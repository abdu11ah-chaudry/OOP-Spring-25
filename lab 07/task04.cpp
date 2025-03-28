#include<iostream>
using namespace std;

class Person{
protected:
    string name;
    int age;
    string contactNumber;
    string address;
public:
    Person(string n, int a, string cNum, string add):name(n),age(a),contactNumber(cNum),address(add){}
    
    virtual void updateInfo(string n, int a, string cNum, string add){
        name=n;
        age=a;
        contactNumber=cNum;
        address=add;
    }

    virtual void displayInfo(){
        cout<<"--------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact Number: "<<contactNumber<<endl;
        cout<<"Address: "<<address<<endl;
    }
};

class Patient:public Person{
protected:
    int patientID;
    string medicalHistory;
    string DoctorAssigned;
public:
    Patient(string n, int a, string cNum, string add, int id, string medHistory, string docassigned):Person(n,a,cNum,add),
    medicalHistory(medHistory),patientID(id),DoctorAssigned(docassigned){}

    void displayInfo() override{
        Person::displayInfo();
        cout<<"Patient ID: "<<patientID<<endl;
        cout<<"Medical History: "<<medicalHistory<<endl;
        cout<<"Doctor Assigned: "<<DoctorAssigned<<endl;
    }
};

class Doctor:public Person{
private:
    string specialization; 
    double consultationFee;
    string patientList[2];
public:
    Doctor(string n, int a, string cNum, string add, string special, double fee, string list[]):Person(n,a,cNum,add),
    specialization(special),consultationFee(fee){
        for(int i=0; i<2; i++){
            patientList[i]=list[i];
        }
    }

    void displayInfo() override{
        Person::displayInfo();
        cout<<"Doctor's Specialization: "<<specialization<<endl;
        cout<<"Consulation Fee: "<<consultationFee<<endl;
        cout<<"Patients List: "<<endl;
        for(int i=0; i<2; i++){
            cout<<patientList[i]<<endl;
        }
    }
};

class Nurse:public Person{
private:
    string assignedWard;
    string shiftTimings;
public:
    Nurse(string n, int a, string cNum, string add, string ward, string timing):Person(n,a,cNum,add),assignedWard(ward),
    shiftTimings(timing){}
    
    void displayInfo() override{
        Person::displayInfo();
        cout<<"Nurse's Assigned Ward: "<<assignedWard<<endl;
        cout<<"Shift Timings: "<<shiftTimings<<endl;
    }
};

class Administrator:public Person{
private:
    string department;
    double salary;
public:
    Administrator(string n, int a, string cNum, string add, string dept, double sal):Person(n,a,cNum,add),department(dept),
    salary(sal){}

    void updateInfo(string n, int a, string cNum, string add, string dept, double sal){
        Person::updateInfo(n,a,cNum,add);
        department=dept;
        salary=sal;
    }
};



int main() {
    
    Patient patient1("Ahmed Ali", 40, "0321-1234567", "Karachi", 101, "Diabetes", "Dr. Ayesha Khan");
    
    
    string patientList[] = {"Ahmed Ali", "Hina Fatima"};
    Doctor doctor1("Dr. Ayesha Khan", 38, "0300-9876543", "Lahore", "Cardiologist", 3000.0, patientList);


    Nurse nurse1("Sadia Malik", 30, "0333-5557777", "Islamabad", "ICU", "Night Shift");

    
    Administrator admin1("Bilal Hussain", 45, "0345-1112222", "Rawalpindi", "HR", 85000.0);

    
    cout<<endl<<"---- Patient Information -----"<<endl;
    patient1.displayInfo();

    cout<<endl<<"----- Doctor Information ----"<<endl;
    doctor1.displayInfo();

    cout<<endl<<"---- Nurse Information ----"<<endl;
    nurse1.displayInfo();

    cout<<endl<<"---- Administrator Information ----"<<endl;
    admin1.displayInfo();

    
    cout<<endl<<"Updating Contact for Patient"<<endl;
    patient1.updateInfo("Ahmed Ali", 40, "0315-8889999", "Karachi");

    cout<<endl<<"Updating Salary for Administrator"<<endl;
    admin1.updateInfo("Bilal Hussain", 45, "0345-1112222", "Rawalpindi", "HR", 90000.0);

    
    cout<<endl<<"---- Updated Administrator Information ----"<<endl;
    admin1.displayInfo();

    return 0;
}

