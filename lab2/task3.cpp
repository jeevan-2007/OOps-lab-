//Employee salry calculator
#include <iostream>
using namespace std;
struct employee{
    string name;
    int hpoursworked;
    int hourlyrate;
}
int main(){
    int n;
    cout<<"Enter the number of employees : "<<endl;
    cin>>n;
    employee *emp=new employee[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the name of the employee : "<<endl;
        cin>>emp[i].name;
        cout<<"Enter the number of hours worked by the employee : "<<endl;
        cin>>emp[i].hpoursworked;
        cout<<"Enter the hourly rate of the employee : "<<endl;
        cin>>emp[i].hourlyrate;
    }
    for(int i=0;i<n;i++){
        cout<<"The salary of the employee "<<emp[i].name<<" is "<<emp[i].hpoursworked*emp[i].hourlyrate<<endl;
    }
    delete [] emp;
    return 0;
}