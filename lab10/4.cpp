/*
Task 04: Parsing Single Extradata Formats (AutonomousCar, ElectricVehicle)
Goal: Extract and convert the numerical value from the ExtraData string for the "AutonomousCar" (Software Version) and "ElectricVehicle" (Battery Capacity) types.
Task: Using the Type string variable and the ExtraData string variable from Scenario 2, write an if else if statements block to check if the type is "AutonomousCar" or "ElectricVehicle".
If "AutonomousCar", use the find method to locate the colon (:) in the ExtraData string and the position after the colon holds the numeric software version. Then use stoi to convert this substring into an integer-type int number (intval) representing the Software Version.
If "ElectricVehicle", use find to locate the colon (:) in the ExtraData string, use the same approach to convert this into the battery capacity.
Print the extracted numerical values along with the vehicle ID. Store them if you wish to convert this substring into an integer.
Remember to use tempPos to see if the colon was found before attempting substr.
Concepts Covered: find, substr, stoi, size_t, std::string, if/else if.*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main(){
    ofstream outputfile("vehicles.txt", ios::trunc);
    outputfile << "# Vehicle data\n";
    outputfile<<"hybridtruck,1,MUstang,2023,Cargo:1000|Battery:200\n";
    outputfile.close();
    ifstream inputfile("vehicles.txt");
    if (!inputfile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1; 
    }
    string line;
    streampos before_pos,after_pos;
    while(getline(inputfile,line)){
          before_pos=inputfile.tellg();
            if(line[0]=='#') continue;
            stringstream ss(line);
            string type, make, year, seats, ExtraData;
            getline(ss, type, ',');
            getline(ss, seats, ',');
            getline(ss, make, ',');
            getline(ss, year, ',');
            getline(ss, ExtraData, ',');
            cout << "Type: " << type << ", Seats: " << seats << ", Make: " << make << ", Year: " << year << endl;
            if(type=="AutonomousCar"){
            size_t colon1 = ExtraData.find(':');             
            size_t pipe = ExtraData.find('|');               
            size_t colon2 = ExtraData.find(':', pipe); 
            int cargo = stoi(ExtraData.substr(colon1 + 1, pipe - (colon1 + 1)));
            int battery = stoi(ExtraData.substr(colon2 + 1));
            cout << "Cargo: " << cargo << ", Battery: " << battery << endl;
            after_pos=inputfile.tellg();
            cout << "Position before: " << before_pos << ", Position after: " << after_pos << endl;
         }
    }
    inputfile.close();
    return 0;
}