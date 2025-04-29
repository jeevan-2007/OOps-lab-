//Task 01: Reading the Data File

//Open the provided data file (named "vehicles.txt") and read through it line by line.

//Task: Write C++ code to declare an input file stream object (ifstream), open the specified file. Include a check to make sure the file opened successfully. If it fails, print an error message. Then, using a loop with getline, read each full line from the file into a std::string variable. Lines of text may be in some common lines starting with # which imply comments. Skip those lines once the file is opening and reading line by line.

//Concepts Covered: File I/O (ifstream, open, is_open, getline), std::string.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream inputfile("vehicles.txt"); 
    if(!inputfile.is_open()){
        cout << "Error opening file!" << endl;
        return 1; 
    }
    string line;
    while(getline(inputfile, line)){
        if(line[0] == '#') continue; 
        cout << line << endl; 
    }
    inputfile.close(); 
}