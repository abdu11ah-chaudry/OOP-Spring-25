#include<iostream>
using namespace std;

class Student{
private:
    int ID;
    string name;
    int *examscore;
    int size;
public:
    Student():ID(0),name("Unkown"),examscore(nullptr){}
    
    Student(int id, string n, int scores[], int s){
        ID=id;
        name=n;
        size=s;
        examscore= new int[size];
        for(int i=0; i<size; i++){
            examscore[i]=scores[i];
        }
    }

    Student(const Student &obj){
        this->ID=obj.ID;
        this->name=obj.name;
        this->size=obj.size;
        examscore=new int[size];
        for(int i=0; i<size; i++){
            this->examscore[i]=obj.examscore[i];
        }
    }
    void displayDetails(){
        cout<<"-------------------"<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"Student ID: "<<ID<<endl;
        cout<<"Student's Exam Score: "<<endl;
        for(int i=0; i<size; i++){
            cout<<i+1<<": "<<examscore[i]<<endl;
        }
    }
    ~Student(){
        delete [] examscore;
    }

};
int main(){
    int scores[3]={99,98,97};
    Student s1(1,"Abdullah",scores,3);

    s1.displayDetails();

    Student s2(s1);
    s2.displayDetails();

    return 0;

}
