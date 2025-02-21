#include<iostream>
using namespace std;
class Car{
    private:
    string brand ;
    string model;
    double rental_p;
    bool availability_s;
    public:
    Car(string brand , string model, double rental, bool availability){
        this->brand=brand;
        this->model=model
        rental_p=rental;
        availability_s=availability;
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
    void apply_discount(){
        int days;
        cout<<"Tell me for how many days are you renting car :";
        cin>>days;
        if (days>=5&&days<10){
            cout<<"youve got 5 percent discout";
            rental_p-=(rental_p*0.05);
            cout<<"Your rebtal amount after discount is "<<rental_p;
        }
        else if (days>=10){
            cout<<"youve got 10 percent discout";
            rental_p-=(rental_p*0.1);
            cout<<"Your rebtal amount after discount is "<<rental_p;
        }
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
