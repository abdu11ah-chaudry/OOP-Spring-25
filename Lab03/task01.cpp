#include<iostream>
using namespace std;
class Wallet{
    private:
        string ownerName;
        float totalBalance;
        string transactionHistroy[25];


    public:
        Wallet(){}

        Wallet(string n,float p){
            ownerName=n;
            totalBalance=p;
        }

        int i=0;

        void addMoney(float n){
            totalBalance+=n;
            transactionHistroy[i++]=to_string(n)+"$ are added to the total balance";
        }


        void sendMoney(float n){
            totalBalance-=n;
            transactionHistroy[i++]=to_string(n)+"$ are tranfered from your wallet";
        }


        void displayTransactionHistroy(){
            for(int j=0;j<i;j++){
                cout<<transactionHistroy[j]<<endl;
            }
        }

        float getBalance(){
            return totalBalance;
        }
};

int main(){

    Wallet w1("Abdullah",10000);
    cout<<"Total balance: "<<w1.getBalance()<<endl;
    w1.addMoney(7000);
    w1.displayTransactionHistroy();
    cout<<"Total balance: "<<w1.getBalance()<<endl;
    w1.sendMoney(500);
    w1.displayTransactionHistroy();
    cout<<"Total balance: "<<w1.getBalance()<<endl;

    return 0;
}
