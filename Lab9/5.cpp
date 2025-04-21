#include<iostream>
using namespace std;

class shipment {
protected:
    string tracking_number;
    double weight;
public:
    shipment(string t, double w): tracking_number(t), weight(w) {}
    virtual void showDetails() = 0; 
    virtual void display() = 0;
    virtual ~shipment() {} // virtual destructor
};

class air_fright: public shipment {
    string flight_number;
public:
    air_fright(string t, double w, string f): shipment(t, w), flight_number(f) {}
    void showDetails() override {
        cout << "Air Flight Shipment" << endl;
        cout << "Tracking Number: " << tracking_number << endl;
        cout << "Weight: " << weight << endl;
        cout << "Flight Number: " << flight_number << endl;
    }
    void display() override {
        cout << "Air Flight Shipment" << endl;
    }
};

class ground_shipment: public shipment {
    string truck_number;
public:
    ground_shipment(string t, double w, string tr): shipment(t, w), truck_number(tr) {}
    void showDetails() override {
        cout << "Ground Shipment" << endl;
        cout << "Tracking Number: " << tracking_number << endl;
        cout << "Weight: " << weight << endl;
        cout << "Truck Number: " << truck_number << endl;
    }
    void display() override {
        cout << "Ground Shipment" << endl;
    }
};

int main() {
    shipment* s1 = new air_fright("A123", 150.5, "FL456");
    shipment* s2 = new ground_shipment("G789", 200.0, "TR123");

    s1->showDetails();
    s1->display();

    s2->showDetails();
    s2->display();

    delete s1;
    delete s2;

    return 0;
}
