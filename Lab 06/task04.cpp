#include<iostream>
using namespace std;

class Account{
protected:
    int accountNumber;
    float balance;
public:
    Account(){}
    
    Account(int acNum, float bal):accountNumber(acNum),balance(bal){}

    void displayDetails(){
        cout<<"-----------------------"<<endl;
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

class SavingAccount: private Account{
private:
    float interestRate;
public:
    SavingAccount() {}

    SavingAccount(int accNum, float bal, float intRate):Account(accNum,bal),interestRate(intRate){}

    void displayDetails(){
        Account::displayDetails();
        cout<<"Interest Rate: "<<interestRate<<endl;
        cout<<"---------------------"<<endl;
    }
};

class CheckingAccount: private Account{
private:
    float overDraftLimit;
public:
    CheckingAccount() {}

    CheckingAccount(int accNum, float bal, float overlim):Account(accNum,bal),overDraftLimit(overlim){}

    void displayDetails(){
        Account::displayDetails();
        cout<<"Over Draft Limit: "<<overDraftLimit<<endl;
        cout<<"---------------------"<<endl;
    }
};

int main(){

    SavingAccount sa(1,40000.45,7.45);
    CheckingAccount ca(2,33000.4,1000);

    cout<<"Saving Account: "<<endl;
    sa.displayDetails();

    cout<<"Checking Account: "<<endl;
    ca.displayDetails();

    return 0;
}
