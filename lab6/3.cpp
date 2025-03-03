#include<iostream>
using namespace std;
class person{
    protected:
    string name;
    int age;
    public:
    person(string n, int a){
        name = n;
        age = a;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class teacher : public person{
    string subject ;
    public:
    teacher(string n, int a, string s) : person(n, a){
        subject = s;
    }
    void display(){
        person::display();
        cout << "Subject: " << subject << endl;
    }
};
class researcher : public teacher{
    string research_area;
    public:
    researcher(string n, int a, string s, string ra) : teacher(n, a, s){
        research_area = ra;
    }
    void display(){
        teacher::display();
        cout << "Research Area: " << research_area << endl;
    }
};
class professor : public researcher {
    int no_of_publications;
    public:
    professor(string n, int a, string s, string ra, int nop) : researcher(n, a, s, ra){
        no_of_publications = nop;
    }
    void display(){
        researcher::display();
        cout << "No of Publications: " << no_of_publications << endl;
    }
};
int main(){
    person p1("bobzy the king", 30);
    p1.display();
    teacher t1("Mike Tyson", 40, "Maths");
    t1.display();
    researcher r1("Atif taahir The Goat", 50, "Physics", "Quantum Mechanics");
    r1.display();
    professor pr1("Puneet superstar", 60, "Chemistry", "Organic Chemistry", 100);
    pr1.display();
    return 0;
}