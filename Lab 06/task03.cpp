#include<iostream>
using namespace std;

class Person{
protected:
    string name;
    int age;
public:
    Person() {}
    Person(string n, int a):name(n),age(a){}        

    void displayDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Teacher:protected Person{
protected:
    string subject;
public:
    Teacher(string n, int a, string sub):Person(n,a),subject(sub){}
    
    void displayDetails(){
        Person::displayDetails();
        cout<<"Subject: "<<subject<<endl;
    }
};

class Researcher:protected Teacher{
protected:
    string ResearchArea;
public:
    Researcher(string n, int a, string sub, string Rarea):Teacher(n,a,sub),ResearchArea(Rarea){}
    
    void displayDetails(){
        Teacher::displayDetails();
        cout<<"Research Area: "<<ResearchArea<<endl;
    }
};

class Professor:private Researcher{
private:
    int publications;
public:
    Professor(string n, int a, string sub, string Rarea, int publicat):Researcher(n,a,sub,Rarea),publications(publicat){}
    
    void displayDetails(){
        Researcher::displayDetails();
        cout<<"Publications: "<<publications<<endl;
    }
};
int main(){

    Professor p("Abdullah",29,"Computer Science","Quantum Computing",28);
    p.displayDetails();

}
