#include <iostream>
using namespace std;
class patient{
    protected:
    string name;
    int id;
    public:
    patient(string name,int id){
        this->name=name;
        this->id=id;
    }
    virtual void displayTreatment()=0;
    virtual void calculateCost()=0;
};
class inpatient: public patient{
    public :
    void displayTreatment(){
        cout<<"The patient is treated for heart attack"<<endl;
    }
    void calculateCost(){
        cout<<"Total cost : 3300039";
    }
};
class outpatient: public patient{
    public :
    void displayTreatment(){
        cout<<"The patient is treated for heart attack"<<endl;
    }
    void calculateCost(){
        cout<<"Total cost : 3300039";
    }
};
int main(){
    patient* P1("jeevan",1);
    P1.displayTreatment();
    P1.calculateCost();
    outpatient P2;
    P2.displayTreatment();
    P2.calculateCost();
}
