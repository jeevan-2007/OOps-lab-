#include <iostream>
using namespace std;

class Product {
public:
    int id;
    string name;
    string type;
    int quantity;

    void setProduct(int id, string name, string type, int quantity) {
        this->id = id;
        this->name = name;
        this->type = type;
        this->quantity = quantity;
    }

    void display() {
        cout << "Product ID: " << id << endl;
        cout << "Product Name: " << name << endl;
        cout << "Product Type: " << type << endl;
        cout << "Product Quantity: " << quantity << endl;
    }
};

class Inventory {
    Product* products;
    int count;
    int maxProducts;

public:
    Inventory(int maxProducts) {
        this->maxProducts = maxProducts;
        products = new Product[maxProducts];
        count = 0;
    }

    void addProduct(int id, string name, string type, int quantity) {
        if (count < maxProducts) {
            products[count].setProduct(id, name, type, quantity);
            count++;
        } else {
            cout << "Inventory is full!" << endl;
        }
    }

    void sortByName() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (products[i].name > products[j].name) {
                    swap(products[i], products[j]);
                }
            }
        }
    }

    void searchByID(int id) {
        for (int i = 0; i < count; i++) {
            if (products[i].id == id) {
                cout << "Product Found:\n";
                products[i].display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void displayAll() {
        for (int i = 0; i < count; i++) {
            products[i].display();
            cout << "-------------------\n";
        }
    }

    ~Inventory() {
        delete[] products;
    }
};

int main() {
    Inventory inv(5);

    inv.addProduct(101, "Laptop", "Electronics", 10);
    inv.addProduct(102, "Table", "Furniture", 5);
    inv.addProduct(103, "Phone", "Electronics", 15);
    inv.addProduct(104, "Chair", "Furniture", 20);
    inv.addProduct(105, "Monitor", "Electronics", 8);

    cout << "\nBefore Sorting:\n";
    inv.displayAll();

    inv.sortByName();
    cout << "\nAfter Sorting:\n";
    inv.displayAll();

    cout << "\nSearching for Product with ID 103:\n";
    inv.searchByID(103);

    return 0;
}
