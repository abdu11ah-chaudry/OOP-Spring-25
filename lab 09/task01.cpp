#include<iostream>
using namespace std;

class Patient{
protected:
    int ID;
    string name;
public:
    Patient(int id, string n):ID(id),name(n){}
    
    virtual void displayTreatment()=0;
    virtual void calculateCost()=0;
};

class InPatient:public Patient{
private:
    double dailyRate;
    int numOFdaysAddmitted;    
public:
    InPatient(int id, string n, double dRate, int numOfDays):Patient(id,n),dailyRate(dRate),numOFdaysAddmitted(numOfDays){}
    
    void displayTreatment() override{
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"This is the treatment for Inpatients(those who stays overnight): "<<endl;
        cout<<"InPatient Treatment for "<<name<<" (ID: "<<ID<< ")"<<endl;
        cout<<"Admitted for "<<numOFdaysAddmitted<<" days at $"<<dailyRate<<" per day."<<endl;
    }

    void calculateCost() override{
        cout<<"Total Cost for Inpatient: "<<ID<<" is: "<<dailyRate*numOFdaysAddmitted<<endl;
    }
};

class OutPatient:public Patient{
private:
    double feePerVisit;
    int numOfVisits;    
public:
    OutPatient(int id, string n, double fee, int numOfDays):Patient(id,n),feePerVisit(fee),numOfVisits(numOfDays){}
        
    void displayTreatment() override{
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"This is the treatment for Outpatients(those who stays for quick treatment): "<<endl;
        cout<<"OutPatient Treatment for "<<name<<" (ID: "<<ID<< ")"<<endl;
        cout<<"Visited for "<<numOfVisits<<" times at $"<<feePerVisit<<" per visit."<<endl;
    }
    
    void calculateCost() override{
        cout<<"Total Cost for Outpatient: "<<ID<<" is: "<<feePerVisit*numOfVisits<<endl;
    }
};
    

int main() {

    InPatient ip(101,"Abdullah",250.0,4);
    OutPatient op(202,"Bilawal", 75.0,3);
    
    Patient* p1=&ip;
    Patient* p2=&op;

    p1->displayTreatment();
    p1->calculateCost();

    p2->displayTreatment();
    p2->calculateCost();

    return 0;
}

