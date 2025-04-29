/*• You are developing a simple inventory system. You need to save basic item data in one format and a
 fixed-length item name directly to a file (e.g., 20 chars).

• Task: Define a simple C++ struct (or class) named InventoryItem that contains an integer itemID and a 
character array itemName of size 20.
Create a function that accepts and creates an InventoryItem object, writes it to a binary file named "inventory.dat"
 using the write() function.

Add another function that reads from "inventory.dat" into a different InventoryItem object using the read() function,
 closes the file, and finally prints the loaded item ID and name.

• Key Concepts: read(), write(), Binary file I/O (ios::binary), ofstream, ifstream, structure/class definition, 
fixed-size character arrays.

*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
struct InventoryItem {
    int itemID;
    char itemName[20]; 
};
int main(){
    InventoryItem item;
    cout<<"ENter item id : ";
    cin>>item.itemID;
    cout<<"Enter item name : ";
    cin.ignore();
    cin.getline(item.itemName, 20); 
    ofstream outfile("inventory.dat", ios::binary | ios::app); 
    if(!outfile){
        cout<<"Error opening file!"<<endl;
        return 0;
    }
    outfile.write((char*)&item, sizeof(item));
    outfile.close();
    InventoryItem item2;
    ifstream infile("inventory.dat", ios::binary);
    if(!infile){
        cout<<"Error opening file!"<<endl;
        return 0;
    }
    infile.read((char*)&item2, sizeof(item2));
    infile.close();
    cout<<"Item ID: "<<item2.itemID<<endl;
    cout<<"Item Name: "<<item2.itemName<<endl;
    return 0;
}
