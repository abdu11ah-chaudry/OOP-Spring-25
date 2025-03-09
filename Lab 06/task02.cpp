#include<iostream>
using namespace std;

class Vehicle{
protected:
    string brand;
    int speed;
public:
    Vehicle() {}
    Vehicle(string br, int sp):brand(br),speed(sp){}

    void display(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<endl;
    }
};

class Car:protected Vehicle{
protected:
    int seats;
public:
    Car() {}
    Car(string br, int sp, int seat):Vehicle(br,sp),seats(seat){}

    void display(){
        Vehicle::display();
        cout<<"Seats: "<<seats<<endl;
    }
};

class ElectricCar:private Car{
private:
    int batteryLife;
public:
    ElectricCar() {}
    ElectricCar(string br, int sp, int seat, int btLife):Car(br,sp,seat),batteryLife(btLife){}
    
    void display(){
        Car::display();
        cout<<"Battery Life: "<<batteryLife<<endl;
    }
};
int main(){

    ElectricCar c("BMW",200,4,100);
    c.display();
}
