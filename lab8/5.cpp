/*Matrix operations are fundamental in many computational problems, including computer graphics, simulations, and data transformations. In this task, you will develop a Matrix2x2 class that represents a 2x2 matrix with integer elements. The class should support standard matrix operations such as addition, subtraction, and multiplication through operator overloading. You will also write a function to compute the determinant of the matrix. In addition, a friend class named MatrixHelper will be created to update a specific element of the matrix, reflecting how utility classes can be used to manipulate core data structures safely.

Requirements:

Create a class Matrix2x2 with private members to store four integers (matrix elements).

Overload the operators +, -, and * to implement matrix addition, subtraction, and multiplication.

Define a friend function determinant() to calculate the determinant of the matrix.

Declare a friend class MatrixHelper that includes a function to update a specific element of the matrix.

Overload the stream insertion operator (<<) so that the matrix can be printed in a formatted manner (for example, two rows).

Develop a main function to instantiate matrix objects, perform operations, compute the determinant, and demonstrate updating a matrix element.*/
#include <iostream>
//without any iomnip
using namespace std;
class Matrix2x2 {
private:
    int a,b,c,d; 
public:
    Matrix2x2(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}
    Matrix2x2 operator+(Matrix2x2 m){
        return Matrix2x2(a+m.a,b+m.b,c+m.c,d+m.d);
    }
    Matrix2x2 operator-(Matrix2x2 m){
        return Matrix2x2(a-m.a,b-m.b,c-m.c,d-m.d);
    }
    Matrix2x2 operator*(Matrix2x2 m){
        return Matrix2x2(a*m.a+b*m.c,a*m.b+b*m.d,c*m.a+d*m.c,c*m.b+d*m.d);
    }
    friend int determinant(Matrix2x2 m){
        return (m.a*m.d)-(m.b*m.c);
    }
    friend class MatrixHelper; 
    friend ostream& operator<<(ostream& obj,Matrix2x2 m){
        obj<<"\n\t["<<m.a<<","<<m.b<<"]\n\t["<<m.c<<","<<m.d<<"]";
        return obj;
    }
};
class MatrixHelper{
public:
    void updateElement(Matrix2x2 &m, int row, int col, int value) {
        if (row == 1 && col == 1) m.a = value;
        else if (row == 1 && col == 2) m.b = value;
        else if (row == 2 && col == 1) m.c = value;
        else if (row == 2 && col == 2) m.d = value;
        else cout << "Invalid position!" << endl;
    }

};
int main(){
    Matrix2x2 m1(1,2,3,4),m2(5,6,7,8);
    Matrix2x2 m3=m1+m2;
    Matrix2x2 m4=m1-m2;
    Matrix2x2 m5=m1*m2;
    int det=determinant(m1);
    cout<<"m1: "<<m1<<endl;
    cout<<"m2: "<<m2<<endl;
    cout<<"m1+m2: "<<m3<<endl;
    cout<<"m1-m2: "<<m4<<endl;
    cout<<"m1*m2: "<<m5<<endl;
    cout<<"Determinant of m1: "<<det<<endl;
    
    MatrixHelper helper;
    helper.updateElement(m1, 1, 1, 10); // Update element at (1, 1) to 10
    cout << "Updated m1: " << m1 << endl; // Display updated matrix

    return 0;
}
