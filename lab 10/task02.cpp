#include<iostream>
#include<fstream>
#include<sstream>
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
    string make, model, type, year;


    while(getline(f,line)){
        if(line[0]=='/') continue;

        break;
    }

    istringstream ss(line);
    getline(ss, make, ',');
    getline(ss, model, ',');
    getline(ss, type, ',');
    getline(ss, year, ',');

    cout<<"Make: "<<make<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Type: "<<type<<endl;
    cout<<"Year: "<<year<<endl;
    
    f.close();
    return 0;
}
