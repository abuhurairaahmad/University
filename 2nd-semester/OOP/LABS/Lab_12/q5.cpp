#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream inFile("STORY.TXT");
    if (!inFile) {
        cerr << "Error: could not open STORY.TXT for reading.\n";
        return 1;
    }
    string line;
    int count = 0;
    while (getline(inFile, line)) {
        if (!line.empty() && line[0] != 'A' && line[0] != 'a') {
            count++;
        }
    }
    inFile.close();
    cout << "Number of lines not starting with 'A': " << count << endl;

    return 0;
}


// Write a function in C++ to count and display the number of lines not starting with
// alphabet 'A' present in a text file "STORY.TXT".
// Example: If the file "STORY.TXT" contains the following lines,
// The rose is red.
// A girl is playing there.
// There is a playground.
// An airplane is in the sky.
// Numbers are not allowed in the password.
// The function should display the output as 3.