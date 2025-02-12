#include<iostream>
#include<string>
using namespace std;
class Car{
    string Model;
    string Brand;
    float fuel_capacity;
    float current_fuel_level;
    public:
    Car(string model,string brand,float fuel_capacity){
        Model=model;
        Brand=brand;
        this->fuel_capacity=fuel_capacity;
        current_fuel_level=0;
    }
    void drive(float distance){
        float fuel_consumption_rate=0.1;
        float fuel_needed=distance*fuel_consumption_rate;
        if (fuel_needed>current_fuel_level){
            cout<<"Fuel is not enough to drive "<<distance<<" Plzz Refuel "endl;
        }
        else{
            current_fuel_level-=fuel_needed;
            cout<<"Car has been driven "<<distance<<".Total fuel remaining  :"<<current_fuel_level<<endl;

        }
    }
    void refuel(float fuel){
        if (fuel+current_fuel_level>fuel_capacity){
            cout<<"Fuel is not needed"<<endl;
        }
        else{
            current_fuel_level+=fuel;
            cout<<"Fuel has been refueled"<<endl;
        }
    }
    void check_fuel_status (){
        cout << "Current fuel level: " << currentFuelLevel << " liters.\n";
        if (currentFuelLevel < (fuelCapacity * 0.1)) {
            cout << "Warning: Low fuel! Please refuel soon.\n";
        }
    }
};
int main(){
    string model;
    string brand;
    float fuel_capacity;
    float Currentfurllrvel;
    cout<<"Enter the model,brand and fuel capacity of car : ";
    cin>>model>>brand>>fuel_capacity;
    cout<<"Enter the current fuel level of car : ";
    cin>>Currentfurllrvel;
    Car car1(model,brand,fuel_capacity);
    car1.drive(100);
    car1.refuel(10);
    car1.check_fuel_status();
    return 0;
}