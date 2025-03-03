#include <iostream>
using namespace std;
class employee{
    protected:
    string name ;
    double salary;
    public :
    employee(string n, double s){
        name = n;
        salary = s;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};
class manager : public employee{
    protected:
    double bonus;
    public:
    manager(string n, double s, double b) : employee(n, s){
        bonus = b;
    }
    void display(){
        employee::display();
        cout << "Bonus: " << bonus << endl;
    }
};
int main(){
    employee e1("Ali", 50000);
    e1.display();
    manager m1("Ahmed", 60000, 10000);
    m1.display();
    return 0;
}   
