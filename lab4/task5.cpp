#include <iostream>
using namespace std;

class Car {
private:
    int car_id;
    string brand, model;
    double rental_p, total_revenue;
    bool availability_s;

public:
    Car(int id, string brand, string model, double rental, bool availability) 
        : car_id(id), brand(brand), model(model), rental_p(rental), availability_s(availability), total_revenue(0.0) {}

    void rental_req(int days) {
        if (availability_s) {
            cout << "Car ID " << car_id << " is rented for " << days << " days.\n";
            availability_s = false;
            double discount = (days >= 10) ? 0.10 : (days >= 5) ? 0.05 : 0.0;
            double final_price = rental_p * days * (1 - discount);
            total_revenue += final_price;
            cout << "Total cost after discount: $" << final_price << endl;
        } else {
            cout << "Car is already rented.\n";
        }
    }

    void returnCar() {
        availability_s = true;
        cout << "Car ID " << car_id << " is returned and now available.\n";
    }

    void displayDetails() {
        cout << "\nCar Details:\n";
        cout << "Car ID: " << car_id << "\nBrand: " << brand << "\nModel: " << model 
             << "\nRental Price: $" << rental_p << "\nAvailability: " << (availability_s ? "Available" : "Rented") 
             << "\nTotal Revenue: $" << total_revenue << endl;
    }
};

int main() {
    int id;
    string brand, model;
    double rental_p;
    bool s;
    cout << "Enter Car ID, Brand, Model, Rental Price, and Availability (1 for available, 0 for rented): ";
    cin >> id >> brand >> model >> rental_p >> s;
    
    Car c1(id, brand, model, rental_p, s);
    
    int days;
    cout << "Enter rental duration in days: ";
    cin >> days;
    
    c1.rental_req(days);
    c1.returnCar();
    c1.displayDetails();

    return 0;
}
