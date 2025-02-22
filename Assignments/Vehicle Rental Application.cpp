#include<iostream>
using namespace std;

class Vehicle{
private:

    string model;
    float rentalPrice;
    string requiredLiscense;

public:    

    Vehicle(){
        model="unknown";
        rentalPrice=0.0;
        requiredLiscense="none";
    }

    Vehicle(string mod, float rP, string rL){
        model=mod;
        rentalPrice=rP;
        requiredLiscense=rL;
    }

    bool isEligible(string userLicense) {
        if (userLicense == "Full") return true; 
        if (userLicense == "Intermediate" &&  requiredLiscense != "Full") return true; 
        if (userLicense == "Learner" && requiredLiscense == "Learner") return true; 
        return false; 
    }

    string getModel(){
        return model;
    }

    float getRentalPrice(){
        return rentalPrice;
    }

    string getRequiredliscense(){
        return requiredLiscense;
    }

    void displayVehicle(){
        cout<<"----------------------------"<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rental price for a day: "<<rentalPrice<<"$"<<endl;
        cout<<"required licence: "<<requiredLiscense<<endl;
    }

};

class User{
private:

    int userID;
    int age;
    string liscenseType;
    string contactInfo;

public:

    User(){
        userID=0;
        age=0;
        liscenseType="none";
        contactInfo="none";
    }

    User(int id, int a, string lType, string cinfo){
        userID=id;
        age=a;
        liscenseType=lType;
        contactInfo=cinfo;
    }

    void updateDetails(int a, string lType, string cinfo){
        age=a;
        liscenseType=lType;
        contactInfo=cinfo;
    }

    int getUserId(){
        return userID;
    }

    int getAge(){
        return age;
    }

    string getLiscenseType(){
        return liscenseType;
    }

    void displayUser(){
        cout<<"----------------------------"<<endl;
        cout<<"User ID: "<<userID<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Liscense Type: "<<liscenseType<<endl;
        cout<<"Contact Information: "<<contactInfo<<endl;
    }

};

class RentingSystem{
private:
    User **users;
    Vehicle **vehicles;
    int usersCount;
    int vehiclesCount;
    int maxUsers;
    int maxVehicles;

public:

    RentingSystem()
    {
        usersCount=0;
        vehiclesCount=0;
        maxUsers=10;
        maxVehicles=10;

        users=new User*[maxUsers];
        vehicles=new Vehicle*[maxVehicles];
    }

    void registerUser(int id, int a, string lType, string cinfo)
    {
            if(usersCount>=maxUsers)
            {
                cout<<"Maximum User registered."<<endl;
            }
            else{
                users[usersCount++]= new User(id,a,lType,cinfo);
                cout<<"User registered successfully! "<<endl;
            }
    }

    void addVehicle(string mod,float rP,string rL)
    {
            if(vehiclesCount>=maxVehicles)
            {
                cout<<"Maximum Vehicle registered"<<endl;
            }
            else{
                vehicles[vehiclesCount++]=new Vehicle(mod,rP,rL);
                cout<<"Vehicle added successfully! "<<endl;
            }
    }    

    void rentVehicle(int userId,string vehiclemodel)
    {
        User *selecteduser=nullptr;
        Vehicle *selectedVehicle=nullptr;

        for(int i=0; i<usersCount; i++){
            if(users[i]->getUserId()==userId){
                selecteduser=users[i];
                break;
            }
        }

        if(!selecteduser){
            cout<<"The selected user is not found in the system. "<<endl;
            return;
        }

        for(int i=0; i<vehiclesCount; i++){
            if(vehicles[i]->getModel()==vehiclemodel){
                selectedVehicle=vehicles[i];
                break;
            }
        }
        if(!selectedVehicle){
            cout<<"The selected Vehicle is not found in the system"<<endl;
            return;
        }

        if(selectedVehicle->isEligible(selecteduser->getLiscenseType())){
            cout << "Vehicle Rented Successfully! "<<selecteduser->getUserId()<<" rented "<<selectedVehicle->getModel()<<" for $"<<selectedVehicle->getRentalPrice()<<" per day."<<endl;
        }
        else{
            cout << "Rental Failed! The eligibilty criteria to rent the vehicle is not matched."<<endl;
        }
    }
    
    void displayAllUsers(){
        for(int i=0; i<usersCount; i++){
            cout<<"-------------------"<<endl;
            cout<<"User "<<i+1<<" : "<<endl;
            users[i]->displayUser();
        }
    }

    void displayAllvehicles(){
        for(int i=0; i<vehiclesCount; i++){
            cout<<"Vehicle "<<i+1<<" : "<<endl;
            vehicles[i]->displayVehicle();
        }
    }

    ~RentingSystem(){
        for(int i=0;i<usersCount;i++){
            delete users[i];
        }
        for(int i=0;i<vehiclesCount;i++){
            delete vehicles[i];
        }
        delete[] users;
        delete[] vehicles;
    }


};

int main(){

    RentingSystem rs;

    rs.registerUser(1,32,"Full","222-222");
    rs.registerUser(2,18,"Learner","333-333");
    rs.registerUser(3,21,"Intermediate","444-888");
    rs.registerUser(4,44,"Full","777-777");
    rs.displayAllUsers();


    rs.addVehicle("Insight",5000.5,"Full");
    rs.addVehicle("Aqua",4500.0,"Intermediate");
    rs.addVehicle("Mehran",2000.0,"Learner");
    rs.addVehicle("Poco",3700.45,"Full");
    rs.displayAllvehicles();


    rs.rentVehicle(1,"Aqua");       
    rs.rentVehicle(2,"Mehran");       
    rs.rentVehicle(3,"Insight");
    rs.rentVehicle(4,"Insight");  

    return 0;
}
