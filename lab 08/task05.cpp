#include<iostream>
using namespace std;

class Matrix2x2{
private:
    int a,b,c,d;
public:
    Matrix2x2(int i=0, int j=0, int k=0, int l=0):a(i),b(j),c(k),d(l){}

    Matrix2x2 operator+(Matrix2x2 &m){
        return Matrix2x2(a+m.a,b+m.b,c+m.c,d+m.d);
    }

    Matrix2x2 operator-(Matrix2x2 &m){
        return Matrix2x2(a-m.a,b-m.b,c-m.c,d-m.d);
    }

    Matrix2x2 operator*(Matrix2x2 &m){
        return Matrix2x2(a*m.a,b*m.b,c*m.c,d*m.d);
    }

    friend double determinant(Matrix2x2 &m);
    friend class MatrixHelper;
    friend ostream& operator<<(ostream& output, Matrix2x2 &m);
};

double determinant(Matrix2x2 &m){
    return m.a*m.d - m.b*m.c;
}

ostream& operator<<(ostream& output, Matrix2x2 &m){
    output<<"["<<m.a<<" "<<m.b<<"]"<<endl;
    output<<"["<<m.c<<" "<<m.d<<"]"<<endl;
    return output;
}

class MatrixHelper{
public:

    void updateElement(Matrix2x2 &m, int row, int col, double value)
    {
        if(row==1 &&col==1)
        {
            m.a = value;
        }
        else if (row==1 && col==2)
        {
            m.b = value;
        }
        else if (row==2 && col==1)
        {            
            m.c = value;
        }
        else if (row==2 && col==2)
        {
        m.d = value;
        }
        else 
        {
            cout<<"Invalid index!"<<endl;
        }
    }    

};

int main(){

    Matrix2x2 m1(1,2,3,4);
    Matrix2x2 m2(5,6,7,8);

    cout<<"Matrix 1:"<<endl<<m1;
    cout<<"Matrix 2:"<<endl<<m2;

    Matrix2x2 sum=m1+m2;
    cout<<"Sum of Matrices: "<<endl<<sum;

    Matrix2x2 diff=m1-m2;
    cout<<"Difference of Matrices: "<<endl<<diff;

    Matrix2x2 prod=m1*m2;
    cout<<"Element-wise Multiplication: "<<endl<<prod;

    cout<<"Determinant of Matrix 1: "<<determinant(m1)<<endl;
    cout<<"Determinant of Matrix 2: "<<determinant(m2)<<endl;

    MatrixHelper helper;
    helper.updateElement(m1,2,2,10);
    cout<<"Updated Matrix 1:" <<endl<<m1;


    return 0;

}
