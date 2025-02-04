//product inventory
#include<iostream>
using namespace std;
struct product{
    int product_id;
    string name;
    int price;
    int quantity;
};
int main(){
    int n;
    cout<<"ENter the number of products : ";
    cin>>n;
    product *products=new product[n];
    double total=0;
    for(int i=0;i<n;i++){
        cout<<"For product no "<<i+1<<" :";
        cout<<" Product Name : ";
        cin>>products[i].name;
        cout<<" Product id : ";
        cin>>products[i].product_id;
        cout<<" Product price : ";
        cin>>products[i].price;
        cout<<" Product quantity : ";
        cin>>products[i].quantity;
        total+=products[i].price*products[i].quantity;
    }
    cout<<"The total value of the inventory is : "<<total;
    delete [] products;
}