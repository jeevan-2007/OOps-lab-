#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int main() {
    
    ofstream outputfile("vehicles.txt", ios::trunc);
    
    outputfile << "# Vehicle data\n";
    outputfile << "Car,1,Toyota,2020,4\n";
    outputfile << "Bus,52,Mercedes,2019\n";
    outputfile.close();
    ifstream inputfile("vehicles.txt"); 
    if (!inputfile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1; 
    }
    string line;
    while (getline(inputfile, line)) {
        if (line[0] == '#') continue; 
        stringstream ss(line);
        string type, make, year, seats;
        getline(ss, type, ',');
        getline(ss, seats, ',');
        getline(ss, make, ',');
        getline(ss, year, ',');
        cout << "Type: " << type << ", Seats: " << seats << ", Make: " << make << ", Year: " << year << endl;
    }
    inputfile.close(); 
    return 0;
}