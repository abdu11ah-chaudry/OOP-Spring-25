#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
protected:
    string id, name, email;
    bool paid;
public:
    User(string i, string n, string e) : id(i), name(n), email(e), paid(false) {}
    virtual double calculateFare(bool isAC) = 0;
    void makePayment() { paid = true; }
    bool hasPaid() { return paid; }
    string getId() { return id; }
    void saveToFile(ofstream& file) {
        file << id << "," << name << "," << email << "," << paid << "\n";
    }
    virtual void display() = 0;
};

class Student : public User {
public:
    Student(string i, string n, string e) : User(i, n, e) {}
    double calculateFare(bool isAC) override {
        return isAC ? 3500 : 1500;
    }
    void display() override {
        cout << "Student: " << name << " (ID: " << id << ")\n";
    }
};

class Faculty : public User {
public:
    Faculty(string i, string n, string e) : User(i, n, e) {}
    double calculateFare(bool isAC) override {
        return isAC ? 5000 : 3000;
    }
    void display() override {
        cout << "Faculty: " << name << " (ID: " << id << ")\n";
    }
};

class Route {
    string id, start, end;
    double distance;
public:
    Route(string i, string s, string e, double d) : id(i), start(s), end(e), distance(d) {}
    string getId() { return id; }
    void saveToFile(ofstream& file) {
        file << id << "," << start << "," << end << "," << distance << "\n";
    }
    void display() {
        cout << "Route " << id << ": " << start << " to " << end << " (" << distance << " km)\n";
    }
};

class Driver {
    string id, name, license;
    string assignedVehicle;
public:
    Driver(string i, string n, string l) : id(i), name(n), license(l), assignedVehicle("") {}
    void assignVehicle(string v) { assignedVehicle = v; }
    void removeVehicle() { assignedVehicle = ""; }
    string getId() { return id; }
    void saveToFile(ofstream& file) {
        file << id << "," << name << "," << license << "," << assignedVehicle << "\n";
    }
    void display() {
        cout << "Driver " << name << " (ID: " << id << ")";
        if (!assignedVehicle.empty()) 
            cout << " - Assigned to vehicle " << assignedVehicle;
        cout << "\n";
    }
};

class Vehicle {
protected:
    string id, model;
    bool ac;
    Driver* driver;
    Route* route;
    int totalSeats;
    int bookedSeats;
public:
    Vehicle(string i, string m, bool a, Route* r, int s) : 
        id(i), model(m), ac(a), route(r), totalSeats(s), bookedSeats(0), driver(nullptr) {}
    virtual ~Vehicle() {}
    void assignDriver(Driver* d) { driver = d; d->assignVehicle(id); }
    void removeDriver() { if (driver) driver->removeVehicle(); driver = nullptr; }
    virtual bool bookSeat() {
        if (bookedSeats < totalSeats) {
            bookedSeats++;
            return true;
        }
        return false;
    }
    string getId() { return id; }
    void saveToFile(ofstream& file) {
        file << id << "," << model << "," << ac << "," 
             << (driver ? driver->getId() : "null") << ","
             << (route ? route->getId() : "null") << ","
             << totalSeats << "," << bookedSeats << "\n";
    }
    virtual void display() = 0;
};

class Bus : public Vehicle {
public:
    Bus(string i, string m, bool a, Route* r) : Vehicle(i, m, a, r, 52) {}
    void display() override {
        cout << "Bus " << id << " (" << model << ") - " 
             << (ac ? "AC" : "Non-AC") << " - Seats: " 
             << bookedSeats << "/" << totalSeats << "\n";
    }
};

class Coaster : public Vehicle {
public:
    Coaster(string i, string m, bool a, Route* r) : Vehicle(i, m, a, r, 32) {}
    void display() override {
        cout << "Coaster " << id << " (" << model << ") - " 
             << (ac ? "AC" : "Non-AC") << " - Seats: " 
             << bookedSeats << "/" << totalSeats << "\n";
    }
};

class TransportSystem {
    User* users[100];
    Driver* drivers[50];
    Route* routes[30];
    Vehicle* vehicles[40];
    int userCount, driverCount, routeCount, vehicleCount;
public:
    TransportSystem() : userCount(0), driverCount(0), routeCount(0), vehicleCount(0) {}
    
    void addUser(User* u) { users[userCount++] = u; }
    void addDriver(Driver* d) { drivers[driverCount++] = d; }
    void addRoute(Route* r) { routes[routeCount++] = r; }
    void addVehicle(Vehicle* v) { vehicles[vehicleCount++] = v; }
    
    void saveAllData() {
        ofstream userFile("users.txt"), driverFile("drivers.txt"), 
                routeFile("routes.txt"), vehicleFile("vehicles.txt");
        
        for (int i = 0; i < userCount; i++) users[i]->saveToFile(userFile);
        for (int i = 0; i < driverCount; i++) drivers[i]->saveToFile(driverFile);
        for (int i = 0; i < routeCount; i++) routes[i]->saveToFile(routeFile);
        for (int i = 0; i < vehicleCount; i++) vehicles[i]->saveToFile(vehicleFile);
    }
    
    void displayAll() {
        cout << "=== Users ===\n";
        for (int i = 0; i < userCount; i++) users[i]->display();
        
        cout << "\n=== Drivers ===\n";
        for (int i = 0; i < driverCount; i++) drivers[i]->display();
        
        cout << "\n=== Routes ===\n";
        for (int i = 0; i < routeCount; i++) routes[i]->display();
        
        cout << "\n=== Vehicles ===\n";
        for (int i = 0; i < vehicleCount; i++) vehicles[i]->display();
    }
};

int main() {
    TransportSystem system;
    
    Route r1("R001", "Fast Campus", "Saddar", 15.5);
    Route r2("R002", "Fast Campus", "Highway", 5.2);
    system.addRoute(&r1);
    system.addRoute(&r2);
    
    Driver d1("D001", "Ali Khan", "LIC12345");
    Driver d2("D002", "Ahmed Raza", "LIC67890");
    system.addDriver(&d1);
    system.addDriver(&d2);
    
    Bus b1("V001", "Hino", true, &r1);
    Coaster c1("V002", "Toyota", false, &r2);
    system.addVehicle(&b1);
    system.addVehicle(&c1);
    
    b1.assignDriver(&d1);
    c1.assignDriver(&d2);
    
    Student s1("S001", "Bilal Ahmed", "bilal@email.com");
    Faculty f1("F001", "Dr. Saeed", "saeed@email.com");
    system.addUser(&s1);
    system.addUser(&f1);
    
    s1.makePayment();
    f1.makePayment();
    
    b1.bookSeat();
    c1.bookSeat();
    
    system.displayAll();
    system.saveAllData();
    
    return 0;
}
