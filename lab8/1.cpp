//Qno 1
#include <iostream>
#include <cmath>
using namespace std;
class complex{
    private:
    int real;
    int  imag;    
    public:
    complex(int r=0,int i=0):real(r),imag(i){}
    complex operator+(complex c){
        return complex(real+c.real,imag+c.imag);
    }
    complex operator-(complex c){
        return complex(real-c.real,imag-c.imag);
    }
    complex operator*(complex c){
        return complex(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
    }
    complex operator/(complex c){
        int denominator=c.real*c.real+c.imag*c.imag;
        return complex((real*c.real+imag*c.imag)/denominator,(imag*c.real-real*c.imag)/denominator);
    }
    friend double magnitude(complex c){
        return sqrt(c.real*c.real+c.imag*c.imag);
    }
    friend ostream& operator<<(ostream& obj,complex c){
        if(c.imag>=0)
            obj<<c.real<<"+"<<c.imag<<"i";
        else
            obj<<c.real<<c.imag<<"i";
        return obj;
    }

};
int main(){
    complex c1(3,4),c2(1,2);
    complex c3=c1+c2;
    complex c4=c1-c2;
    complex c5=c1*c2;
    complex c6=c1/c2;

    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;
    cout<<"c1+c2: "<<c3<<endl;
    cout<<"c1-c2: "<<c4<<endl;
    cout<<"c1*c2: "<<c5<<endl;
    cout<<"c1/c2: "<<c6<<endl;
    cout<<"Magnitude of c1: "<<magnitude(c1)<<endl;
    cout<<"Magnitude of c2: "<<magnitude(c2)<<endl;
}
