#include<iostream>
using namespace std;

class Doctor{
private:
    string name;
    string specialiazation;
    string experience;
public:
    Doctor() {}
    
    Doctor(string n, string special, string exp):name(n),specialiazation(special),experience(exp){}

    void displayDoctor(){
        cout<<"Doctor's name: "<<name<<endl;
        cout<<"Specialization: "<<specialiazation<<endl;
        cout<<"Experience: "<<experience<<endl;
    }
};

class Hospital{
private:
    string HospitalName;
    Doctor *doctors;
    int noofdocs;
public:
    Hospital(string name):HospitalName(name),noofdocs(0){
        doctors=new Doctor[10];
    }
    void addDoctor(const Doctor &d){
        if(noofdocs<10){
            doctors[noofdocs++]=d;
        }
        else{
            cout<<"Maximum Doctors capacity reached."<<endl;
        }
    }
    void displayHospital(){
        cout<<"----------------------"<<endl;
        cout<<"Hospital Name: "<<HospitalName<<endl;
        cout<<"Doctors Associated: "<<endl;
        for(int i=0; i<noofdocs; i++){
            doctors[i].displayDoctor();
        }
    }
    ~Hospital(){
        delete [] doctors;
    }
};

int main(){

    Doctor d1("Abdullah","Nuero-Surgeon","10 years");
    Doctor d2("Rehman","Dermatologist","12 years");

    Hospital h1("New Hospital");

    h1.addDoctor(d1);
    h1.addDoctor(d2);

    h1.displayHospital();

    return 0;
}
