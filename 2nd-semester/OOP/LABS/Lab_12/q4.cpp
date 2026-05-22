

// Take a class Participant having three attributes (ID, name and score) and following
// member functions.
//  Input () function takes data of the object and stores it in a file name participant.dat
//  Output () function takes id from user and show respective data of that id.
//  Max () gives the highest score of the Participant in the file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <limits>

using namespace std;

// Participant class: plain-old-data layout so we can write/read objects directly
class Participant {
public:
	int id;            // participant ID
	char name[50];     // participant name (fixed-size C-string)
	int score;         // participant score

	Participant() { id = 0; name[0] = '\0'; score = 0; }

	// Input(): read data from user and append to file "participant.dat"
	void Input() {
		// Read ID
		cout << "Enter ID: ";
		while (!(cin >> id)) {
			cout << "Invalid input. Enter numeric ID: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

		// Read name (allow spaces)
		string tempName;
		cout << "Enter name: ";
		getline(cin, tempName);
		strncpy(name, tempName.c_str(), sizeof(name) - 1);
		name[sizeof(name) - 1] = '\0';

		// Read score
		cout << "Enter score: ";
		while (!(cin >> score)) {
			cout << "Invalid input. Enter numeric score: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		// Append this object to the binary file
		ofstream ofs("participant.dat", ios::binary | ios::app);
		if (!ofs) {
			cerr << "Error: could not open participant.dat for writing.\n";
			return;
		}
		ofs.write(reinterpret_cast<char*>(this), sizeof(*this));
		ofs.close();
		cout << "Record saved.\n";
	}

	// Output(): asks user for an ID and prints the matching record (if any)
	void Output() {
		int searchId;
		cout << "Enter ID to search: ";
		while (!(cin >> searchId)) {
			cout << "Invalid input. Enter numeric ID: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		ifstream ifs("participant.dat", ios::binary);
		if (!ifs) {
			cerr << "Error: could not open participant.dat for reading.\n";
			return;
		}

		Participant p;
		bool found = false;
		// Read each Participant object and compare IDs
		while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p))) {
			if (p.id == searchId) {
				cout << "Record found:\n";
				cout << left << setw(10) << "ID" << ": " << p.id << '\n';
				cout << left << setw(10) << "Name" << ": " << p.name << '\n';
				cout << left << setw(10) << "Score" << ": " << p.score << '\n';
				found = true;
				break; // stop after first match
			}
		}
		if (!found) cout << "No participant with ID " << searchId << " found.\n";
		ifs.close();
	}

	// Max(): finds and displays the participant with the highest score
	void Max() {
		ifstream ifs("participant.dat", ios::binary);
		if (!ifs) {
			cerr << "Error: could not open participant.dat for reading.\n";
			return;
		}

		Participant p;
		bool any = false;
		Participant best;
		int maxScore = numeric_limits<int>::min();

		while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p))) {
			if (!any || p.score > maxScore) {
				best = p;
				maxScore = p.score;
				any = true;
			}
		}

		if (!any) {
			cout << "No records in file.\n";
		} else {
			cout << "Highest score:\n";
			cout << left << setw(10) << "ID" << ": " << best.id << '\n';
			cout << left << setw(10) << "Name" << ": " << best.name << '\n';
			cout << left << setw(10) << "Score" << ": " << best.score << '\n';
		}
		ifs.close();
	}
};

// Simple interactive menu to demonstrate the class usage
int main() {
	Participant p; // we'll reuse this object to call member functions

	cout << "Participant Manager - store records in participant.dat\n";
	cout << "(Records are stored as binary objects for simplicity.)\n\n";

	while (true) {
		cout << "Menu:\n";
		cout << "1. Add participant\n";
		cout << "2. Show participant by ID\n";
		cout << "3. Show participant with max score\n";
		cout << "4. Exit\n";
		cout << "Choose an option: ";

		int choice;
		if (!(cin >> choice)) {
			cout << "Invalid input. Please enter a number between 1 and 4.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline before next getline

		switch (choice) {
			case 1: {
				int n = 1;
				cout << "How many participants to add? ";
				if (!(cin >> n)) { n = 1; cin.clear(); }
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				for (int i = 0; i < n; ++i) {
					cout << "\nParticipant " << (i+1) << ":\n";
					p.Input();
				}
				break;
			}
			case 2:
				p.Output();
				break;
			case 3:
				p.Max();
				break;
			case 4:
				cout << "Exiting. Goodbye!\n";
				return 0;
			default:
				cout << "Please choose a valid option (1-4).\n";
		}

		cout << "\n";
	}

	return 0;
}