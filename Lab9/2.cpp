#include<iostream>
using namespace std;
//abstract class 
class menu_item{
    protected:
    string DishName;
    double DishPrice;
    public:
    menu_item(string name, double price): DishName(name), DishPrice(price) {}
    virtual void showDetails()=0;
    virtual void prepare()=0;
};
class Appetizer: public menu_item{
    public:
    Appetizer(string name, double price): menu_item(name, price) {}
    void showDetails(){
        cout<<"Appetizer: "<<DishName<<", Price: "<<DishPrice<<endl;
    }
    void prepare(){
        cout<<"Preparing "<<DishName<<" appetizer."<<endl;
    }
};
class MainCourse: public menu_item{
    public:
    MainCourse(string name, double price): menu_item(name, price) {}
    void showDetails(){
        cout<<"Main Course: "<<DishName<<", Price: "<<DishPrice<<endl;
    }
    void prepare(){
        cout<<"Preparing "<<DishName<<" main course."<<endl;
    }
    
};
int main(){
    
    menu_item* item1 = new Appetizer("Spring Rolls", 5.99);
    menu_item* item2 = new MainCourse("Grilled Chicken", 12.99);
    item1->showDetails();
    item1->prepare();
    item2->showDetails();
    item2->prepare();
    return 0;
}