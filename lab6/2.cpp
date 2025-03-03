#include<iostream>
using namespace std;
class vehicle {
    string brand;
    int speed;
    public:
    vehicle(string b, int s){
        brand = b;
        speed = s;
    }
    void display(){
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
    }
};
class car : public vehicle{
    int seats;
    public:
    car(string b, int s, int st) : vehicle(b, s){
        seats = st;
    }
    void display(){
        vehicle::display();
        cout << "Seats: " << seats << endl;
    }
};
class Ecar : public car {
    int battery_life;
    public:
    Ecar(string b, int s, int st, int bl) : car(b, s, st){
        battery_life = bl;
    }
    void display(){
        car::display();
        cout << "Battery Life: " << battery_life <<" kms"<< endl;
    }
};
int main(){
    vehicle v1("Toyota", 200);
    v1.display();
    car c1("Honda", 250, 4);
    c1.display();
    Ecar ec1("Tesla", 300, 2, 100);
    ec1.display();
    return 0;
}