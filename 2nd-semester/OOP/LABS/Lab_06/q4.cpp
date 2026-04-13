#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string occupation;

public:
    Person(string _occupation) {
        occupation = _occupation;
    }

    // Virtual function to allow overriding in derived classes
    virtual void Draw() {
        cout << "A person can draw in many ways" << endl;
    }
};

class Artist : public Person {
public:
    // Passes "artist" to the base class constructor
    Artist() : Person("artist") {}

    void Draw() override {
        cout << "An artist can draw with a paint brush" << endl;
    }
};

class Gunman : public Person {
public:
    // Passes "gunman" to the base class constructor
    Gunman() : Person("gunman") {}

    void Draw() override {
        cout << "A gunman draws a gun to shoot" << endl;
    }
};

int main() {
    // Array of pointers of type Person
    Person* people[3];

    // Dynamically creating objects
    people[0] = new Person("none"); 
    people[1] = new Artist();
    people[2] = new Gunman();

    // Calling Draw function for each object
    for (int i = 0; i < 3; i++) {
        people[i]->Draw();
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < 3; i++) {
        delete people[i];
    }

    return 0;
}

// Create the classes following the diagram given below. Keep the following things
// in mind:
// - When an object of Artist is created, the value “artist” will be set to occupation.
// - When an object of Gunman is created, the value “gunman” will be set to
// occupation.
// - Person::Draw() will print out “A person can draw in many ways”
// - Artist::Draw()willprint out “An artist can drawwith a paint brush”
// - Gunman::Draw() will print out “A gunman draws a gun to shoot”
// - Write a test code by creating an array of pointers of type Person. Dynamically create
// objects of each class and store address in the array. After that call Draw function for each
// object.