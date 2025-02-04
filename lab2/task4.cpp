//Dynamic array of string
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"ENter no of strings you want to enter : "<<endl;
    cin>>n;
    string *arr=new string[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the string : ";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]>arr[j]){
                string temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"The sorted array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    delete [] arr;

}