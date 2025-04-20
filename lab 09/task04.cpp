#include<iostream>
using namespace std;

class WeatherSensor{
protected:
public:
    virtual void readData(double x)=0;    
    virtual void displayReport()=0;    
};

class Thermometer:public WeatherSensor{
private:
    int temperature;    
public:
    void readData(double temp) override{
        temperature=temp;
    }
    void displayReport() override{
        cout<<"Thermometer Reading: "<<temperature<<" `C"<<endl;
    }    
};

class Barometer:public WeatherSensor{
private:
    int pressure;
public:
    void readData(double pres) override{
        pressure=pres;
    }
    void displayReport() override{
        cout<<"Barometer Reading: "<<pressure<<" Pa"<<endl;
    }    
};

int main(){

    Thermometer thermometer;
    Barometer barometer;

    WeatherSensor* s1=&thermometer;
    WeatherSensor* s2=&barometer;

    s1->readData(20.2);
    s1->displayReport();

    s2->readData(1000.13);
    s2->displayReport();

    return 0;
}
