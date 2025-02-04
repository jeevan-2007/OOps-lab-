#include<iostream>
using namespace std;
int main(){
    int pages,rows,cols;
    cout<<"Enter dimensions of the 3d matrix : ";
    cin>>pages>>rows>>cols;
    int ***matrix=new int**[pages];
    for(int i=0;i<pages;i++){
        matrix[i]=new int*[rows];
        for(int j=0;j<rows;j++){
            matrix[i][j]=new int[cols];
        }
    }
    for(int i=0;i<pages;i++){
        for(int j=0;j<rows;j++){
            for(int k=0;k<cols;k++){
                cout<<"Enter the element at position "<<i<<" "<<j<<" "<<k<<" : ";
                cin>>matrix[i][j][k];
            }
        }
    }
    for(int i=0;i<pages;i++){
        for(int j=0;j<rows;j++){
            cout<<"|\t";
            for(int k=0;k<cols;k++){
                cout<<"Enter the element at position "<<i<<" "<<j<<" "<<k<<" : ";
            }
            cout<<"\t|"<<endl;
        }
        cout<<endl;
    }
    for(int i=0;i<pages;i++){
        for(int j=0;j<rows;j++){
            delete [] matrix[i][j];
        }
        delete [] matrix[i];
    }
    
}