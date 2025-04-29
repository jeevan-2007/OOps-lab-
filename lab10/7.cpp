/*• You are logging sensor data to a file. After writing a block of data, you want to know exactly where the next write
 operation will occur in the file.
• Task:

Create an output file stream (ofstream) and open a test file (e.g., "sensor_log.txt").

Write a couple of lines of dummy sensor data (just use the << operator).

After each write operation, use the tellp() function to get the current position of the put pointer and print it to the console.

Observe how the position changes as you write more data.

Close the file at the end.

• Key Concepts: ofstream, open(), tellp(), writing data (<< operator), streampos.

*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ofstream outfile("sensor_log.txt", ios::app);
    if(!outfile){
        cout<<"Error opening file!"<<endl;
        return 0;
    }
    outfile << "Sensor Data 1: Temperature: 25.5C\n";
    cout << "Current position after first write: " << outfile.tellp() << endl;
    outfile << "Sensor Data 2: Humidity: 60%\n";
    cout << "Current position after second write: " << outfile.tellp() << endl;
    outfile << "Sensor Data 3: Pressure: 1013hPa\n";
    cout << "Current position after third write: " << outfile.tellp() << endl;
    outfile.close();
    cout << "File closed." << endl;
    return 0;
    
}