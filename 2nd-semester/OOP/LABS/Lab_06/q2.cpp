#include <iostream>
using namespace std;

class Calculator {
private:
    double Num1, Num2, Num3;

public:
    Calculator(double n1, double n2, double n3) {
        Num1 = n1;
        Num2 = n2;
        Num3 = n3;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(double a, double b, double c) {
        return a + b + c;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double multiply(double a, double b, double c) {
        return a * b * c;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double divide(double a, double b) {
        return a / b;
    }
};

int main() {
    double n1, n2, n3;
    cout << "Enter num1: ";
    cin >> n1;
    cout << "Enter num2: ";
    cin >> n2;
    cout << "Enter num3: ";
    cin >> n3;
    Calculator calc(n1, n2, n3);

    cout << "Addition (2 inputs): " << calc.add(n1, n2) << endl;
    cout << "Addition (3 inputs): " << calc.add(n1, n2, n3) << endl;
    cout << "Multiplication (2 inputs): " << calc.multiply(n1, n2) << endl;
    cout << "Multiplication (3 inputs): " << calc.multiply(n1, n2, n3) << endl;
    cout << "Subtraction: " << calc.subtract(n1, n2) << endl;
    cout << "Division: " << calc.divide(n1, n2) << endl;

    return 0;
}

// 1. Create a class called Calculator that has three private member variables Num1,
// Num2, Num3. In this class, you have to overload the functions for addition and
// multiplication such that they take two and three inputs respectively. You also have
// to make methods for subtraction and division. For example: add(1,2) and
// add(1,2,3) similarly for multiply, it would be multiply(1,2) and multiply(1,2,3). You
// may ask the user for input at the time of object creation. Afterwards just
// demonstrate how the functions are being called.c