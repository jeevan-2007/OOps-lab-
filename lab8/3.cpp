/*
In many graphical and physics applications, 2D vectors are used to represent directions, velocities, and forces. In this task, a class Vector2D that encapsulates a vector’s x and y components is to be developed using appropriate operator overloading methods. The class should support scalar operations such as addition, subtraction, and multiplication (scaling). In addition, you will provide a friend function to calculate the dot product between two vectors. Another function will be implemented to find the magnitude (length) of a vector. The goal is to create a flexible class with overloading and a friend function to access the private data directly.

Requirements:

Create a class Vector2D with private data members for the x and y coordinates.

Overload the +, -, and * operators to allow vector addition and scaling.

Overload the stream insertion operator (<<) to support outputting a vector.

Define a friend function dotProduct() to compute the dot product between two vectors.

Define another function magnitude() to get the vector length.

Write a main function to create sample vectors, perform operations, and print the results.
*/
#include <iostream>
#include <cmath>
using namespace std;
class Vector2D {
private:
    double x, y;
public:
    Vector2D(double x=0,double y=0):x(x),y(y){}
    Vector2D operator+(const Vector2D& v) const {
        return Vector2D(x + v.x, y + v.y);
    }
    Vector2D operator-(const Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }
    friend double dotProduct(const Vector2D& v1, const Vector2D& v2) {
        return (v1.x * v2.x + v1.y * v2.y);
    }
    friend double magnitude(const Vector2D& v) {
        return sqrt(v.x * v.x + v.y * v.y);
    }
    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

};
int main(){
    Vector2D v1(3, 4), v2(1, 2);
    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;
    Vector2D v5 = v1 * 2.0;
    double dot = dotProduct(v1, v2);
    double magV1 = magnitude(v1);
    double magV2 = magnitude(v2);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v1 + v2: " << v3 << endl;
    cout << "v1 - v2: " << v4 << endl;
    cout << "v1 * 2.0: " << v5 << endl;
    cout << "Dot Product of v1 and v2: " << dot << endl;
    cout << "Magnitude of v1: " << magV1 << endl;
    cout << "Magnitude of v2: " << magV2 << endl;

    return 0;
}