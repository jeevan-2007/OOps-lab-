#include <iostream>
#include <string>
using namespace std;

class person {
protected:
    string name;
    int age;
    string contact;

public:
    person(string name, int age, string contact) {
        this->name = name;
        this->age = age;
        this->contact = contact;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
    }

    virtual void update_info() {
        int choice;
        cout << "What do you want to update?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Age" << endl;
        cout << "3. Contact" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new name (single word): ";
                cin >> name;
                break;
            case 2:
                cout << "Enter new age: ";
                cin >> age;
                break;
            case 3:
                cout << "Enter new contact: ";
                cin >> contact;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    virtual ~person() {} // Virtual destructor for cleanup
};

class patient : public person {
    int patient_id;
    string patient_history;
    string assigned_doctor;

public:
    patient(string name, int age, string contact, int patient_id, string patient_history, string assigned_doctor)
        : person(name, age, contact) {
        this->patient_id = patient_id;
        this->patient_history = patient_history;
        this->assigned_doctor = assigned_doctor;
    }

    void display() {
        person::display();
        cout << "Patient ID: " << patient_id << endl;
        cout << "Patient History: " << patient_history << endl;
        cout << "Assigned Doctor: " << assigned_doctor << endl;
    }

    void set_patient_history(string patient_history) {
        this->patient_history = patient_history;
    }

    void set_assigned_doctor(string assigned_doctor) {
        this->assigned_doctor = assigned_doctor;
    }
};

class doctor : public person {
    string specialization;
    double consultation_fee;
    patient* patients[10] = {nullptr};

public:
    doctor(string name, int age, string contact, string specialization, double consultation_fee)
        : person(name, age, contact) {
        this->specialization = specialization;
        this->consultation_fee = consultation_fee;
    }

    void display() {
        person::display();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: " << consultation_fee << endl;
    }

    void add_patient(patient* p) {
        for (int i = 0; i < 10; i++) {
            if (patients[i] == nullptr) {
                patients[i] = p;
                cout << "Patient added successfully!" << endl;
                return;
            }
        }
        cout << "Doctor's patient list is full!" << endl;
    }

    void display_patients() {
        cout << "Doctor's Patients:" << endl;
        for (int i = 0; i < 10; i++) {
            if (patients[i] != nullptr) {
                patients[i]->display();
            }
        }
    }
};

class nurse : public person {
    string assigned_ward;
    string duty_timings;

public:
    nurse(string name, int age, string contact, string assigned_ward, string duty_timings)
        : person(name, age, contact) {
        this->assigned_ward = assigned_ward;
        this->duty_timings = duty_timings;
    }

    void display() {
        person::display();
        cout << "Assigned Ward: " << assigned_ward << endl;
        cout << "Duty Timings: " << duty_timings << endl;
    }

    void update_info() {
        int choice;
        cout << "What do you want to update?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Age" << endl;
        cout << "3. Contact" << endl;
        cout << "4. Assigned Ward" << endl;
        cout << "5. Duty Timings" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new name (single word): ";
                cin >> name;
                break;
            case 2:
                cout << "Enter new age: ";
                cin >> age;
                break;
            case 3:
                cout << "Enter new contact: ";
                cin >> contact;
                break;
            case 4:
                cout << "Enter new assigned ward (single word): ";
                cin >> assigned_ward;
                break;
            case 5:
                cout << "Enter new duty timings (single word): ";
                cin >> duty_timings;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
};

class administrator : public person {
    string department;
    string salary;

public:
    administrator(string name, int age, string contact, string department, string salary)
        : person(name, age, contact) {
        this->department = department;
        this->salary = salary;
    }

    void display() {
        person::display();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }

    void update_info() {
        int choice;
        cout << "What do you want to update?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Age" << endl;
        cout << "3. Contact" << endl;
        cout << "4. Department" << endl;
        cout << "5. Salary" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new name (single word): ";
                cin >> name;
                break;
            case 2:
                cout << "Enter new age: ";
                cin >> age;
                break;
            case 3:
                cout << "Enter new contact: ";
                cin >> contact;
                break;
            case 4:
                cout << "Enter new department (single word): ";
                cin >> department;
                break;
            case 5:
                cout << "Enter new salary: ";
                cin >> salary;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
};

int main() {
    patient* p1 = new patient("Ali", 25, "03001234567", 1, "Fever", "DrAsad");
    p1->display();
    cout << endl;

    doctor* d1 = new doctor("DrAsad", 30, "03001234567", "Cardiologist", 5000);
    d1->add_patient(p1);
    d1->display_patients();
    cout << endl;

    nurse* n1 = new nurse("NurseAisha", 22, "03001234567", "Ward1", "8am-4pm");
    n1->display();
    cout << endl;

    administrator* a1 = new administrator("AdminAli", 35, "03001234567", "HR", "50000");
    a1->display();
    cout << endl;

    delete p1;
    delete d1;
    delete n1;
    delete a1;

    return 0;
}
