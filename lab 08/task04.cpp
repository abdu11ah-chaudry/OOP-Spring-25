#include<iostream>
using namespace std;

class Car{
private:
    string model;
    double price;
public:
    Car(){}

    Car(string mod, double p):model(mod),price(p){}

    friend class InventoryManager;
    friend void compareCar(Car &c1, Car &c2);
};

void compareCar(Car &c1, Car &c2){
    if(c1.price>c2.price){
        cout<<"Car: "<<c1.model<<" is more expensive"<<endl;
    }
    else if(c2.price>c1.price){
        cout<<"Car: "<<c2.model<<" is more expensive"<<endl;
    }
    else{
        cout<<"Both cars have equal prices."<<endl;
    }
}



class InventoryManager{
public:
    void updatePrice(Car c, double newPrice){
        c.price=newPrice;
        cout<<"Price Updated Successfully."<<endl;
    }

    void displayDetails(Car c){
        cout<<"Model: "<<c.model<<endl;
        cout<<"Price: "<<c.price<<endl;
    }

};

int main(){

    Car c1("Honda Vezel",4500000);
    Car c2("Kia Stonic",4000000);

    InventoryManager manager;

    cout<<"Initial Car Details: "<<endl;
    manager.displayDetails(c1);
    manager.displayDetails(c2);
    cout<<endl;

    compareCar(c1,c2);
    cout<<endl;

    manager.updatePrice(c1,28000);
    cout<<"After Price Update: "<<endl;
    manager.displayDetails(c1);
    cout<<endl;

    compareCar(c1,c2);

    return 0;
}
