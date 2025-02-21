#include<iostream>
using namespace std;
class Car{
    private:
    string brand ;
    string model;
    double rental_p;
    bool availability_s;
    public:
    Car(){
        brand="unknoen";
        model="generic";
        rental_p=0.0;
        availability_s=true;
    }
    void updatation(string brand,string model,double rental_p,bool availability_s){
        this->brand=brand;
        this->model=model;
        this->rental_p=rental_p;
        this->availability_s=availability_s;
    }
    void check_car(){
        if (availability_s==true)cout<<"car is available";
        else cout<<"car is not available";
    }
    void retal_req(){
        if(availability_s==true)cout<<"Caar is rented to you";
        else cout<<"Car is already rented ";
    }
};
int main(){
    Car c();
    string brand;
    string model;
    double rental_p;
    bool s;
    cout<<"enter car brand model rental price and availability : ";
    cin>>brand>>model>>rental_p>>s;
    c.updatation(brand,model,rental_p,s);
    c.check_car();
    c.retal_req();
}
