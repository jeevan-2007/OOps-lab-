#include <iostream>
using namespace std;

class patient {
protected:
    string name;
    int id;

public:
    patient(string name, int id) {
        this->name = name;
        this->id = id;
    }

    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;
};

class inpatient : public patient {
public:
    inpatient(string name, int id) : patient(name, id) {}

    void displayTreatment() override {
        cout << "The patient " << name << " is treated for a heart attack (inpatient)." << endl;
    }

    void calculateCost() override {
        cout << "Total cost: 3300039" << endl;
    }
};

class outpatient : public patient {
public:
    outpatient(string name, int id) : patient(name, id) {}

    void displayTreatment() override {
        cout << "The patient " << name << " is treated for a heart attack (outpatient)." << endl;
    }

    void calculateCost() override {
        cout << "Total cost: 3300039" << endl;
    }
};

int main() {
    // Use dynamic allocation with base class pointer
    patient* P1 = new inpatient("John Doe", 101);
    P1->displayTreatment();
    P1->calculateCost();

    cout << endl;

    outpatient P2("Jane Smith", 202);
    P2.displayTreatment();
    P2.calculateCost();

    delete P1; // Free allocated memory
    return 0;
}
