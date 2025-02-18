#include<iostream>
using namespace std;

class Car{
private:
    string brand;
    string model;
    float rentalPrice;
    bool availability;

public:
    Car(){
        brand="Unknown";
        model="Generic";
        rentalPrice=0.0;
        availability=true;
    }

    void updateCarDetails(string br, string mod, float rental, bool available){
        brand=br;
        model=mod;
        rentalPrice=rental;
        availability=available;
    }

    bool isAvailable(){
        return availability;
    }

    void rentalRequest(){
        if(availability==true){
            cout<<"Car rented successfully."<<endl;
            availability=false;
        }
        else{
            cout<<"Car is already rented, You can't rent it."<<endl;
        }
    }

    void displayDetails(){
        cout<<"---------------"<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rental Price: "<<rentalPrice<<endl;
        cout<<"Availability: "<<(availability?"yes":"No")<<endl;    
    }
};
int main(){

    Car c1;
    c1.displayDetails();
    c1.updateCarDetails("Honda","Insight",20000.45,true);
    c1.displayDetails();
    c1.rentalRequest();

    
    return 0;
}
