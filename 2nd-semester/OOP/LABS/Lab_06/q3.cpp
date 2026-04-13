#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    double x, y;
public:
    Vector(double x_val, double y_val) : x(x_val), y(y_val) {}
    Vector operator +(const Vector& Obj) {
        Vector temp(0, 0);
        temp.x = x + Obj.x;
        temp.y = y + Obj.y;
        return temp;
    }
    Vector operator -(const Vector& Obj) {
        Vector temp(0, 0);
        temp.x = x - Obj.x;
        temp.y = y - Obj.y;
        return temp;
    }
    Vector operator *(double scalar) {
        Vector temp(0, 0);
        temp.x = x * scalar;
        temp.y = y * scalar;
        return temp;
    }
    Vector operator /(double scalar) {
        Vector temp(0, 0);
        temp.x = x / scalar;
        temp.y = y / scalar;
        return temp;
    }
    double magnitude() {
        return sqrt(x * x + y * y);
    }
    void display() {
        cout << "Vector(" << x << "i, " << y << "j)" << endl;
    }

};

int main() {
    Vector v1(3.0, 4.0);
    Vector v2(1.0, 2.0);
    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    Vector v5 = v1 * 2.0;
    Vector v6 = v1 / 2.0;

    cout << "v1: "; v1.display();
    cout << "v2: "; v2.display();
    cout << "v1 + v2: "; v3.display();
    cout << "v1 - v2: "; v4.display();
    cout << "v1 * 2: "; v5.display();
    cout << "v1 / 2: "; v6.display();
    cout << "Magnitude of v1: " << v1.magnitude() << endl;

    return 0;
}

// Create a class called Vector which represents a two-dimensional vector with x and
// y components. The class should have the following member functions:
// - A constructor that initializes the x and y components of the vector.
// - An overloaded operator + that adds two Vector objects and returns a new Vector
// object.
// - An overloaded operator - that subtracts two Vector objects and returns a new Vector
// object.
// Sample run
// This is Display() method of DerivedClass
// This is Show() method of BaseClass
// cout << "\nThis is Display( ) method of DerivedClass";
// }
// };
// // Driver code
// int main( ){
// DerivedClass dr;
// BaseClass &bs = dr;
// bs.Display( );
// dr.Show( );
// }
// 6 Object Oriented Programming (CT-260) Lab 06
// - An overloaded operator * that multiplies a Vector object by a scalar value and returns a
// new Vector object.
// - An overloaded operator / that divides a Vector object by a scalar value and returns a
// new Vector object.
// - A member function magnitude that returns the magnitude of the vector.
// In the main function, create two Vector objects and demonstrate the use of all the
// overloaded operators.