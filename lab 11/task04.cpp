#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override{
        return "A database error occurred.";
    }
};

class QueryTimeoutException : public DatabaseException {
    //No overriding of what()
};
class ConnectionFailedException : public DatabaseException {
    //No overriding of what()
};

template<typename T>
class DatabaseConnector{
private:
    T dbName;
public:
    DatabaseConnector(T dbName):dbName(dbName){}

    void connect(){
        if(dbName=="invalid_db"){
            throw ConnectionFailedException();
        } 
        else if(dbName=="slow_db") {
            throw QueryTimeoutException();
        } 
        else{
            cout<<"Connected to "<<dbName<<" successfully."<<endl;
        }
    }
};

int main(){
    try{
        cout<<"Attempting to connect to invalid_db..."<<endl;
        DatabaseConnector<string> connector1("invalid_db");
        connector1.connect();
    } 
    catch(const ConnectionFailedException& e){
        cout<<"Caught Connection FailedException what(): "<<e.what()<<endl;
    }

    try{
        cout<<"\nAttempting to connect to slow_db..."<<endl;
        DatabaseConnector<string> connector2("slow_db");
        connector2.connect();
    } 
    catch(const DatabaseException& e){
        cout<<"Caught a general DatabaseException what(): "<<e.what()<<endl;
    }
    
    return 0;
}
