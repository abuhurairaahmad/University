#include <iostream>
using namespace std;

int main(){
    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    try {
        if (password.length() < 6) {
            throw "Password must be at least 6 characters long.";
        }
        bool hasDigit = false;
        for (char c : password) {
            if (isdigit(c)) {
                hasDigit = true;
                break;
            }
        }
        if (!hasDigit) {
            throw "Password must contain at least one digit.";
        }
        cout << "Login successful!" << endl;
    } catch (const char* msg) {
        cerr << "Login failed: " << msg << endl;
    }

    return 0;
}

// Create a C++ Program to implement login. It should accept user name and password
// and throw a custom exception if the password has less than 6 characters or does not
// contain a digit.
