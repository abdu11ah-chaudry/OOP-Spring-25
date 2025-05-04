#include<iostream>
#include<sstream>
#include<stdexcept>
using namespace std;


class DimensionMissMatch: public exception{
private:
    string message;
public:
    DimensionMissMatch(int r1, int c1, int r2, int c2){
        stringstream ss;
        ss<<"Dimension Missmatch exception.\nMatrices must have same dimensions ("<<r1<<"x"<<c1<<" vs "
        <<r2<<"x"<<c2<<") !";
        message=ss.str();
    }
    
    const char* what() const noexcept override{
        return message.c_str();
    }
};

template<typename T>
class Matrix{
private:
    int rows,cols;
    T** data;
public:
    Matrix(int r, int c):rows(r),cols(c){
        data=new T*[rows];
        for(int i=0; i<rows; i++){
            data[i]=new T[cols];
        }
    }
    
    void input(){
        cout<<"Enter the elements for "<<rows<<"x"<<cols<<" matrix: "<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cin>>data[i][j];
            }
        }
    }

    void print(){
        cout<<"Matrix "<<rows<<"x"<<cols<<": "<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other){
        if(rows!=other.rows || cols!=other.cols)
            throw DimensionMissMatch(rows,cols,other.rows,other.cols);

        Matrix<T> result(rows,cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                result.data[i][j]=data[i][j]+other.data[i][j];
            }
        }
        return result;    
    }

    ~Matrix(){
        for(int i=0; i<rows; i++){
            delete[] data[i];
        }
        delete[] data;
    }

};

int main(){

    try{
        Matrix<int> A(2,2);
        Matrix<int> B(3,2);

        cout<<"Matrix A:"<<endl;
        A.input();

        cout << "Matrix B:"<<endl;
        B.input();

        Matrix<int> C = A + B;

        cout << "Result: "<<endl;
        C.print();
    } 
    catch(const DimensionMissMatch& d){
        cout<<d.what()<<endl;
    }
    return 0;
}
