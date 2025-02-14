#include<iostream>
using namespace std;

class Car{

private:
    string brand;
    string model;
    float fuelCapacity;
    float currentFuelLevel;

public:
    
Car(){
    fuelCapacity=40.0;
    currentFuelLevel=0;
}

Car(string br,string mod,float curr){
    brand=br;
    model=mod;
    fuelCapacity=40.0;
    currentFuelLevel=curr;
}

void fuelUsed(float x){
    if(currentFuelLevel-x >=0){
        currentFuelLevel-=x;
    }
    else
    {
        cout<<"Invalid use of Fuel"<<endl;
    }
}

void Refuel(float x)
{
    if(x+currentFuelLevel <= fuelCapacity){
        currentFuelLevel+=x;
    }
    else{
        cout<<"Invalid fuel capacity"<<endl;
    }
}

void fuelStatus()
{
    if(currentFuelLevel==fuelCapacity){
        cout<<"Fuel tank is full"<<endl;
    }
    else{
        cout<<"The current fuel level is "+to_string(currentFuelLevel)+" litres"<<endl;
    }
}


};
int main(){

    Car c1("Honda","Insight",25);
    c1.fuelUsed(10);
    c1.Refuel(15);
    c1.fuelStatus();

    return 0;
}
