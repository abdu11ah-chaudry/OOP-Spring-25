#include<iostream>
using namespace std;

class Device{
protected:
    int DeviceID;
    string name;
    bool status;
    string location;
public:
    Device(int id, string n, bool st, string loc):DeviceID(id),name(n),status(st),location(loc){}
    
    virtual void turnon(){
        cout<<"Device turned on."<<endl;
        status=true;
    }
    
    virtual void turnoff(){
        cout<<"Device turned off."<<endl;
        status=false;
    }

    virtual bool getStatus(){
        return status;
    }

    virtual void displayInfo(){
        cout<<"----------------"<<endl;
        cout<<"Device ID: "<<DeviceID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Status: "<<(status? "On":"Off")<<endl;
        cout<<"Location: "<<location<<endl;
    }

};

class Light:public Device{
private:
    int brightnessLevel;
    string colorMode;
public:
    Light(int id,string n,bool st,string loc, int bLevel, string colormd):Device(id,n,st,loc),brightnessLevel(bLevel),colorMode(colormd){}

    void displayInfo() override{
        Device::displayInfo();
        cout<<"Brightness Level: "<<brightnessLevel<<endl;
        cout<<"Color Mode: "<<colorMode<<endl;
    }
};

class Thermostat:public Device{
private:
    int currentTemperature;
    int targetTemperature;
    string mode;
public:
    Thermostat(int id,string n,bool st,string loc, int t1, int t2, string m):Device(id,n,st,loc),currentTemperature(t1),targetTemperature(t2),mode(m){}

    bool getStatus() override{
        return currentTemperature;
    } 
};

class SecurityCamera:public Device{
private:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;
public:
    SecurityCamera(int id,string n,bool st,string loc, int res, bool rst, bool nightvision):Device(id,n,st,loc),resolution(res),
    recordingStatus(rst),nightVisionEnabled(nightvision){}
    
    void turnon() override{
        Device::turnon();
        cout<<"Automatic recording started."<<endl;
        recordingStatus=true;
    }
};

class SmartPlug:public Device{
private:
    int powerConsumption;
    int timerSetting;
public:
    SmartPlug(int id,string n,bool st,string loc, int pconsumption, int timer):Device(id,n,st,loc),powerConsumption(pconsumption),
    timerSetting(timer){}
    
    void turnoff() override{
        Device::turnoff();
        cout<<"Power Usage Logged: "<<powerConsumption<<endl;
    }
    
};
int main(){

    Light light(01,"Bedroom Light.",true,"Bedroom",75,"Light");
    Thermostat thermostat(02,"Home Thermostat",false, "Hallway",34,24,"Cooling");
    SecurityCamera camera(03,"Front Door Camera",true,"Entrance",1080,false,true);
    SmartPlug plug(04,"Smart Plug",true,"Kitchen",500, 2);

    light.turnon();
    light.displayInfo();
    
    thermostat.getStatus();
    
    camera.turnon();
    
    plug.turnoff();
    
    return 0;

    return 0;
}
