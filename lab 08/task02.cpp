#include<iostream>
using namespace std;

class Account{
private:
    int AccountNumber;
    double balance;
public:
    Account():AccountNumber(0),balance(0.0){}

    Account(int acNum, double bal):AccountNumber(acNum),balance(bal){}

    friend class Manager;
    friend void transferFunds(Account& sender, Account& reciever, double amount);
};

void transferFunds(Account& sender, Account& reciever, double amount){
    if(amount<=sender.balance){
        reciever.balance+=amount;
        sender.balance-=amount;
        cout<<"Funds Transfered Successfully."<<endl;
    }
    else{
        cout<<"Can not transfer funds due to insufficient balance."<<endl;
    }
}


class Manager{
public:
    void diplayDetails(Account &acc){
        cout<<"Account Number: "<<acc.AccountNumber<<endl;
        cout<<"Balance: "<<acc.balance<<endl;
    }
    
    void deposit(Account &acc, double amount){
        acc.balance+=amount;
        cout<<"Amount: "<<amount<<" successfully deposited to Account Number: "<<acc.AccountNumber<<endl;
    }

    void withdraw(Account &acc, double amount){
        if(amount<=acc.balance){
            acc.balance-=amount;
            cout<<"Amount: "<<amount<<" successfully withdrawn from Account Number: "<<acc.AccountNumber<<endl;
        }
        else{
            cout<<"In sufficient Funds."<<endl;
        }
    }

};


int main() {
    Account acc1(01,32000.0);
    Account acc2(02,33000.0);
    
    Manager manager;

    cout<<"Initial Details: "<<endl;
    manager.diplayDetails(acc1);
    manager.diplayDetails(acc2);
    cout<<endl;

    manager.deposit(acc1,1000.0);
    manager.withdraw(acc2,570.0);
    cout<<endl;

    cout<<"After Deposit and Withdrawal: "<<endl;
    manager.diplayDetails(acc1);
    manager.diplayDetails(acc2);
    cout<<endl;

    transferFunds(acc1,acc2,2100.0);
    cout<<endl;

    cout<<"After Transfer: "<<endl;
    manager.diplayDetails(acc1);
    manager.diplayDetails(acc2);

    return 0;
}
