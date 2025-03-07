#include<iostream>
using namespace std;

class AlaramSystem{
private:
    string securityLevel;
public:
    AlaramSystem(string level):securityLevel(level) {}
    
    void setSecurityLevel(string level){
        securityLevel=level;
    }

    string getSecurityLevel(){
        return securityLevel;
    }    
};

class SmartHome{
private:
    string homeAddress;
    AlaramSystem a;
public:
    SmartHome(string address, string level):homeAddress(address),a(level){}
    
    void displayHome(){
        cout<<"----------------"<<endl;
        cout<<"Home Adress: "<<homeAddress<<endl;
        cout<<"Home Alaram System Security Level: "<<a.getSecurityLevel()<<endl;
    }
};

int main(){

    SmartHome home1("101 Street Birminghim","Medium");
    home1.displayHome();

    return 0;
}
