#include<iostream>
using namespace std;
int main(){
    int rows, cols;
    cout<<"Enter the number of rows and columns of the matrices : "<<endl;
    cin>>rows>>cols;
    int **matrix1=new int*[rows]; 
    int **matrix2=new int*[rows];
    for(int i=0;i<rows;i++){
        matrix1[i]=new int[cols];
        matrix2[i]=new int[cols];
    }
    cout<<"Enter the elements of the first matrix : "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"Enter the element at position "<<i<<" "<<j<<" : ";
            cin>>matrix1[i][j];
        }
    }
    cout<<"Enter the elements of the second matrix : "<<endl;
    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"Enter the element at position "<<i<<" "<<j<<" : ";
            cin>>matrix2[i][j];
        }   
    }
    int **sum=new int*[rows];
    for(int i=0;i<rows;i++){
        sum[i]=new int[cols];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            sum[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    cout<<"The sum of the two matrices is : "<<endl;
    for(int i=0;i<rows;i++){
        cout<<"|";
        for(int j=0;j<cols;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<"|";
        cout<<endl;
    }
    int **sub=new int*[rows];
    for(int i=0;i<rows;i++){
        sub[i]=new int[cols];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            sub[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    cout<<"The subtraction of the two matrices is : "<<endl;
    for(int i=0;i<rows;i++){
        cout<<"|";
        for(int j=0;j<cols;j++){
            cout<<sub[i][j]<<" ";
        }
        cout<<"|";
        cout<<endl;
    }
    for(int i=0;i<rows;i++){
        delete [] matrix1[i];
        delete [] matrix2[i];
        delete [] sum[i];
        delete [] sub[i];
    }
    delete [] matrix1;
    delete [] matrix2;
    delete [] sum;
    delete [] sub;
}