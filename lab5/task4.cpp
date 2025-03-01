#include<iostream>
using namespace std;
class Alarmsystem{
    int id;
    string security_level;
    public :
    Alarmsystem(int id, string security_level) {
        this->id = id;
        this->security_level = security_level;
    }
    void get_security_level(){
        cout<<"Security level of alarm system with id "<<id<<" is "<<security_level<<endl;
    }
    ~Alarmsystem(){
        cout<<"Alarm system with id "<<id<<" is destroyed"<<endl;
    }
};
class smarthome{
    int house_no;
    string owner;
    Alarmsystem *alarm;
    public :
    smarthome(int house_no, string owner, int id, string security_level) {
        this->house_no = house_no;
        this->owner = owner;
        alarm = new Alarmsystem(id, security_level);
    }
    void display() {
        cout<<"House Number: "<<house_no<<endl;
        cout<<"Owner: "<<owner<<endl;
        alarm->get_security_level();
    }
    ~smarthome(){
        cout<<"Smart home with house number "<<house_no<<" is destroyed"<<endl;
        delete alarm;
    }
};
int main() {
    smarthome s1(1, "Ali", 1, "High");
    s1.display();
    return 0;
}