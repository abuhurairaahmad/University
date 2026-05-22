#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    
    cout << "Length of the string: " << str.length() << endl;
    
    ofstream outFile("string.txt");
    if (outFile.is_open()) {
        outFile << str;
        outFile.close();
    }
    
    ifstream inFile("string.txt");
    if (inFile.is_open()) {
        getline(inFile, str);
        cout << "Stored string: " << str << endl;
        inFile.close();
    }
    
    return 0;
}

// Write a program to implement I/O operations on characters. I/O operations includes
// inputting a string, calculating length of the string, Storing the String in a file and fetch
// the stored characters from it.