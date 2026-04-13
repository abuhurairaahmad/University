#include <iostream>
using namespace std;

class Shape {
protected:
    int numberOfSides;
    double area;
public:
    Shape() : numberOfSides(0), area(0.0) {}
    Shape(int numberOfSides, double area) : numberOfSides(numberOfSides), area(area) {}
    // Accessors
    int getNumberOfSides() const {
        return numberOfSides;
    }
    double getArea() const {
        return area;
    }
    // Mutators
    void setNumberOfSides(int sides) {
        numberOfSides = sides;
    }
    void setArea(double shapeArea) {
        area = shapeArea;
    }
};

class Rectangle : public Shape {
protected:
    double length, width;
public:
    Rectangle(double len, double w) : length(len), width(w) {}
    void generateArea() {
        area = length * width;
    }
    
};

class Circle : public Shape {
protected:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    void generateArea() {
        area = 3.14159 * radius * radius;
    }
};

class Triangle : public Shape {
protected:
    double height, base;
public:
    Triangle(double height, double base) : height(height), base(base) {}
    void generateArea() {
        area = height * base / 2;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    bool checkSides() {
        return length == width;
    }
    void generateArea() {
        area = length * width; // Since it's a square, length and width are the same
    }
};


int main(){
    Square sq(5.0);
    cout << sq.checkSides() << endl; // Should return 1 (true)
    
    return 0;
}


// Create a class named Shape. All our shapes will be inherited from this class. It will
// contain the following data members and functions: numberOfSides, area,
// parametrized constructor, accessors and mutators for the data members.Create
// classes called Rectangle, Circle and Triangle, which are all inherited from the class
// Shape. Create a class called Square which is inherited from Rectangle. The derived
// classes will have the following members:
// Rectangle: length, width, parameterized constructor, generateArea( ) – should
// place the result in area.
// Circle: radius, parameterized constructor, generateArea( ) – should place the
// result in area
// Triangle: height, base, parameterized constructor, generateArea( ) – should place
// the result in area (Area = height*base/2)
// Square:
// - It should have a parameterized constructor that takes one side as input. The
// constructor should call the constructor for the Rectangle class with that value
// as parameters.
// - checkSides( ); - checks if both sides are equal. Sides are inherited from
// Rectangle.
// - generateArea( ) – should place the result in area
