#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    ofstream outputfile("vehicles.txt", ios::trunc);
    outputfile << "# Vehicle data\n";
    outputfile << "Car,1,Toyota,2020,4\n";
    outputfile << "Bus,52,Mercedes,2019\n";
    outputfile << "AutonomousCar,1,Waymo,2021,Software Version: 2.0\n";
    outputfile << "ElectricVehicle,1,Tesla,2022,Battery Capacity: 75kWh\n";
    outputfile << "HybridTruck,1,Ford,2023,Cargo:1000|Battery:200\n";
    outputfile.close();
    ifstream inputfile("vehicles.txt");
    if (!inputfile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1; 
    }
    string line;
    
}