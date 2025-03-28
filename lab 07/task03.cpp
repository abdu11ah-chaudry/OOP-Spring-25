#include<iostream>
using namespace std;

class Ticket{
protected:
    int TicketID;
    string Passengername;
    double price;
    string date;
    string destination;
public:
    Ticket(int id, string n, double pr, string dt, string dest):TicketID(id),Passengername(n),price(pr),date(dt),destination(dest){}
    
    virtual void reserve(){
        cout<<"Seats Reserved Successfully."<<endl;
    }

    virtual void cancel(){
        cout<<"Ticket Cancelled Successfully."<<endl;
    }

    virtual void displayInfo(){
        cout<<"----------------------"<<endl;
        cout<<"Ticket ID: "<<TicketID<<endl;
        cout<<"Passenger Name: "<<Passengername<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Destination: "<<destination<<endl;
    }
};

class FlightTicket:public Ticket{
private:
    string airLineName;
    int flightNumber;
    string seatClass;
public:    
    FlightTicket(int id, string n, double pr, string dt, string dest, string airname, int fNum, string sclass):Ticket(id,n,pr,dt,dest),
    airLineName(airname),flightNumber(fNum),seatClass(sclass){}

    void displayInfo() override{
        Ticket::displayInfo();
        cout<<"AirLine Name: "<<airLineName<<endl;
        cout<<"Flight Number: "<<flightNumber<<endl;
        cout<<"Seat Class: "<<seatClass<<endl;
    }
};

class TrainTicket:public Ticket{
private:
    int trainNumber;
    string coachType;
    string departureTime;
public:
    TrainTicket(int id, string n, double pr, string dt, string dest, int tNum, string coachtyp, string depTime):Ticket(id,n,pr,dt,dest),
    trainNumber(tNum),coachType(coachtyp),departureTime(depTime){}
    
    void reserve() override{
        cout<<"Automatically seats Reserved Successfully."<<endl;
    }
};

class BusTicket:public Ticket{
private:
    string busCompany;
    int seatNumber;
public:
    BusTicket(int id, string n, double pr, string dt, string dest, string company, int seatNum):Ticket(id,n,pr,dt,dest),
    busCompany(company),seatNumber(seatNum){}

    void cancel() override{
        cout<<"Ticket Cancelled Last Minute Successfully."<<endl;
    }
};

class ConcertTicket:public Ticket{
private:
    string artistName;
    string Venue;
    string seatType;
public:
    ConcertTicket(int id, string n, double pr, string dt, string dest, string aName, string ven, string type):Ticket(id,n,pr,dt,dest),
    Venue(ven),artistName(aName),seatType(type){}
    
    void displayInfo() override{
        Ticket::displayInfo();
        cout<<"Artist Name: "<<artistName<<endl;
        cout<<"Venue: "<<Venue<<endl;
        cout<<"Seat Type: "<<seatType<<endl;
    }
};

int main() {
    
    FlightTicket flight(101, "Abdullah", 500.0, "2025-04-10", "New York", "Emirates", 9876, "Business");
    TrainTicket train(102, "Ahmed", 50.0, "2025-04-12", "Los Angeles", 2345, "First Class", "10:00 AM");
    BusTicket bus(103, "Musa", 25.0, "2025-04-15", "Chicago", "Greyhound", 12);
    ConcertTicket concert(104, "Arham", 80.0, "2025-05-01", "Las Vegas", "Taylor Swift", "Madison Square Garden", "VIP");

    
    cout<<endl<<"Displaying Ticket Information:"<<endl;
    flight.displayInfo();
    train.displayInfo();
    bus.displayInfo();
    concert.displayInfo();

    cout<<endl<<"Reserving Tickets:";
    flight.reserve();
    train.reserve();
    bus.reserve();
    concert.reserve();

    cout<<endl<<"Cancelling Tickets:"<<endl;
    flight.cancel();
    train.cancel();
    bus.cancel();
    concert.cancel();

    return 0;
}
