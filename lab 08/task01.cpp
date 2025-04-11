#include<iostream>
#include<cmath>
using namespace std;

class Complex{
private:
    int real;
    int imag;
public:
    Complex():real(0),imag(0){}

    Complex(int r, int i){
        real=r;
        imag=i;
    }
    
    Complex operator +(Complex c){
        return Complex(real+c.real, imag+c.imag);
    }

    Complex operator -(Complex c){
        return Complex(real-c.real, imag-c.imag);
    }

    Complex operator *(Complex c){
        return Complex(real*c.real, imag*c.imag);
    }

    Complex operator /(Complex c){
        double denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator,(imag * c.real - real * c.imag) / denominator);
    }

    friend ostream& operator<<(ostream& output, Complex c);
    friend double magnitude(Complex& c);
};

ostream& operator<<(ostream& output, Complex c){
    output<<"Complex Number: "<<c.real<<(c.imag>0? " +":" -")<<abs(c.imag)<<"i"<<endl;
    return output;
}

double magnitude(Complex& c){
    return sqrt(c.real*c.real + c.imag*c.imag);
}

int main(){

    Complex c1(4,3);
    Complex c2(3,2);

    Complex sum =c1+c2;
    Complex diff =c1-c2;
    Complex prod =c1*c2;
    Complex quot =c1/c2;

    cout<<"c1= "<<c1<<endl;
    cout<<"c2= "<<c2<< endl;
    cout<<"c1 + c2 = "<<c1+c2<<endl;
    cout<<"c1 - c2 = "<<c1-c2<<endl;
    cout<<"c1 * c2 = "<<c1*c2<<endl;
    cout<<"c1 / c2 = "<<c1/c2<<endl;
    cout<<"Magnitude of c1= "<<magnitude(c1)<<endl;
    cout<<"Magnitude of c2= "<<magnitude(c2)<<endl;

    return 0;
}
