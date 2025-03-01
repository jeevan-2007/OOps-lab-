#include<iostream>
using namespace std;
class student {
    int id;
    string name;
    double *marks;
    int nos;
    public :
    student(int id, string name, int nos) {
        this->id = id;
        this->name = name;
        this->nos = nos;
        marks = new double[nos];
    }
    void setMarks(int nos) {
        for(int i=0; i<nos; i++) {
            cout<<"Enter marks of subject "<<i+1<<": ";
            cin>>marks[i];
        }
    }
    student (student &s){
        id = s.id;
        name = s.name;
        nos = s.nos;
        marks = new double[nos];
        for(int i=0; i<nos; i++) {
            marks[i] = s.marks[i];
        }
        cout<<"Students info copied successfully"<<endl;

    }
    void display() {
        cout<<"Student ID: "<<id<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"Marks: ";
        for(int i=0; i<nos; i++) {
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    student s1(1, "Ali", 3);
    s1.setMarks(3);
    s1.display();
    student s2(s1);
    s2.display();
    return 0;
}