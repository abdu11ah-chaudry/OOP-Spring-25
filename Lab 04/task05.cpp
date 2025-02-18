#include<iostream>
using namespace std;

class Car{
private:
    string brand;
    string model;
    float rentalPrice;
    bool availability;
    float totalRevenue;
    float finalprice=0.0;
    int carID;
    string registrationNumber;

public:
    Car(){
        brand="Unknown";
        model="Generic";
        rentalPrice=0.0;
        availability=true;
        totalRevenue=0.0;
        finalprice=0.0;
        carID=0;
        registrationNumber="Unknown";
    }

    Car(string br, string mod, float rental, bool available, float revenue, int id, string regnum){
        brand=br;
        model=mod;
        rentalPrice=rental;
        availability=available;
        totalRevenue=revenue;
        carID=id;
        registrationNumber=regnum;
    }

    void updateCarDetails(string br, string mod, float rental, bool available, float revenue, int id, string regnum){
        brand=br;
        model=mod;
        rentalPrice=rental;
        availability=available;
        totalRevenue=revenue;
        carID=id;
        registrationNumber=regnum;
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
        cout<<"Final Price after discount: "<<finalprice<<endl;
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

        finalprice=rentalPrice*numOfDays*(1-discount);

        this->totalRevenue+=finalprice;
        this->availability=false;

    }

    Car(const Car &obj){
        brand=obj.brand;
        model=obj.model;
        rentalPrice=obj.rentalPrice;
        availability=obj.availability;
        totalRevenue=obj.totalRevenue;
        finalprice=obj.finalprice;
        carID=obj.carID;
        registrationNumber=obj.registrationNumber;
    }

    ~Car(){
        cout<<"Object is Destructed!"<<endl;
    }

};
int main(){

    Car c1("Honda","Insight",20000.45,true,0.0,1,"ABC-123");
    c1.applyDiscount(11);
    c1.displayDetails();
    Car c2("Toyota","Aqua",18000,true,0.0,2,"XYZ-456");
    c2.applyDiscount(6);
    c2.displayDetails();

    
    return 0;
}
