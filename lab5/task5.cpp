#include <iostream>
using namespace std;

class doctor {
    string name, speciality;
    int experience;
public:
    doctor() {}
    doctor(string name, string speciality, int experience) {
        this->name = name;
        this->speciality = speciality;
        this->experience = experience;
    }
    string getName() { return name; }
    void set_experience(int experience) { this->experience = experience; }
    void set_speciality(string speciality) { this->speciality = speciality; }
    void display() {
        cout << "Doctor Name: " << name << endl;
        cout << "Speciality: " << speciality << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

class hospital {
    string name, loc;
    doctor** d;
    int nod, doc_count;
public:
    hospital(string name, string loc, int nod) {
        this->name = name;
        this->loc = loc;
        this->nod = nod;
        doc_count = 0;
        d = new doctor*[nod];
    }

    void add_doctors(string name, string speciality, int experience) {
        if (doc_count < nod) {
            d[doc_count] = new doctor(name, speciality, experience);
            doc_count++;
        } else cout << "Max doctors reached!" << endl;
    }

    void remove_doctor(string name) {
        for (int i = 0; i < doc_count; i++) {
            if (d[i]->getName() == name) {
                delete d[i];
                for (int j = i; j < doc_count - 1; j++) d[j] = d[j + 1];
                doc_count--;
                break;
            }
        }
    }

    void display_docs() {
        cout << "Hospital Name: " << name << endl;
        cout << "Location: " << loc << endl;
        for (int i = 0; i < doc_count; i++) d[i]->display();
    }

    ~hospital() {
        for (int i = 0; i < doc_count; i++) delete d[i];
        delete[] d;
    }
};

int main() {
    hospital h1("Agha Khan Hospital", "Karachi", 3);
    h1.add_doctors("Dr. Ali", "Cardiologist", 10);
    h1.add_doctors("Dr. Ahmed", "Neurologist", 15);
    h1.add_doctors("Dr. Asad", "Dermatologist", 5);
    h1.display_docs();
    h1.remove_doctor("Dr. Ahmed");
    h1.display_docs();
    return 0;
}
