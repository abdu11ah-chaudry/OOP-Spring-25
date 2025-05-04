#include<iostream>
#include<exception>
using namespace std;

class InvalidTemperatureException:public exception{
    //no overriding of what() as mentioned in the task.    
};

template<typename T>
T convertToFahrenheit(T celsius){
    if(celsius<(-273.15))
        throw InvalidTemperatureException();
    return celsius*1.8 + 32;
}

int main(){
    double celsius;
    try{
        cout<<"Enter the temperature in celsius to be converted in Fahrenheit."<<endl;
        cin>>celsius;
        double result =convertToFahrenheit(celsius);
        cout<<"To Farhenheit: "<<result;
    }

    catch(InvalidTemperatureException& t){
        cout<<"Caught Invalid temperature Exception what().\nCan't convert less than (-273.15 C) "<<t.what();
    }

    return 0;
}
