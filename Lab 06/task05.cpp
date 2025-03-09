#include<iostream>
using namespace std;

class Device{
protected:
    int deviceID;
    bool status;
public:
    Device(){}

    Device(int id, bool st):deviceID(id),status(st){}

    virtual void displayDetails(){
        cout<<"---------------------"<<endl;
        cout<<"Device ID: "<<deviceID<<endl;
        cout<<"Status: "<<(status ? "Yes":"No")<<endl;
    }
};

class SmartPhone:virtual public Device{
protected:
    float screenSize;
public:
    SmartPhone(){}    

    SmartPhone(int id, bool st, float sSize):Device(id,st),screenSize(sSize){}

    void displayDetails() override{
        Device::displayDetails();
        cout<<"Screen Size: "<<screenSize<<endl;
    }
};

class SmartWatch:virtual public Device{
protected:
    bool heartRateMonitor;
public:
    SmartWatch(){}
    
    SmartWatch(int id, bool st, bool hrMonitor):Device(id,st),heartRateMonitor(hrMonitor){}

    void displayDetails() override{
        Device::displayDetails();
        cout<<"Heart Rate Monitor: "<<(heartRateMonitor? "yes" :"No")<<endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;
public:
    SmartWearable(){}

    SmartWearable(int id, bool st, float sSize, bool hrMonitor, int stepcount):
    Device(id,st),SmartPhone(id,st,sSize),SmartWatch(id,st,hrMonitor),stepCounter(stepcount){}

    void displayDetails() override{
        Device::displayDetails();
        cout<<"Screen Size: "<<screenSize<<" inches"<<endl;
        cout<< "Heart Rate Monitor: "<<(heartRateMonitor ? "Yes" : "No")<<endl;
        cout<<"Step Counter: "<<stepCounter<<" steps"<<endl;
    }
};    
int main(){

    SmartWearable s(1,true,3.5,true,1000);
    s.displayDetails();
    
    return 0;
}
