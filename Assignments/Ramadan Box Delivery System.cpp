#include <iostream>
using namespace std;

class Vehicle {
protected:
    string vehicleID; 
    static int activeDeliveries;
    int speed;        
    int capacity;     
    int energyUsage;
public:
    
    Vehicle(string id, int spd, int cap, int energy):vehicleID(id),speed(spd),capacity(cap),energyUsage(energy){
        activeDeliveries++;
    }


    virtual void calculateOptimalRoute() {
        cout<<"Calculating optimal route for vehicle: "<<vehicleID<<endl;
    }

    virtual void estimateDeliveryTime() {
        cout<<"Estimating delivery time for vehicle: "<<vehicleID<<endl;
    }

    virtual void move() {
        cout<<"Vehicle "<<vehicleID<<" is moving.."<<endl;
    }

    static int getActiveDeliveries() {
        return activeDeliveries;
    }

    virtual ~Vehicle(){
        activeDeliveries--;
    }

    friend string resolveConflict(Vehicle& v1, Vehicle& v2, int packageWeight);

    bool operator==(const Vehicle& other) {
        return (speed == other.speed && capacity == other.capacity && energyUsage == other.energyUsage);
    }
};


int Vehicle::activeDeliveries=0;

string resolveConflict(Vehicle& v1, Vehicle& v2, int packageWeight) {
    cout<<"Resolving conflict between "<<v1.vehicleID<<" and "<<v2.vehicleID<<endl;

    if (v1.capacity >= packageWeight && v2.capacity < packageWeight) return v1.vehicleID;
    if (v2.capacity >= packageWeight && v1.capacity < packageWeight) return v2.vehicleID;

    if (v1.speed > v2.speed) return v1.vehicleID;
    if (v2.speed > v1.speed) return v2.vehicleID;

    if (v1.energyUsage < v2.energyUsage) return v1.vehicleID;
    if (v2.energyUsage < v1.energyUsage) return v2.vehicleID;

    return "Both vehicles are equally efficient. Assigning randomly.";
}

class RamzanDrone: public Vehicle{
private:
    int maxWeightCapacity;
    bool highSpeedMode;

public:
    RamzanDrone(string id, int wCapacity):Vehicle(id,120,10,15),maxWeightCapacity(wCapacity),highSpeedMode(false){}

    void move() override{
        cout<<"RamzanDrone: "<<vehicleID<<" is flying towards destination."<<endl;
    }

    void calculateOptimalRoute() override{
        cout<<"RamzanDrone :"<<vehicleID<<" calculating fastest Aerial route."<<endl;
    }

    void estimateDeliveryTime() override{
        cout<<"RamzanDrone :"<<vehicleID<<" estimating delivery timing based on wind conditions."<<endl;
    }

    void command(string action, int packageID){
        cout<<"RamzanDrone: "<<vehicleID<<" Recieved Command: "<<action<<" PackageID: "<<packageID<<endl;
    }

    void command(string action, int packageID, string urgency){
        if(urgency=="IftarMeal"){
            highSpeedMode=true;
            cout<<"RamzanDrone: "<<vehicleID<<" activating HIGH-SPEED-MODE for Iftar Delivery!"<<endl;
        }
        else{
            cout<<"RamzanDrone: "<<vehicleID<<" delivering the package :"<<packageID<<" with normal priority!"<<endl;
        }
    }
};

class RamzanTimeShip: public Vehicle{
private:
    int historicalValidationCode;
    bool EnabledTimeSynced;
public:
    
    RamzanTimeShip(string id, int hvCode):Vehicle(id,90,30,15),historicalValidationCode(hvCode),EnabledTimeSynced(false){}

    void move() override{
        if(EnabledTimeSynced){
            cout<<"RamzanTimeShip: "<<vehicleID<<" is moving by Time-Travel."<<endl;
        }
        else{
            cout<<"Can not Move, Time Synced Required."<<endl;
            return;
        }
    }

    void calculateOptimalRoute() override{
        cout<<"RamzanTimeShip :"<<vehicleID<<" calculating fastest Time-Travel."<<endl;
    }

    void estimateDeliveryTime() override{
        cout<<"RamzanTimeShip :"<<vehicleID<<" estimating delivery timing based on Time Travel."<<endl;
    }

    void command(string action, int packageID){
        cout<<"RamzanTimeShip: "<<vehicleID<<" Recieved Command: "<<action<<" PackageID: "<<packageID<<endl;
    }

    void command(string command, int packageID, string urgency){
        if(urgency=="Urgent"){

            if (historicalValidationCode%2==0) {  //Dummy Condition for validation success
                EnabledTimeSynced=true;
                cout<<"Historical validation PASSED. Time synchronization enabled!"<<endl;
                cout<<"Proceeding with urgent time-travel delivery..."<<endl;
            } 
            else{
                cout<<"Historical validation FAILED. Delivery CANNOT proceed."<<endl;
            }
        } 
        else{
            cout<<"RamzanTimeShip:"<<vehicleID<<" processing delivery with normal priority."<<endl;
        }
    }
};

class RamzanHyperPod: public Vehicle{
private:
    int maxLoadCapacity;
    bool bulkMode;
public:
    
    RamzanHyperPod(string id, int maxload):Vehicle(id,80,100,20),bulkMode(false), maxLoadCapacity(maxload){}

    void move() override{
        cout<<"RamzanHyperPod: "<<vehicleID<<" is moving through underground tunnels."<<endl;
    }

    void calculateOptimalRoute() override{
        cout<<"RamzanHyperPod :"<<vehicleID<<" calculating the fastest underground delivery route."<<endl;
    }

    void estimateDeliveryTime() override{
        cout<<"RamzanHyperPod :"<<vehicleID<<" estimating delivery timing based on tunnels."<<endl;
    }

    void command(string action, int packageID){
        cout<<"RamzanHyperPod: "<<vehicleID<<" Recieved Command: "<<action<<" PackageID: "<<packageID<<endl;
    }

    void command(string action, int packageID, int weight){
        if(weight>maxLoadCapacity){
            cout<<"Exceeded Max load capacity, can not process delivery"<<endl;
        }
        else{
            bulkMode=true;
            cout<<"RamzanHyperPod "<<vehicleID<<" activating bulk mode for large-scale Delivery."<<endl;
        }
    }

};


class OperatorControlPanel {
public:
    void issueCommand(Vehicle* vehicle, string action, int packageID) {
        cout<<"Operator Pannel issuing command: "<<action<<" for Package "<<packageID<<endl;
        vehicle->calculateOptimalRoute();
        vehicle->estimateDeliveryTime();
        vehicle->move();
    }
};


int main() {
    RamzanDrone drone("D101", 5);
    RamzanTimeShip timeShip("T202", 42);
    RamzanHyperPod hyperPod("H303", 150);

    OperatorControlPanel control;
    control.issueCommand(&drone, "Deliver", 123);
    control.issueCommand(&timeShip, "Deliver", 456);
    control.issueCommand(&hyperPod, "Deliver", 789);

    return 0;
}

