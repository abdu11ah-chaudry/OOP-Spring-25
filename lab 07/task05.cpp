#include<iostream>
using namespace std;

class Character{
protected:
    int characterID;
    string name;
    int healthPoints;
    int level;
    string weaponType;
public:
    Character(int id, string n, int hps, int lev, string weapon):characterID(id),name(n),healthPoints(hps),level(lev),
    weaponType(weapon){}
    
    virtual void attack(){
        cout<<"Attacking with: "<<weaponType<<endl;
    }

    virtual void defend(){
        cout<<"Defending with: "<<weaponType<<endl;
    }

    virtual void displayStats(){
        cout<<"-------------------------"<<endl;
        cout<<"Character ID: "<<characterID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Health Points: "<<healthPoints<<endl;
        cout<<"Level: "<<level<<endl;
        cout<<"Weapon Type: "<<weaponType<<endl;
    }
};

class Warrior:public Character{
private:
    int armourStrength;
    int meleeDamage;
public:
    Warrior(int id, string n, int hps, int lev, string weapon, int aStrength, int mDamage):Character(id,n,lev,hps,weapon),armourStrength(aStrength),
    meleeDamage(mDamage){}

    void attack() override
    {
        cout<<"Attacking with "<<weaponType<<" and "<<meleeDamage<<" damage"<<endl;
    }
};

class Mage:public Character{
private:
    int manaPoints;
    int spellPower;
public:
    Mage(int id, string n, int hps, int lev, string weapon, int mana, int spell):Character(id,n,lev,hps,weapon),manaPoints(mana),
    spellPower(spell){}
    
    void defend() override{
        cout<<"Defend with Magical Barriers"<<endl;
    }
};

class Archer:public Character{
private:
    int arrowCounts;
    int rangeAccuracy;
public:
    Archer(int id, string n, int hps, int lev, string weapon, int arrow, int range):Character(id,n,lev,hps,weapon),arrowCounts(arrow),
    rangeAccuracy(range){}

    void attack() override{
        cout<<"Use Arrow for Long range attack"<<endl;
    }
};

class Rogue:public Character{
private:
    int sleathLevel;
    int agility;
public:
    Rogue(int id, string n, int hps, int lev, string weapon, int sLevel, int agil):Character(id,n,lev,hps,weapon),sleathLevel(sLevel),
    agility(agil){}
    
    void displayStats() override{
        Character::displayStats();
        cout<<"Sleath Level: "<<sleathLevel<<endl;
        cout<<"Agility: "<<agility<<endl;
    }
};

int main() {
    
    Warrior warrior1(101, "Ragnar", 150, 5, "Sword", 80, 50);
    
    Mage mage1(102, "Merlin", 120, 6, "Staff", 200, 70);

    Archer archer1(103, "Legolas", 130, 5, "Bow", 30, 90);

    Rogue rogue1(104, "Shadow", 110, 4, "Dagger", 95, 85);

    cout<<endl<<"---- Warrior Stats -----"<<endl;
    warrior1.displayStats();
    warrior1.attack();
    warrior1.defend();

    cout<<endl<<"---- Mage Stats ----"<<endl;
    mage1.displayStats();
    mage1.attack();
    mage1.defend();

    cout<<endl<<"---- Archer Stats -----"<<endl;
    archer1.displayStats();
    archer1.attack();
    archer1.defend();

    cout<<endl<<"---- Rogue Stats -----"<<endl;
    rogue1.displayStats();
    rogue1.attack();
    rogue1.defend();

    return 0;
}

