#include<iostream>
using namespace std;

class Car{
private:
    string brand;
    string model;
    float rentalPrice;
    bool availability;
    float totalRevenue;

public:
    Car(){
        brand="Unknown";
        model="Generic";
        rentalPrice=0.0;
        availability=true;
        totalRevenue=0.0;
    }

    Car(string br, string mod, float rental, bool available, float revenue){
        brand=br;
        model=mod;
        rentalPrice=rental;
        availability=available;
        totalRevenue=revenue;
    }

    void updateCarDetails(string br, string mod, float rental, bool available, float revenue){
        brand=br;
        model=mod;
        rentalPrice=rental;
        availability=available;
        totalRevenue=revenue;
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
        cout<<"Total Revenue: "<<totalRevenue<<endl;
        cout<<"---------------"<<endl;    
    }

    void applyDiscount(int numOfDays){
        if(!availability){
            cout<<"Car is not available to be rented."<<endl;
            return;
        }

        float discount=0.0;
        if(numOfDays>10){
            discount=0.1;
        }
        else if(numOfDays>5){
            discount=0.05;
        }

        float finalPrice=rentalPrice*numOfDays*(1-discount);

        this->totalRevenue+=finalPrice;
        this->availability=false;

    }

    Car(const Car &obj){
        brand=obj.brand;
        model=obj.model;
        rentalPrice=obj.rentalPrice;
        availability=obj.availability;
        totalRevenue=obj.totalRevenue;
    }

    ~Car(){
        cout<<"Object is Destructed!"<<endl;
    }

};
int main(){

    Car c1("Honda","Insight",20000.45,true,0.0);
    c1.displayDetails();
    c1.applyDiscount(11);
    c1.displayDetails();

    
    return 0;
}
