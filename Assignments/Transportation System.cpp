#include<iostream>
using namespace std;

class Student{
private:

    const string stdID;
    string cardId;
    string name;
    string stop;
    bool isFeePaid;

public:

    Student(string id,string carId,string n,string stop,bool paid=false):stdID(id),stop(stop),name(n),cardId(carId),isFeePaid(paid){}

    void payFee(){
        isFeePaid=true;
    }

    string getStop() const{
        return stop;
    }

    bool checkIsFeepaid() const{
        return isFeePaid;
    }

    string getStudentID() const{
        return stdID;
    }

    void diplayStudent() const{
        cout<<"------------------"<<endl;
        cout<<"Student Id: "<<stdID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Card Id: "<<cardId<<endl;
        cout<<"Stop: "<<stop<<endl;
    }

};

class Stop{
private:

    string stopName;
    Student **assignedStudent;
    int studentCount;
    int studentCapacity;

public:

    Stop(string n):stopName(n){
        studentCount=0;
        studentCapacity=10;

        assignedStudent=new Student*[studentCapacity];
    }

    
    
    void AssignStudent(Student *s)
    {
        if(studentCount>=studentCapacity){
            cout<<"Maximum Capacity of students have been reached. "<<endl;
        }
        else{
            assignedStudent[studentCount++]=s;
        }    
    }
    
    string getStopName() const{
        return stopName;
    }
    
    ~Stop(){
        delete[] assignedStudent;
    }

};

class Route{
private:

    string routeId;
    Stop **stops;
    int stopCount;
    int StopCapacity;

public:

    Route(string id):routeId(id){
        stopCount=0;
        StopCapacity=10;

        stops=new Stop*[StopCapacity];
    }

    
    void addStop(Stop *s){
        if(stopCount>=StopCapacity){
            cout<<"Maximum number of stops reached."<<endl;
        }
        else{
            stops[stopCount++]=s;
        }    
    }
    
    Stop** getStops(){
        return stops;
    }
    
    int getStopCount(){
        return stopCount;
    }
    
    ~Route(){
        delete[] stops;
    }

};

class Bus{
private:

    string busID;
    Route &route;
    Student **assignedStudent;
    int studentCount;
    int studentCapacity;

public:
        
    Bus(string id,Route &r):busID(id),route(r){
        studentCount=0;
        studentCapacity=10;

        assignedStudent=new Student*[studentCapacity];
    }

    
    
    void assignStudentToBus(Student *s){
        
        for(int i=0; i<route.getStopCount(); i++){
            if(route.getStops()[i]->getStopName()==s->getStop()){
                if(studentCount>=studentCapacity){
                    cout<<"No more space available."<<endl;
                }
                else{
                    assignedStudent[studentCount++]=s;
                    cout << "Student " << s->getStudentID()<<" assigned to Bus "<<busID<< " at Stop "<<s->getStop()<<endl;
                    return;
                }    
            }
        }
        cout<<"No matching student found\n";
    }
    
    void displayStudentAssignedToBus(){
        
        for(int i=0;i<studentCount;i++){
            assignedStudent[i]->diplayStudent();
        }
    }
    
    ~Bus(){
        delete[] assignedStudent;
    }

};

int main(){

    Stop *stp1 = new Stop("Sharah-e-Faisal.");
    Stop *stp2 = new Stop("Guru Mandir.");
    Stop *stp3 = new Stop("Liaquatabad.");

    Route rt1("Route 1");

    rt1.addStop(stp1);
    rt1.addStop(stp2);
    rt1.addStop(stp3);

    Bus bus1("Bus 01",rt1);

    Student *st1=new Student("St1","CID101","Abdullah","Sharah-e-Faisal.");
    Student *st2=new Student("St2","CID102","Shakir","Guru Mandir.");
    Student *st3=new Student("St3","CID103","Nafees","Liaquatabad.");
    Student *st4=new Student("St4","CID104","Rafay","Guru Mandir.");
    Student *st5=new Student("St5","CID105","Shaukat","Sharah-e-Faisal.");

    stp1->AssignStudent(st1);
    stp2->AssignStudent(st2);
    stp3->AssignStudent(st3);
    stp2->AssignStudent(st4);
    stp1->AssignStudent(st5);

    bus1.assignStudentToBus(st1);
    bus1.assignStudentToBus(st2);
    bus1.assignStudentToBus(st3);
    bus1.assignStudentToBus(st4);

    bus1.displayStudentAssignedToBus();

    delete st1;
    delete st2;
    delete st3;
    delete st4;
    delete stp1;
    delete stp2;
    delete stp3;


    return 0;
}
