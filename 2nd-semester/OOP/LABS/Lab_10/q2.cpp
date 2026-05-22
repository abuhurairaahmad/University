#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
void swap(T1 &a, T2 &b) {
    T1 temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 5, y = 10;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;

    string st1 = "Hello", st2 = "World";
    cout << "\nBefore swapping: st1 = " << st1 << ", st2 = " << st2 << endl;
    swap(st1, st2);
    cout << "After swapping: st1 = " << st1 << ", st2 = " << st2 << endl;

     double d1 = 3.14, d2 = 2.71;
    cout << "\nBefore swapping: d1 = " << d1 << ", d2 = " << d2 << endl;
    swap(d1, d2);
    cout << "After swapping: d1 = " << d1 << ", d2 = " << d2 << endl;

    float f1 = 1.5f, f2 = 2.5f;
    cout << "\nBefore swapping: f1 = " << f1 << ", f2 = " << f2 << endl;
    swap(f1, f2);
    cout << "After swapping: f1 = " << f1 << ", f2 = " << f2 << endl;

    return 0;
}


// Create a C++ Program to swap the data using template function, instead of calling a
// function by passing a value, use call by reference, Two numbers can be of same
// datatype or combination of different data types.