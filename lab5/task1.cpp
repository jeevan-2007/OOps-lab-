#include <iostream>
using namespace std;

class apartments {
    int unique_id;
    string adress;
    string *owners_name;
    
public:
    apartments(int id, string adress, string &name) {
        unique_id = id;
        this->adress = adress;
        owners_name = new string(name);
    }
    
    apartments(apartments& owner1) {
        unique_id = owner1.unique_id;
        adress = owner1.adress;
        owners_name = new string(*owner1.owners_name);
    }
    
    void display() {
        cout << "Apartment ID: " << unique_id << endl;
        cout << "Address: " << adress << endl;
        cout << "Owner's Name: " << *owners_name << endl;
    }

    ~apartments() {
        delete owners_name;
    }
};

int main() {
    string owner_name;
    cout << "Enter name of owner 1: ";
    cin >> owner_name;
    apartments S1(2, "Karachi", owner_name);
    S1.display();
    
    return 0;
}
