/*You are reading a large log file piece by piece. After reading a certain amount of data, you want to record exactly
 how far you’ve progressed into the file.

Task:
Create a text file (e.g., "large_log.txt") with several lines of text. Open it with an input file stream (ifstream). 
Read the first 10 characters using the read() function (or read a line using getline). Immediately after reading, use
 the tellg() function to get the current position of the get pointer and print this position. Read another block of 
 data (e.g., the next 10 characters or another line) and again print the position using tellg(). Close the file at the end.

Key Concepts:
ifstream, open(), read() (or getline), tellg(), streampos

*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ofstream writefile("large_log.txt", ios::trunc);
    writefile<<"Sir talha plz oop mein 4 deden\n";
    writefile << "This is a large log file.\n";
    writefile<<"Hello World!\n";
    writefile.close();
    ifstream readfile("large_log.txt");
    if(!readfile){
        cout<<"Error opening file!"<<endl;
        return 0;
    }
    char buffer[11]; 
    readfile.read(buffer, 10); 
    buffer[10] = '\0';
    cout << "Read data: " << buffer << endl;
    cout << "Current position after first read: " << readfile.tellg() << endl;
    readfile.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Read data: " << buffer << endl;
    cout << "Current position after second read: " << readfile.tellg() << endl;
    readfile.close();
    cout << "File closed." << endl;
    return 0;
}