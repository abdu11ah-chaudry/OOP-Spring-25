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

    Car(string br, string mod, float rental, bool available){
        brand=br;
        model=mod;
        rentalPrice=rental;
        availability=available;
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
        cout<<"---------------"<<endl;    
    }

    void applyDiscount(int numOfDays){
        if(!availability){
            cout<<"Car is not available to be rented."<<endl;
            return;
        }

        if(numOfDays>10){
            cout<<"Final Price after discount: "<<rentalPrice*(1-0.1)<<endl;
        }
        else if(numOfDays>5){
            cout<<"Final Price after discount: "<<rentalPrice*(1-0.05)<<endl;
        }
        else if(numOfDays>0){
            cout<<"No discount can be applied"<<endl;
        }
        else{
            cout<<"Invalid Days"<<endl;
        }
    }

    Car(const Car &obj){
        brand=obj.brand;
        model=obj.model;
        rentalPrice=obj.rentalPrice;
        availability=obj.availability;
    }

    ~Car(){
        cout<<"Object is Destructed!"<<endl;
    }

};
int main(){

    Car c1("Honda","Insight",20000.45,true);
    Car c2(c1);
    c1.displayDetails();
    c2.displayDetails();

    
    return 0;
}
