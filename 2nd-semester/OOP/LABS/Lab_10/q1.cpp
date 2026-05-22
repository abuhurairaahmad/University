#include <iostream>
using namespace std;

template <typename T>
class Calculator {
private:
    T num1, num2;
public:
    Calculator(T n1, T n2) : num1(n1), num2(n2) {}

    T add() {
        return num1 + num2;
    }

    T subtract() {
        return num1 - num2;
    }

    T multiply() {
        return num1 * num2;
    }

    T divide() {
        return num1 / num2;
    }
};

int main(){
    Calculator<int> calc(3, 2);
    cout << "int calculator:" << endl;
    cout << "The value of a is " << 3 << " and the value of b is " << 2 << endl;
    cout << "Add: " << calc.add() << endl;
    cout << "Subtract: " << calc.subtract() << endl;
    cout << "Multiply: " << calc.multiply() << endl;
    cout << "Divide: " << calc.divide() << endl;

    Calculator<double> calc2(3.5, 2.5);
    cout << "\ndouble calculator:" << endl;
    cout << "The value of a is " << 3.5 << " and the value of b is " << 2.5 << endl;
    cout << "Add: " << calc2.add() << endl;
    cout << "Subtract: " << calc2.subtract() << endl;
    cout << "Multiply: " << calc2.multiply() << endl;
    cout << "Divide: " << calc2.divide() << endl;

     Calculator<float> calc3(3.5f, 2.5f);
    cout << "\nfloat calculator:" << endl;
    cout << "The value of a is " << 3.5f << " and the value of b is " << 2.5f << endl;
    cout << "Add: " << calc3.add() << endl;
    cout << "Subtract: " << calc3.subtract() << endl;
    cout << "Multiply: " << calc3.multiply() << endl;
    cout << "Divide: " << calc3.divide() << endl;


    return 0;
}

// Create a C++ Program to add, subtract, multiply and divide two numbers using class
// template. Two numbers can be of the same datatype or combination of different
// data types.