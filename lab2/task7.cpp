//matrix multiplication using pointers
#include <iostream>
using namespace std;
int main(){
    int **matrix1,**matrix2,**product;
    int rows1, cols1,rows2, cols2;
    cout<<"Enter dimensions of matix 1 : ";
    cin>>rows1>>cols1;
    cout<<"Enter dimension of matrix 2 : ";
    cin>>rows2>>cols2;
    if (cols1!=rows2){
        cout<<"Matrix multiplication not possible";
        return 0;
    }
    else{
    matrix1=new int*[rows1];
    matrix2=new int*[rows2];
    for(int i=0;i<rows1;i++){
        matrix1[i]=new int[cols1];
        matrix2[i]=new int[cols2];
    }
    product=new int*[rows1];
    for(int i=0;i<rows1;i++){
        product[i]=new int[cols2];
    }
    cout<<"For elments of matrix 1 :"<<endl;
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            cout<<"Enter the element at position "<<i<<" "<<j<<" of matrix 1 : ";
            cin>>matrix1[i][j];
        }
    }
    cout<<"For elments of matrix 2 :"<<endl;
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            cout<<"Enter the element at position "<<i<<" "<<j<<" of matrix 2 : ";
            cin>>matrix2[i][j];
        }
    }
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
            product[i][j]=0;
            for(int k=0;k<cols1;k++){
                product[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    cout<<"The product of the two matrices is : "<<endl;
    for(int i=0;i<rows1;i++){
        cout<<"|";
        for(int j=0;j<cols2;j++){
            cout<<product[i][j]<<" ";
        }
        cout<<"\t|";
        cout<<endl;
    }
    for(int i=0;i<rows1;i++){
        delete [] matrix1[i];
    }
    for(int i=0;i<rows2;i++){
        delete [] matrix2[i];
    }
    for(int i=0;i<rows1;i++){
        delete [] product[i];
    }
    delete matrix1;
    delete matrix2;
    delete product;

}
}