#include <iostream>
#include <set>
using namespace std;

int main(){
    set<string> guest;
    // Input: Prompt the user to enter the names of guests attending the party. Allow the user to continue entering names until they choose to stop.
    while (true) {
        string name;
        cout << "Enter guest name (or 'stop' to finish): ";
        getline(cin, name);
        if (name == "stop") break; // sentinel value to end input
        guest.insert(name); // store in set (automatically handles duplicates)
    }
    cout << endl;

    // Display all the unique guest names stored in the set in alphabetical order.
    cout << "Guest List (in alphabetical order):\n";
    for (const auto &name : guest) {
        cout << name << endl;
    }
    cout << endl;

    // The numeber of unique guests attending the party.
    cout << "Number of unique guests: " << guest.size() << endl;
    cout << endl;

    return 0;
}
