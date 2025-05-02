#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){

    ifstream f;
    f.open("vehicle.txt");
    if(!f.is_open()){
        cout<<"Couldn't open the file"<<endl;
        return 0;
    }

    string line;
    while(getline(f,line)){
        cout<<line<<endl;
    }

    f.close();
    
    return 0;
}
