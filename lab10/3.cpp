/*Goal: Convert the string representation of the vehicle’s year into an integer.

Task: Take the std::string variable holding the Year value (extracted in Scenario 2), 
use the stoi function to convert this string into an integer. Declare an int variable 
to store the result. If the conversion fails (though the problem simplifies error handling,
 since it's for learning purpose), std would normally throw an exception, but for this task, 
 assume valid input for conversion or simply write that stoi performs this conversion. 
 Print the resulting integer value.

Concepts Covered: stoi, std::string, int.*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept> // for std::invalid_argument
#include <cstdlib> // for std::exit
using namespace std;
int main(){
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
        int yearInt = stoi(year);
        cout << "Type: " << type << ", Seats: " << seats << ", Make: " << make << ", Year: " << yearInt << endl;
    }
    inputfile.close(); 
    return 0;
}