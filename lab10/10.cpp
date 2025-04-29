#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ofstream outfile("data_records.txt", ios::trunc);
    outfile << "Record 1\n";
    outfile << "Record 2\n";
    outfile << "Record 3\n";
    outfile << "Record 4\n";
    outfile.close();

    ifstream infile("data_records.txt");
    if (!infile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    infile.seekg(12, ios::beg); 
    string record;
    getline(infile, record); 
    cout << "Third Record: " << record << endl;

    infile.close();
    return 0;
}