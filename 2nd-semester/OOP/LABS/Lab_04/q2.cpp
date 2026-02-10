#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr; // Pointer to the array
    int size;  // Size of the array

public:
    // Parameterized constructor
    DynamicArray(int size) : size(size) {
        arr = new int[size]; // Dynamically allocate memory for the array
        for (int i = 0; i < size; i++) {
            arr[i] = 0; // Initialize all values to 0
        }
    }
    // Destructor to free the allocated memory
    ~DynamicArray() {
        delete[] arr;
    }
    // Member function to push value to the end of the array
    void push(int value) {
        if (size > 0) {
            arr[size - 1] = value; // Push value to the end of the array
        }
    }
    // Member function to return the size of the array
    int getSize() {
        return size;
    }
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " "; // Print the array elements
        }
        cout << endl; 

    }

};


int main(){
    DynamicArray myArray(5); // Create a DynamicArray of size 5
    myArray.push(10); // Push value 10 to the end of the array

    cout << "Size of the array: " << myArray.getSize() << endl; // Display the size of the array
    cout << "Array elements: ";
    myArray.printArray(); // Display the array elements

    
    return 0;
}

// Create a class called DynamicArray. The class should contain a pointer to the
// array, and size of the array as data members. Create the parameterized constructor
// which take size of the array as input and initializes all the values with 0. Create the
// member function “push” which takes value as parameter and push it to the end of
// the array. Create the member function size() which returns the size of the array.
