#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ofstream outfile("config.text", ios::trunc);
    outfile << "AAA01\n";
    outfile << "BBB00\n";
    outfile << "CCC01\n";
    outfile.close();
    fstream file("config.text", ios::in | ios::out | ios::ate);
    if(!file){
        cout<<"Error opening file!"<<endl;
        return 0;
    }
    file.seekp(9); 
    file.put('1'); 
    file.seekg(0); 
    string line;
    while(getline(file, line)){
        cout << line << endl; 
    }
    file.close();
    return 0;
}