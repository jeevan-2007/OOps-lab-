#include<iostream>
using namespace std;
class Weather_sensor{
    public:
    virtual void read_data()=0;
    virtual void display_report()=0;
};
class Thermometer: public Weather_sensor{
    float temperature;
    public :
    Thermometer(float t):temperature(t){}
    void read_data(){
        temperature=26.6;
    }
    void display_report(){
        cout<<"Temperature: "<<temperature<<" °C"<<endl;
    }
};
class Barometer: public Weather_sensor{
    float pressure;
    public:
    Barometer(float p):pressure(p){}
    void read_data(){
        pressure=1013.25;
    }
    void display_report(){
        cout<<"Pressure: "<<pressure<<" hPa"<<endl;
    }
};
int main(){
    Weather_sensor* sensor1 = new Thermometer(0);
    Weather_sensor* sensor2 = new Barometer(0);
    
    sensor1->read_data();
    sensor1->display_report();
    
    sensor2->read_data();
    sensor2->display_report();
    
    delete sensor1;
    delete sensor2;
    
    return 0;
}