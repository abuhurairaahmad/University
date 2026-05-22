#include <iostream>
using namespace std;

template <typename T>
class mycontainer {
private:
    T element;
public:
    mycontainer(T e) : element(e) {}
    T increase() {
        element++;
        return element;
    }
};

template <>
class mycontainer<char> {
private:
    char element;
public:
    mycontainer(char e) : element(e) {}
    char uppercase() {
        if (element >= 'a' && element <= 'z') {
            element = element - ('a' - 'A');  // This will give 32
            // You can convert to uppercase by subtracting 32 from a lowercase character
            return element;
        }
    }
};

int main(){
    mycontainer<int> intContainer(5);
    cout << "Integer before increase: 5" << endl;
    cout << "Integer after increase: " << intContainer.increase() << endl;

    mycontainer<double> doubleContainer(3.14);
    cout << "\nDouble before increase: 3.14" << endl;
    cout << "Double after increase: " << doubleContainer.increase() << endl;

    mycontainer<char> charContainer('b');
    cout << "\nCharacter before uppercase: 'b'" << endl;
    cout << "Character after uppercase: '" << charContainer.uppercase() << "'" << endl;

    return 0;
}



// 3. Create a C++ class called mycontainer that can store one element of any type and it
// has just one member function called increase, which increases its value. But we find
// that when it stores an element of type char it would be more convenient to have a
// completely different implementation with a function member uppercase, declare a
// class template specialization for that type.