//traversing the array 
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"ENter no of integers to input : " ;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the integer : ";
        cin>>*(arr+i);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*(arr+i);
    }
    cout<<"The sum of the integers is : "<<sum<<endl;
    delete [] arr;
}