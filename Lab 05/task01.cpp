#include<iostream>
using namespace std;

class Appartment{
private:
    int ID;
    string address;
    string *ownerName;
public:
    Appartment():ID(0),address("None"),ownerName(nullptr){}

    Appartment(int id, string add, string owner){
        ID=id;
        address=add;
        ownerName= new string(owner);
    }

    Appartment(const Appartment &obj){
        this->ID=obj.ID;
        this->address=obj.address;
        this->ownerName=new string(*obj.ownerName);
    }

    void displayDetails(){
        cout<<"Appartment ID: "<<ID<<endl;
        cout<<"Appartment Address: "<<address<<endl;
        cout<<"Appartment's Owner Name: "<<*ownerName<<endl;
    }

    ~Appartment(){
        delete ownerName;
    }

};
int main(){

    Appartment a1(1,"101 Street Birminghim","Abdullah");
    Appartment a2(a1);

    a1.displayDetails();
    a2.displayDetails();


    return 0;
}
