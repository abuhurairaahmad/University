#include <iostream>
#include <map>
using namespace std;

int getGrade(const map<string, int> &student, const string &name) {
    auto it = student.find(name);
    if (it != student.end()) {
        return it->second; // return the grade
    } else {
        throw "Student not found"; // throw an exception if student is not in the map
    }
}

void updateGrade(map<string, int> &student, const string &name, int newGrade) {
    auto it = student.find(name);
    if (it != student.end()) {
        it->second = newGrade; // update the grade
    } else {
        throw "Student not found"; // throw an exception if student is not in the map
    }
}

void displayEverything(const map<string, int> &student) {
    cout << "Student Grades:\n";
    for (const auto &entry : student) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

void removeStudent(map<string, int> &student, const string &name) {
    auto it = student.find(name);
    if (it != student.end()) {
        student.erase(it); // remove the student from the map
    } else {
        throw "Student not found"; // throw an exception if student is not in the map
    }
}




int main(){
    map<string, int> student;
    // Input: Prompt the user to enter the names and grades of multiple students. Allow the user to
    // continue entering data until they choose to stop.
    while (true) {
        string name;
        int grade;
        cout << "Enter student name (or 'stop' to finish): ";
        getline(cin, name);
        if (name == "stop") break; // sentinel value to end input
        cout << "Enter grade for " << name << ": ";
        cin >> grade;
        cin.ignore(); // clear newline from input buffer
        student[name] = grade; // store in map
    }
    cout << endl;

    cout << "Enter the student name of which you want to find the grade of: " << endl;
    string searchName;
    getline(cin, searchName);
    try {
        int grade = getGrade(student, searchName);
        cout << "Grade for " << searchName << ": " << grade << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    cout << endl;

    cout << "Enter the name of the student you want to remove: " << endl;
    string removeName;
    getline(cin, removeName);
    try {
        removeStudent(student, removeName);
        cout << "Student removed: " << removeName << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    cout << endl;

    cout << "Enter the name of the student of which grade you want to update: " << endl;
    string updateName;
    getline(cin, updateName);
    cout << "Enter the new grade for " << updateName << ": ";
    int newGrade;
    cin >> newGrade;
    try {
        updateGrade(student, updateName, newGrade);
        cout << "Grade updated for " << updateName << ": " << newGrade << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    cout << endl;
    
    displayEverything(student); // Display all student grades
    return 0;
}
