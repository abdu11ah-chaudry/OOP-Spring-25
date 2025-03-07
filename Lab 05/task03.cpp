#include<iostream>
using namespace std;


class Employee{
private:
    string name;
    string designation;
public:
    Employee() {}
    
    Employee(string n, string desig):name(n),designation(desig){}

    void displayEmployee(){
        cout<<"Employee name: "<<name<<endl;
        cout<<"Employee Designation: "<<designation<<endl;
    }
};

class Project{
private:
    string title;
    string deadline;
    Employee *employees;
    int employeecount=0;
public:    
    Project(){}

    Project(string t, string d){
        title=t;
        deadline=d;
        employees= new Employee[10];
    }

    void addEmployee(const Employee &e){
        if(employeecount<10){
            employees[employeecount++]=e;
        }
        else{
            cout<<"Maximum Numbers of Employees are already signed up"<<endl;
        }
    }

    void displayProject(){
        cout<<"---------------------"<<endl;
        cout<<"Project Title: "<<title<<endl;
        cout<<"Project Deadline: "<<deadline<<endl;
        cout<<"Employees Enrolled: "<<endl;
        for(int i=0; i<employeecount; i++){
            employees[i].displayEmployee();
        }
    }

    ~Project(){
        delete[] employees;
    }
};

int main(){

    Employee e1("Abdullah","Senior Developer");
    Employee e2("Haider","Junior Developer");
    Employee e3("Shayan","Intern");
    Employee e4("Kashif","Senior Marketer");

    Project p1("Health Management System","End of May");
    Project p2("Brick Breaker Game","End of Novemeber");

    p1.addEmployee(e1);
    p1.addEmployee(e2);
    p1.addEmployee(e3);

    p2.addEmployee(e1);
    p2.addEmployee(e2);
    p2.addEmployee(e3);
    p2.addEmployee(e4);

    p1.displayProject();
    p2.displayProject();

    return 0;
}

