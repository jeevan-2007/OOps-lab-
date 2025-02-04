//student marks 
#include <iostream>
using namespace std;
struct student{
    string name;
    int rollnum;
    int marks[3];
};
int main(){
    int n;
    cout<<"Enter number of studnts : ";
    cin>>n;
    student *stud=new student[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the name of the student : ";
        cin>>stud[i].name;
        cout<<"Enter the roll number of the student : ";
        cin>>stud[i].rollnum;
        cout<<"Enter the marks of the student in 3 subjects : ";
        for(int j=0;j<3;j++){
            cin>>stud[i].marks[j];
        }
    }
    double avrg[3];
    for(int i=0;i<n;i++){
        avg=0;
        for(int j=0;j<3;j++){
            avg+=stud[i].marks[j];
        }
        avrg[i]=avg/3;
    }
    for(int i=0;i<n;i++){
        cout<<"The average marks of the student "<<stud[i].name<<" is "<<avrg[i]<<endl;
    }
    delete [] stud;
}