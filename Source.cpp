#include <iostream>
#include <string>
#include "HashMapTable.h"


int main() {
	HashMapTable hash;
	int k;
	string v;
	int c;

	while (1) {
		cout << "\n" << endl;
		cout << "1. Add a new entry to the Phone Book" << endl;
		cout << "2. Find an entry in the Phone Book" << endl;
		cout << "3. Close the Phone Book" << endl;
		cout << "\n\tYou: ";
		cin >> c;

		switch (c) {
		case 1:
			// Get user input
			cout << "\nName: ";
			cin >> v;
			cout << "Phone #: ";
			cin >> k;

			hash.Insert(k, v);  // Hash result

			break;

		case 2:
			// Get user input
			cout << "\nPhone Number to Lookup: ";
			cin >> k;

			hash.Retrieve(k);  // Hash result

			break;

		case 3:
			exit(1);

		default:
			cout << "\nError! Please try again! (#1-3)\n" << endl;
		}
	}

	return 0;
}