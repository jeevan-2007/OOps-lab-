#include <iostream>
using namespace std;

class Car {
private:
    string brand, model;
    double rental_p, total_revenue;
    bool availability_s;

public:
    Car(string brand, string model, double rental, bool availability) {
        this->brand = brand;
        this->model = model;
        this->rental_p = rental;
        availability_s = availability;
        total_revenue = 0.0;
    }

    void rental_req(int days) {
        if (availability_s) {
            cout << "Car is rented to you for " << days << " days.\n";
            availability_s = false;
            double discount = (days >= 10) ? 0.10 : (days >= 5) ? 0.05 : 0.0;
            double final_price = rental_p * days * (1 - discount);
            total_revenue += final_price;
            cout << "Total cost after discount: $" << final_price << endl;
        } else cout << "Car is already rented.\n";
    }

    void returnCar() { availability_s = true; cout << "Car returned and is now available.\n"; }

    void displayRevenue() { cout << "Total revenue generated by " << brand << " " << model << ": $" << total_revenue << endl; }
};

int main() {
    string brand, model;
    double rental_p;
    bool s;
    cout << "Enter car brand, model, rental price, and availability (1 for available, 0 for rented): ";
    cin >> brand >> model >> rental_p >> s;
    
    Car c1(brand, model, rental_p, s);
    int days;
    cout << "Enter rental duration in days: ";
    cin >> days;
    c1.rental_req(days);
    c1.returnCar();
    c1.displayRevenue();

    return 0;
}
