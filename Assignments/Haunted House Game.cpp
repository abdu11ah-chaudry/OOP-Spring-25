#include<iostream>
using namespace std;

class Ghost{
protected:
    string WorkerName;
    int scareLevel;
public:
    Ghost(){}

    Ghost(string n, int sLevel):WorkerName(n),scareLevel(sLevel){}

    virtual void haunt(){

    }

    friend ostream& operator<<(ostream &output, Ghost &g);

    Ghost operator+(const Ghost& g){
        Ghost upgradedGhost;
        upgradedGhost.scareLevel=scareLevel+g.scareLevel;
        upgradedGhost.WorkerName=WorkerName+" & "+g.WorkerName;

        if(upgradedGhost.scareLevel>10){
            upgradedGhost.scareLevel=10;
        }

        return upgradedGhost;
    }
};

ostream& operator<<(ostream &output, Ghost &g){
    output<<"------------------"<<endl;
    output<<"Ghost's Worker Name: "<<g.WorkerName<<endl;
    output<<"Ghost's Scare Level: "<<g.scareLevel<<endl;
    return output;
}

class Poltergeist:virtual public Ghost{    
public:
    Poltergeist(string worker, int sLevel):Ghost(worker,sLevel){}

    void haunt() override{
        cout<<"Poltergeist moves objects around! with scareLevel of "<<scareLevel<<endl;
    }    
};

class Banshee:public Ghost{
public:
    Banshee(string worker, int sLevel):Ghost(worker,sLevel){}

    void haunt() override{
        cout<<"Banshee screams loudly! with the scare level of "<<scareLevel<<endl;
    }    
};

class ShadowGhost:virtual public Ghost{
public:
    ShadowGhost(string worker, int sLevel):Ghost(worker,sLevel){}

    void haunt() override{
        cout<<"ShadowGhost Whispers Creepily in the darkness! with the scare level of "<<scareLevel<<endl;
    }    
};

class ShadowPoltergeist:public ShadowGhost, Poltergeist{
public:
    
    ShadowPoltergeist(string worker, int sLevel):Ghost(worker,sLevel),ShadowGhost(worker,sLevel),Poltergeist(worker,sLevel){}

    void haunt() override {
        ShadowGhost::haunt(); 
        Poltergeist::haunt();  
    }
};

class HauntedHouse;

class Visitor{
private:
    string name;
    int bravery;
public:
    Visitor(string n, int br):name(n),bravery(br){}
    
    string getName(){
        return name;
    }
    
    int getBravery(){
        return bravery;
    }
    
    void reactToHaunting(int scarelevel){
        if(scarelevel>bravery){
            cout<<"Screams and Runaway!"<<endl;
        }
        else if(scarelevel<bravery){
            cout<<"Laughs or taunt at the ghost!"<<endl;
        }
        else{
            cout<<"Gets shaky voice!"<<endl;
        }
    }
};

class HauntedHouse{
private:
    string houseName;
    Ghost **ghosts;
    int ghostCount;
    int ghostCapacity;
public:
    HauntedHouse(string n):houseName(n),ghostCapacity(10),ghostCount(0){
        ghosts= new Ghost*[ghostCapacity];
    }

    void addGhost(Ghost* g) {
        if (ghostCount<ghostCapacity) {
            ghosts[ghostCount++]=g;
        } else{
            cout<<"Cannot add more ghosts to " << houseName << "! as the maximum capacity of ghosts has reached."<<endl;
        }
    }

    void simulateHaunting(Visitor &v){
        cout<<"Visitor "<<v.getName()<<" is visiting the "<<houseName<<endl;
        for(int i=0; i<ghostCount; i++){
            ghosts[i]->haunt();
        }
    }

    friend ostream& operator<<(ostream &output, HauntedHouse &h);

    friend void visit(Visitor visitors[], int numOfVisitors, HauntedHouse &h);

    ~HauntedHouse(){
        for(int i=0; i<ghostCount; i++){
            delete ghosts[i];
        }
        delete[] ghosts;
    }
};

ostream& operator<<(ostream &output,HauntedHouse &h){
    output<<"-----------------------"<<endl;
    output<<"Haunted House: "<<h.houseName<<endl;
    output<<"Ghosts Inside: "<<endl;
    for(int i=0; i<h.ghostCount; i++){
        output<<*(h.ghosts[i])<<endl;
    }
    return output;
}



void visit(Visitor visitors[], int numOfVisitors, HauntedHouse &h){
    cout<<"A group of friends is visiting: "<<h.houseName<<endl;
    for(int i=0; i<numOfVisitors; i++){
        cout<<"Visitor "<<visitors[i].getName()<<" enters."<<endl;
        h.simulateHaunting(visitors[i]);
    }

    cout<<"The visit has ended, GoodBye!"<<endl;
}



int main() {

    HauntedHouse house1("The Cursed Manor");
    HauntedHouse house2("Phantom Castle");

    
    Poltergeist* ghost1 = new Poltergeist("Jack", 6);
    Banshee* ghost2 = new Banshee("Sarah", 8);
    ShadowGhost* ghost3 = new ShadowGhost("Ethan", 5);
    ShadowPoltergeist* ghost4 = new ShadowPoltergeist("Liam", 9);

    
    house1.addGhost(ghost1);
    house1.addGhost(ghost2);
    house2.addGhost(ghost3);
    house2.addGhost(ghost4);

    
    Visitor visitors[] = {
        Visitor("Alice", 3),  
        Visitor("Bob", 6),    
        Visitor("Charlie", 9) 
    };

    cout<<house1<<endl;
    cout<<house2<<endl;

    
    visit(visitors,3,house1);
    visit(visitors,3,house2);


    cout << house1 << endl;
    cout << house2 << endl;

    return 0;
}
