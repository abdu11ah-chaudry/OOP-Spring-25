#include<iostream>
using namespace std;

class Passenger{
protected:
    string cardID;
    string name;
    string stop;

public:
    Passenger(){}
    
    Passenger(string id, string n, string stp):cardID(id),name(n),stop(stp){}

    string getStop() const{
        return stop;
    }

    virtual void display() const{
        cout<<"Card ID: "<<cardID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Stop: "<<stop<<endl;
    }

};

class Student: public Passenger{
private:
    const string stdID;
    bool isSemesterFeePaid;
public:
    Student(string id,string carId,string n,string stp,bool paid=false):stdID(id),isSemesterFeePaid(paid),Passenger(carId,n,stp){}
    
    string getStudentID() const{
        return stdID;
    }
    
    void paySemesterFee() {
        isSemesterFeePaid = true;
        cout << name << " has paid the semester fee." << endl;
    }

    bool checkIsFeePaid(){
        return isSemesterFeePaid;
    }

    void display() const override{
        cout<<"------------------"<<endl;
        cout<<"Student      "<<endl;
        cout<<"Student Id: "<<stdID<<endl;
        Passenger::display();
        cout<<"Fee: "<<(isSemesterFeePaid?"Paid":"Unpaid")<<endl;
    }    
};

class Teacher: public Passenger{
private:
    string department;
    bool isMonthlyFeePaid;
public:
    Teacher(string dept,string carId,string n,string stp,bool paid=false):department(dept),isMonthlyFeePaid(paid),Passenger(carId,n,stp){}
    
    string getTeacherDepartment() const{
        return department;
    }

    void payMonthlyFee() {
        isMonthlyFeePaid = true;
        cout << name << " has paid the semester fee." << endl;
    }

    void display() const override{
        cout<<"--------------------"<<endl;
        cout<<"Teacher      "<<endl;
        cout<<"Teacher's Department Name: "<<department<<endl;
        Passenger::display();
        cout<<"Fee: "<<(isMonthlyFeePaid?"Paid":"Unpaid")<<endl;
    }

    bool checkIsFeePaid(){
        return isMonthlyFeePaid;
    }
};

class Staff: public Passenger{
private:
    string designation;
    bool isMonthlyFeePaid;
public:
    Staff(string desig,string carId,string n,string stp,bool paid=false):designation(desig),isMonthlyFeePaid(paid),Passenger(carId,n,stp){}

    string getDesignation() const{
        return designation;
    }

    void payMonthlyFee() {
        isMonthlyFeePaid = true;
        cout << name << " has paid the semester fee." << endl;
    }
    
    bool checkIsFeePaid(){
        return isMonthlyFeePaid;
    }

    void display() const override{
        cout<<"--------------------"<<endl;
        cout<<"Staff Member      "<<endl;
        cout<<"Designation : "<<designation<<endl;
        Passenger::display();
        cout<<"Fee: "<<(isMonthlyFeePaid?"Paid":"Unpaid")<<endl;
    }
};

class Stop{
private:
    string stopName;
    Student **assignedStudent;
    Teacher **assignedTeacher;
    Staff **assignedStaff;
    int studentCount, teacherCount, staffCount;
    int studentCapacity, teacherCapacity, staffCapacity;

public:
    
