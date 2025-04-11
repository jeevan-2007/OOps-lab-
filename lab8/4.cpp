/*Imagine you are building a system for a car dealership to manage its inventory. Each car in the dealership has attributes such as model and price. For effective management, a dedicated InventoryManager class is required to access and modify the private data members of each car. Additionally, the dealership wants a feature that can compare two cars to determine which one is more expensive. For this, you will write a friend function that compares the prices of two objects. This task is meant to help understand how friend classes and functions can be used to extend the functionality of a class without compromising its data encapsulation.

Requirements:

Define a class Car with private members for the car’s model (a string) and its price (a double).

Use a friend class declaration to allow an InventoryManager class to modify and display car details.

Implement member functions in the InventoryManager class to update a car’s price and display its details.

Create a friend function comparePrice() that compares two Car objects and prints which car is more expensive (or if they are priced equally).

Write a main function to demonstrate creating car objects, updating prices, and comparing them.*/
#include <iostream>
#include <string>
using namespace std;
class Car {
private:
    string model;
    double price;
public:
    Car(string m, double p) : model(m), price(p) {}
    friend class InventoryManager; 
    friend void comparePrice(const Car &car1, const Car &car2); 
};
class InventoryManager {
public:
    void updatePrice(Car &car, double newPrice) {
        car.price = newPrice;
    }
    void displayCarDetails(const Car &car) {
        cout << "Model: " << car.model << ", Price: $" << car.price << endl;
    }
};
void comparePrice(const Car &car1, const Car &car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " is more expensive than " << car2.model << endl;
    } else if (car1.price < car2.price) {
        cout << car2.model << " is more expensive than " << car1.model << endl;
    } else {
        cout << car1.model << " and " << car2.model << " are priced equally." << endl;
    }
};
int main() {
    Car car1("Toyota Camry", 24000.0);
    Car car2("Honda Accord", 26000.0);
    InventoryManager manager;
    
    cout << "Before Price Update:" << endl;
    manager.displayCarDetails(car1);
    manager.displayCarDetails(car2);
    
    manager.updatePrice(car1, 25000.0);
    
    cout << "After Price Update:" << endl;
    manager.displayCarDetails(car1);
    
    comparePrice(car1, car2);
    
    return 0;
}