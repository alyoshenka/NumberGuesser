#include <iostream>
using namespace std;

// To Do
// Multiple letters input > carryover to next input check

 //cin.clear();
 //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


// This function implments the binary search algorithm to
// guess a number chosen by the user.
int binarySearch(int minVal, int maxVal) {
	int tryCount = 1;

	// initial prompt
	cout << "Choose a number between " << minVal << " and " <<
		maxVal << " (inclusive)." << endl;
	cout << "Hit enter when ready." << endl;

	// Ultimately, this would be dependant
	int arr[100] = {};

	// populate array
	for (int i = minVal; i <= maxVal; i++) {
		// so it starts at idx 0
		arr[i - 1] = i;
	}

	bool tooHigh = false;
	int middle = -1;
	char check = 'a';

	while (minVal <= maxVal) {

		middle = floor((minVal + maxVal) / 2);
		// check if it is the number
		// user input
		check = 'a';

		// check for number
		cout << "Is " << middle << " the number? (y or n)" << endl;
		cin >> check;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// break out of loop
		if (check == 'y') {
			cout << middle << " is your number." << endl;
			return tryCount;
		}

		// input validation
		while (check != 'n') {
			cout << "Bad input." << endl;
			cout << "Is " << middle << " the number? (y or n)" << endl;
			cin >> check;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// break out of loop
			if (check == 'y') {
				cout << middle << " is your number." << endl;
				return tryCount;
			}
		}

		// check if it is too high or too low
		tooHigh = false;
		check = 'a';
		cout << "Is " << middle << " too high? (y or n)" << endl;
		cin >> check;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (check == 'y') {
			tooHigh = true;
		}
		else {
			// here just in case
			tooHigh = false;
		}
		// input validation
		while (check != 'n' && check != 'y') {
			cout << "Bad input." << endl;
			cout << "Is " << middle << " too high? (y or n)" << endl;
			cin >> check;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// break out of loop
			if (check == 'y') {
				tooHigh = true;
			}
			else {
				// here just in case
				tooHigh = false;
			}
		}

		if (tooHigh) {
			maxVal = middle - 1;
		}
		else {
			minVal = middle + 1;
		}
		tryCount++;
	}
	return 0;
}

// Main application function
int main() {

	int tryCount = binarySearch(1, 100);

	if (tryCount == 0) {
		cout << "You cheated." << endl;
		cout << "Goodbye" << endl;
	} else if (tryCount == 1) {
		cout << "It took me " << tryCount <<
			" try to guess your number." << endl;
	} else {
		cout << "It took me " << tryCount <<
			" tries to guess your number." << endl;
	}

	system("pause");
	return 0;
}