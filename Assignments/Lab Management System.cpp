#include<iostream>
#include<cstring>
using namespace std;

int generateHash(const string &password){
    unsigned long hash=5381;

    for(char c: password){
        hash=hash*33+c;
    }

    return hash;
}

class User{
protected:
    string name;
    int ID;
    int hashedPassword;
    string permissions[3];
    string email;
public:
    User(string n, int id, string password, string perm[], string mail):name(n),ID(id),email(mail){
        hashedPassword=generateHash(password);
        for(int i=0; i<3; i++){
            permissions[i]=perm[i];
        }
    }

    bool authenticate(string password){
        if(generateHash(password)==hashedPassword){
            return true;
        }
        return false;
    }

    bool hasPermission(string action){
        for(int i=0; i<3; i++){
            if(permissions[i]==action){
                return true;
            }
        }
        return false;
    }

    virtual void display(){
        cout<<"--------------------"<<endl;
        cout<<"User ID: "<<ID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Permissions: ";
        for (int i=0; i<3; i++) {
            cout<<permissions[i]<<" ";
        }
        cout << endl;
    }

    void accessLab() {
        if(hasPermission("full_lab_access")){
            cout<<name<<" has full lab access."<<endl;
        }else{
            cout<<name<<" does not have full lab access."<<endl;
        }
    }

    string getname(){
        return name;
    }

    int getID(){
        return ID;
    }

};

class Student : public User {
protected:
    int assignments[10]; // 0 = Not Submitted, 1 = Submitted, -1 = Not Assigned

public:    
    Student(string n, int id, string password, string perm[], string mail)
        : User(n,id,password,perm,mail){
        for(int i=0; i<10; i++) {
            assignments[i]=-1;
        }
    }


    void assignAssignment(int assignmentIndex) {
        if(assignmentIndex>=0 && assignmentIndex<10){
            if(assignments[assignmentIndex]==-1){
                assignments[assignmentIndex]=0;
                cout<<"Assignment "<<assignmentIndex<<" assigned to "<<name<<endl;
            }else{
                cout<<"Assignment "<<assignmentIndex<<" is already assigned."<<endl;
            }
        }else{
            cout<<"Invalid assignment index!"<<endl;
        }
    }

    void submitAssignment(int assignmentIndex){
        if (assignmentIndex>=0 && assignmentIndex<10){
            if(assignments[assignmentIndex]==0){
                assignments[assignmentIndex]=1;
                cout<<"Assignment "<<assignmentIndex<<" submitted successfully by "<<name<<endl;
            }else if(assignments[assignmentIndex]==1){
                cout<<"Assignment "<<assignmentIndex<<" is already submitted."<<endl;
            }else{
                cout<<"Assignment "<<assignmentIndex<<" was not assigned!"<<endl;
            }
        }else{
            cout<<"Invalid assignment index!"<<endl;
        }
    }

    void display() override {
        User::display();
        cout<<"Assignments Status: ";
        for(int i=0; i<10; i++){
            cout<<"Assignment "<<i+1<<": ";
            if(assignments[i]==-1)
                cout<<"[Not Assigned]"<<endl;
            else if(assignments[i]==0)
                cout<<"[Pending]"<<endl;
            else
                cout<<"[Submitted]"<<endl;
        }
        cout<<endl;
    }
};

class TA:public Student{
private:
    Student* managedStudents[10];
    int numManagedStudents;
    string projects[2];
    int numProjects;
public:
    TA(string n, int id, string password, string perm[], string mail):Student(n,id,password,perm,mail){
        numManagedStudents=0;
        numProjects=0;
        memset(managedStudents, 0, sizeof(managedStudents)); // Intialize student pointer
    }
    
    void assignStudent(Student* student) {
        if(numManagedStudents<10){
            managedStudents[numManagedStudents++]=student;
            cout<<"Student "<<student->getname()<<" assigned to TA "<<getname()<<endl;
        }else{
            cout<<"Cannot assign more than 10 students"<<endl;
        }
    }

    void startProject(string projectName) {
        if(numProjects<2) {
            projects[numProjects++]=projectName;
            cout<<"TA "<<getname()<<" started working on project: "<<projectName<<endl;
        }else{
            cout<<"TA cannot take more than 2 projects!"<<endl;
        }
    }

    void display() override {
        Student::display();
        cout<<"Managed Students: ";
        for(int i=0; i<numManagedStudents; i++) {
            cout<<managedStudents[i]->getname()<<" ";
        }
        cout<<endl;
    }
};

class Professor: public User{
public:
    Professor(string n, int id, string password, string perm[], string mail)
    :User(n,id,password,perm,mail){}
    
    void assignProjectToTA(TA* ta, string projectName) {
        ta->startProject(projectName);
        cout<<"Professor "<<name<<" assigned project '"<<projectName<<"' to TA "<<ta->getname()<<endl;
    }

    void display() override {
        User::display();
        cout<<"Professor has full control of the lab."<<endl;
    }
};

void authenticateAndPerformAction(User* user, string action) {
    string password;
    cout<<"Enter password for authentication: ";
    cin>>password;

    if(user->authenticate(password)){
        if(user->hasPermission(action)){
            cout<<"Action '"<<action<<"' performed successfully by "<<user->getname()<<endl;
        }else{
            cout<<"Permission denied for action '"<<action<<endl;
        }
    }else{
        cout<<"Authentication failed!"<<endl;
    }
}


int main() {
  
    string studentPerms[] = {"submit assignment", "", ""};
    string taPerms[] = {"manage_students", "view projects", ""};
    string professorPerms[] = {"assign_projects", "full_lab_access", ""};

    
    Student s1("Ali", 101, "stud123", studentPerms, "ali@student.com");
    TA ta1("Ahmed", 201, "ta123", taPerms, "ahmed@ta.com");
    Professor prof1("Dr. Khan", 301, "prof123", professorPerms, "khan@prof.com");

    cout<<endl<<"--- Assigning Assignment to Student ---"<<endl;
    s1.assignAssignment(0);
    s1.assignAssignment(1);

    cout<<endl<<"--- Student Submitting Assignment ---"<<endl;
    s1.submitAssignment(0);
    s1.submitAssignment(2);  // Should show "not assigned"

    cout<<endl<<"--- TA Assigning Student ---"<<endl;
    ta1.assignStudent(&s1);

    cout<<endl<<"--- TA Starting Projects ---"<<endl;
    ta1.startProject("AI Research");
    ta1.startProject("Data Cleaning");
    ta1.startProject("Extra Project"); // Should not be allowed

    cout<<endl<<"--- Professor Assigning Project to TA ---"<<endl;
    prof1.assignProjectToTA(&ta1, "Lab Maintenance");

    cout<<endl<<"--- Display All Users ---"<<endl;
    cout<<endl<<"Student Info:"<<endl;
    s1.display();

    cout<<endl<<"TA Info:"<<endl;
    ta1.display();

    cout<<endl<<"Professor Info:"<<endl;
    prof1.display();

    cout<<endl<<"--- Authentication Tests ---"<<endl;

    authenticateAndPerformAction(&s1, "submit assignment");   // Should work
    authenticateAndPerformAction(&ta1, "manage_students");    // Should work
    authenticateAndPerformAction(&prof1, "full_lab_access");  // Should work

    authenticateAndPerformAction(&s1, "assign_projects");     // Should fail (no such permission)

    return 0;
}
