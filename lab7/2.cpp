#include<iostream>
using namespace std;

class product {
protected:
    int product_id;
    string product_name;
    int product_price;
public:
    product(int id, string name, int price) {
        product_id = id;
        product_name = name;
        product_price = price;
    }
    virtual void show() {
        cout << "Product ID: " << product_id << endl;
        cout << "Product Name: " << product_name << endl;
        cout << "Product Price: " << product_price << endl;
    }
    virtual void apply_discount(int quan) {
        if (product_price > 100) {
            product_price = product_price - (product_price * 0.1);
        } else cout << "No discount" << endl;
    }
    virtual int calculate_price(int quantity) {
        return product_price * quantity;
    }
    ~product() {
        cout << "Destructor called" << endl;
    }
    
    product operator+(const product& other) {
        return product(this->product_id, this->product_name, this->product_price + other.product_price);
    }
};

class electronics : public product {
    string brand;
    int warranty;
public:
    electronics(int id, string name, int price, string brand_name, int warranty_period) : product(id, name, price) {
        brand = brand_name;
        warranty = warranty_period;
    }
    void show() {
        product::show();
        cout << "Brand: " << brand << endl;
        cout << "Warranty: " << warranty << " years" << endl;
    }
};

class clothing : public product {
private:
    int size;
    string color;
    string fabric;
public:
    clothing(int id, string name, int price, int size_, string color_, string fabric_) : product(id, name, price) {
        size = size_;
        color = color_;
        fabric = fabric_;
    }
    void show() {
        product::show();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Fabric: " << fabric << endl;
    }
    void apply_discount(int quan) {
        if (quan > 5) {
            product_price = product_price - (product_price * 0.2);
            cout << "Total discount: " << product_price * 0.2 << endl;
            cout << "Total price: " << product_price << endl;
        } else cout << "No discount" << endl;
    }
};

class fooditem : public product {
    string expiry_date;
    int calories;
public:
    fooditem(int id, string name, int price, string expiry, int cal) : product(id, name, price) {
        expiry_date = expiry;
        calories = cal;
    }
    void show() {
        product::show();
        cout << "Expiry Date: " << expiry_date << endl;
        cout << "Calories: " << calories << endl;
    }
    int calculate_price(int quantity) {
        product_price = product_price * quantity - (product_price * 0.01 * quantity);
        cout << "Total discount: " << product_price * 0.01 * quantity << endl;
        cout << "Total price: " << product_price << endl;
        return product_price * quantity;
    }
};

class book : public product {
    string author;
    string genre;
public:
    book(int id, string name, int price, string auth, string gen)
        : product(id, name, price), author(auth), genre(gen) {}

    void show() {
        product::show();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    product* p1 = new electronics(1, "Laptop", 50000, "Dell", 2);
    product* p2 = new clothing(2, "Shirt", 1000, 40, "Blue", "Cotton");
    product* p3 = new fooditem(3, "Biscuit", 50, "12/12/2022", 100);
    book* p4 = new book(4, "C++ Programming", 2000, "Bjarne Stroustrup", "Programming");

    cout << "\n--- Product Details ---\n";
    p1->show();
    p2->apply_discount(6);
    p3->calculate_price(10);
    p4->show();
    
    product p5 = *p1 + *p2;  
    p5.show();

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}
