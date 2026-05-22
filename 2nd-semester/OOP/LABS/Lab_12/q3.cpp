#include <iostream>
#include <fstream>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person (string n, int a) : name(n), age(a) {}
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person person1("Ali", 25);
    ofstream outFile("person.bin", ios::binary);
    if (outFile.is_open()) {
        outFile.write((char*)&person1, sizeof(person1));
        outFile.close();
    }

    // Now we will read the object back from the file
    Person person2("", 0); // Create an empty object to read into
    ifstream inFile("person.bin", ios::binary);
    if (inFile.is_open()) {
        inFile.read((char*)&person2, sizeof(person2));
        inFile.close();
    }
    person2.display(); // Display the read object

    return 0;
}

// Take a class Person having two attributes name and age. Include a parametrized
// constructor to give values to all data members. In main function Create an instance
// of the person class and name it person1. Create a binary file person.bin and write
// person1 object into it. Read the person1 object from the file.