    Stop(string n):stopName(n){
        studentCount=0, teacherCount=0, staffCount=0;
        studentCapacity=5;
        teacherCapacity=5;
        staffCapacity=5;
    
        assignedTeacher=new Teacher*[teacherCapacity];
        assignedStaff=new Staff*[staffCapacity];
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

    void assignTeacher(Teacher *t)
    {
        if(teacherCount>=teacherCapacity){
            cout<<"Maximum Capacity of teachers have been reached. "<<endl;
        }
        else{
            assignedTeacher[teacherCount++]=t;
        }    
    }

    void AssignStaff(Staff *st)
    {
        if(staffCount>=staffCapacity){
            cout<<"Maximum Capacity of staff have been reached. "<<endl;
        }
        else{
            assignedStaff[staffCount++]=st;
        }    
    }
        
    string getStopName() const{
        return stopName;
    }
        
    ~Stop(){
        delete[] assignedStudent;
        delete[] assignedTeacher;
        delete[] assignedStaff;
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
        StopCapacity=5;
    
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
    
    bool operator ==(const Route &r){
        if(stopCount!=r.stopCount){ return false; }

        for(int i=0; i<stopCount; i++){
            if(stops[i]->getStopName()!=r.stops[i]->getStopName()){
                return false;
            }
        }

        return true;
    }

};

class Bus{
private:
    
    string busID;
    Route &route;
    Student **assignedStudent;
    Teacher **assignedTeacher;
    Staff **assignedStaff;
    int studentCount, teacherCount, staffCount;
    int studentCapacity, teacherCapacity, staffCapacity;
    
public:
            
    Bus(string id,Route &r):busID(id),route(r){
        studentCount=0, teacherCount=0, staffCount=0;
        studentCapacity=15;
        teacherCapacity=15;
        staffCapacity=15;
    
        assignedTeacher=new Teacher*[teacherCapacity];
        assignedStaff=new Staff*[staffCapacity];
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

    void assignTeacherToBus(Teacher *t){        
            
        for(int i=0; i<route.getStopCount(); i++){
            if(route.getStops()[i]->getStopName()==t->getStop()){
                if(teacherCount>=teacherCapacity){
                    cout<<"No more space available."<<endl;
                }
                else{
                    assignedTeacher[teacherCount++]=t;
                    cout << "Teacher " << t->getTeacherDepartment()<<" assigned to Bus "<<busID<< " at Stop "<<t->getStop()<<endl;
                    return;
                }    
            }
        }
        cout<<"No matching Teacher found\n";
    }

    void assignStaffToBus(Staff *st){        
            
        for(int i=0; i<route.getStopCount(); i++){
            if(route.getStops()[i]->getStopName()==st->getStop()){
                if(studentCount>=studentCapacity){
                    cout<<"No more space available."<<endl;
                }
                else{
                    assignedStaff[staffCount++]=st;
                    cout << "Staff " << st->getDesignation()<<" assigned to Bus "<<busID<< " at Stop "<<st->getStop()<<endl;
                    return;
                }    
            }
        }
        cout<<"No matching staff Member found\n";
    }
    
    void displayPassengersAssignedToBus(){
        cout<<"------------------------------"<<endl;
        cout<<"Assigned Students To Bus: "<<endl;    
        for(int i=0;i<studentCount;i++){
            assignedStudent[i]->display();
            }
            cout<<"------------------------------"<<endl;
            cout<<"Assigned Teachers To Bus: "<<endl;    
            for(int i=0;i<teacherCount;i++){
                assignedTeacher[i]->display();
            }
            cout<<"------------------------------"<<endl;
            cout<<"Assigned Staff Members To Bus: "<<endl;    
            for(int i=0;i<staffCount;i++){
                assignedStaff[i]->display();
            }
        }
        
    ~Bus(){
        delete[] assignedStudent;
        delete[] assignedTeacher;
        delete[] assignedStaff;
    }

};

    
int main(){
    
    Stop stop1("Bahria"), stop2("Saddar"), stop3("Rizvia");
    Stop stop4("Bahria"), stop5("Soldier Bazar"), stop6("Rizvia"); 

    
    Route route1("Route 1");
    route1.addStop(&stop1);
    route1.addStop(&stop2);
    route1.addStop(&stop3);

    
    Route route2("Route 2");
    route2.addStop(&stop4); 
    route2.addStop(&stop5); 
    route2.addStop(&stop6); 

    
    Route route3("Route 3");
    route3.addStop(&stop2); 
    route3.addStop(&stop5); 

    
    cout << "Comparing Route 1 and Route 2: ";
    if(route1==route2)
        cout<<"Routes are same."<<endl;
    else
        cout<<"Routes are different."<<endl;
    
    cout<<"Comparing Route 1 and Route 3: ";
    if(route1==route3)
        cout<<"Routes are same."<<endl;
    else
        cout<<"Routes are different."<<endl;

    
    Bus bus1("Bus-101", route1);

    
    Student s1("S1","C1","Asad","Bahria",true);
    Student s2("S2","C2","Bilawal","Saddar",false);

    Teacher t1("Math","C3","Dr. Saleem","Saddar",true);
    Teacher t2("Physics", "C4", "Dr. Bakhtawar","Rizvia",false);

    Staff st1("Driver","C5","Jameel","Bahria",true);
    Staff st2("Clerk","C6","Dawood","Rizvia",false);

    stop1.AssignStudent(&s1);
    stop2.AssignStudent(&s2);

    stop2.assignTeacher(&t1);
    stop3.assignTeacher(&t2);

    stop1.AssignStaff(&st1);
    stop3.AssignStaff(&st2);

    
    bus1.assignStudentToBus(&s1);
    bus1.assignStudentToBus(&s2);

    bus1.assignTeacherToBus(&t1);
    bus1.assignTeacherToBus(&t2);

    bus1.assignStaffToBus(&st1);
    bus1.assignStaffToBus(&st2);

    
    bus1.displayPassengersAssignedToBus();

    return 0;
}
