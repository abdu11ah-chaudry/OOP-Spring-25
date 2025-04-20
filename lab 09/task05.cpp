#include<iostream>
using namespace std;


class Shipment{
protected:
    string trackingNumber;
    double weight;
public:
    Shipment(string tNum, double w):trackingNumber(tNum),weight(w){}

    virtual void estimateDeliveryTime()=0;
    virtual void showDetails()=0;
};

class AirFreight:public Shipment{
private:
    int deliveryTime;
public:
    AirFreight(string tNum, double w, int dTime):Shipment(tNum,w),deliveryTime(dTime){}
    
    void estimateDeliveryTime() override{
        cout<<"Estimated delivery Time: "<<deliveryTime<<" Days."<<endl;
    }

    void showDetails() override{
        cout<<"----------AirFreight-----------"<<endl;
        cout<<"Shipment's tracking Number: "<<trackingNumber<<endl;
        cout<<"Weight: "<<weight<<endl;
    }
};

class GroundShipment:public Shipment{
private:
    int deliveryTime;
public:
    GroundShipment(string tNum, double w, int dTime):Shipment(tNum,w),deliveryTime(dTime){}
        
    void estimateDeliveryTime() override{
        cout<<"Estimated delivery Time: "<<deliveryTime<<" Days."<<endl;
    }
    
    void showDetails() override{
        cout<<"----------Ground Shipment-----------"<<endl;
        cout<<"Shipment's tracking Number: "<<trackingNumber<<endl;
        cout<<"Weight: "<<weight<<endl;
    }
};

int main(){

    AirFreight air("AIR123",120.5,1);
    GroundShipment ground("GRD456",80.5,4);

    Shipment* s1=&air;
    Shipment* s2=&ground;

    s1->showDetails();
    s1->estimateDeliveryTime();
    s2->showDetails();
    s2->estimateDeliveryTime();

    return 0;
}
