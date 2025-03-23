#include<iostream>
using namespace std;
class device{
    int d_id;
    string d_name;
    bool d_status;
    public:
    device(int id, string name, bool status){
        d_id = id;
        d_name = name;
        d_status = status;
    }
    virtual void show(){
        cout << "Device ID: " << d_id << endl;
        cout << "Device Name: " << d_name << endl;
        cout << "Device Status: " << d_status << endl;
    }
    virtual void turnon(){
        d_status = true;
    }
    virtual void turnoff(){
        d_status = false;
    }
    virtual bool getstatus(){
        return d_status;
    }
    virtual void setstatus(bool status){
        d_status = status;
    }
};
class light: public device{
    int brightness;
    public:
    light(int id, string name, bool status, int bright):device(id, name, status){
        brightness = bright;
    }
    void show(){
        device::show();
        cout << "Brightness: " << brightness << endl;
    }
    void setbrightness(int bright){
        brightness = bright;
    }

};
class thermostAat: public device{
    int temperature;
    public:
    thermostAat(int id, string name, bool status, int temp):device(id, name, status){
        temperature = temp;
    }
    bool getstatus (){
        cout<<"Temperature: "<<temperature<<endl;
    }
    void settemperature(int temp){
        temperature = temp;
    }
};
class secutiry_cam: public device{
    string resolution;
    bool recording_status;
    bool night_vision;
    public:
    secutiry_cam(int id, string name, bool status, string res, bool rec, bool nv):device(id, name, status){
        resolution = res;
        recording_status = rec;
        night_vision = nv;
    }
    void show(){
        device::show();
        cout << "Resolution: " << resolution << endl;
        cout << "Recording Status: " << recording_status << endl;
        cout << "Night Vision: " << night_vision << endl;
    }
    void setresolution(string res){
        resolution = res;
    }
    void setrecording_status(bool rec){
        recording_status = rec;
    }
    void setnight_vision(bool nv){
        night_vision = nv;
    }
    void turnon(){
        recording_status = true;
        cout << "Recording Started" << endl;
    }

};
class smart_plug:public device{
    int power_consumption;
    int  time_setting;
    public:
    smart_plug(int id, string name, bool status, int power, int time):device(id, name, status){
        power_consumption = power;
        time_setting = time;
    }
    void show(){
        device::show();
        cout << "Power Consumption: " << power_consumption << endl;
        cout << "Time Setting: " << time_setting << endl;
    }
    void turnoff(){
        power_consumption = 0;
        device::turnoff();
        cout << "Power Consumption: " << power_consumption << endl;
    }

};
int main(){
    //dynamically 
    device *d1 = new light(1, "Light", true, 100);
    device *d2 = new thermostAat(2, "Thermostat", true, 25);
    device *d3 = new secutiry_cam(3, "Security Camera", true, "1080p", true, true);
    device *d4 = new smart_plug(4, "Smart Plug", true, 100, 10);
    d1->show();
    d2->getstatus();
    d3->turnon();
    d4->turnoff();
}