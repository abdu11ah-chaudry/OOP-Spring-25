#include<iostream>
using namespace std;

class MenuItem{
protected:
    string dishName;
    double price;
public:
    MenuItem(string n, double p):dishName(n),price(p){}

    virtual void showDetails()=0;
    virtual void prepare()=0;

    virtual ~MenuItem(){}
};

class Apetizer:public MenuItem{
public:
    Apetizer(string n, double p):MenuItem(n,p){}

    void showDetails() override{
        cout<<"-------Apetizer---------"<<endl;
        cout<<"Dish Name: "<<dishName<<endl;
        cout<<"Dish Price: "<<price<<endl;
    }
    
    void prepare() override{
        cout<<"Preparing the dish "<<dishName<<endl;
    }
};

class MainCourse:public MenuItem{
public:
    MainCourse(string n, double p):MenuItem(n,p){}    

    void showDetails() override{
        cout<<"-------MainCourse---------"<<endl;
        cout<<"Dish Name: "<<dishName<<endl;
        cout<<"Dish Price: "<<price<<endl;
    }
        
    void prepare() override{
        cout<<"Preparing the dish "<<dishName<<endl;
    }
};

int main(){

    MenuItem* m1= new Apetizer("Fish And Chips",1000);
    MenuItem* m2= new MainCourse("Pasta",5000);

    m1->showDetails();
    m1->prepare();

    m2->showDetails();
    m2->prepare();
    
    delete m1;
    delete m2;

    return 0;
}
