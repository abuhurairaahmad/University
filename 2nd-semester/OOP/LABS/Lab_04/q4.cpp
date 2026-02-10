#include <iostream>
using namespace std;

int main(){
    const int max_students = 30; // max_students is a constant and cannot be changed
    int student_count = 0; // student_count can be changed

    // Example scenario: Adding students to a class
    student_count = 25; // Adding 25 students
    cout << "Current student count: " << student_count << endl;
    cout << "Maximum allowed students: " << max_students << endl;

    // max_students = 35; // This line will cause a compile-time error because max_students is a constant
    // Uncommenting the above line will cause an error

    return 0;
}

// By considering a scenario of your own choice, write a program to demonstrate the
// concept of constant keyword.
