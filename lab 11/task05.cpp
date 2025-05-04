#include<iostream>
#include<exception>
using namespace std;

class NegativeStockException: public exception{
    //No overriding of what as mentioned in the task.
};    

class OverCapacityException: public exception{
    //No overriding of what as mentioned in the task.
};

template<typename T>
class InventoryItem{
private:
    T stockPrice;
    int maxLimit;
public:
    InventoryItem(T st, int max):stockPrice(st),maxLimit(max){}
    
    void setStock(){
        if(stockPrice<0)
            throw NegativeStockException(); 
        if(stockPrice>maxLimit)
            throw OverCapacityException();
        cout<<"Stock set to: "<<stockPrice<<endl;
    }

};

int main(){

    InventoryItem<double> I1(-3,25);
    InventoryItem<int> I2(50,30);

    try{
        I1.setStock();
    }
    catch(NegativeStockException &e1){
        cout<<"Caught Negative Stock Exception what()"<<e1.what()<<endl;
    }

    try{
        I2.setStock();
    }
    catch(OverCapacityException &e2){
        cout<<"Caught Over Capacity Exception what()"<<e2.what()<<endl;
    }

}
