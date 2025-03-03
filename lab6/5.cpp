#include<iostream>
using namespace std;
class device{
    protected:
    int device_id;
    bool status;
    public:
    device(int id, bool s){
        device_id = id;
        status = s;
    }
    void display(){
        cout << "Device ID: " << device_id << endl;
        cout << "Status: " << status << endl;
    }
};
class mobile : public device{
    protected:
    double screen_size;
    public:
    mobile(int id, bool s, double ss) : device(id, s){
        screen_size = ss;
    }
    void display(){
        device::display();
        cout << "Screen Size: " << screen_size << " inches" << endl;
    }
};
class smartwatch : public device{
    protected :
    bool heart_rate_monitor;
    public:
    smartwatch(int id, bool s, bool hrm) : device(id, s){
        heart_rate_monitor = hrm;
    }
    void display(){
        device::display();
        cout << "Heart Rate Monitor: " << heart_rate_monitor << endl;
    }
};
class smart_wearable : public smartwatch , public mobile{
    protected :
    int step_counter;
    public:
    smart_wearable(int id, bool s, double ss, bool hrm, int sc) : smartwatch(id, s, hrm), mobile(id, s, ss){
        step_counter = sc;
    }
    void display(){
        smartwatch::display();
        mobile::display();
        cout << "Step Counter: " << step_counter << endl;
    }
};
int main(){
    device d1(123, true);
    d1.display();
    mobile m1(124, true, 6.5);
    m1.display();
    smartwatch sw1(125, true, true);
    sw1.display();
    smart_wearable swb1(126, true, 6.5, true, 10000);
    swb1.display();
    return 0;
}
