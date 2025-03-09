#include<iostream>
using namespace std;

class Employee{
protected:
    string name;
    float salary;
public:
    Employee(string n, float sal):name(n),salary(sal){}

    void display(){
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee Salary: "<<salary<<endl;
    }
};

class Manager:private Employee{
private:
    float bonus;
public:
    Manager(string n, float sal, float b):Employee(n,sal),bonus(b){}
    
    void display(){
        Employee::display();
        cout<<"Bonus: "<<bonus<<endl;
    }
};

int main(){

    Manager m("Abdullah",100000,1000);
    m.display();

    return 0;
}
