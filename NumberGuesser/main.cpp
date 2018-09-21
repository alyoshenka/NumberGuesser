#include <iostream>
using namespace std;

// To Do
// Multiple letters input > carryover to next input check

// cin.clear();
// cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


// This function implments the binary search algorithm to
// guess a number chosen by the user.
int binarySearch(int minVal, int maxVal) {

	// number of tries
	int tryNum = 1;

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

	// debugging
	minVal--;

	// initialize
	int middle = (minVal + maxVal) / 2;

	// while the binary search still has values left
	while (minVal <= maxVal) {

		middle = (minVal + maxVal) / 2;

		// check if it is the number
		// user input
		char check = 'a';

		// check for number
		cout << "Is " << middle << " the number? (y or n)" << endl;
		cin >> check;

		// break out of loop
		if (check == 'y') {
			cout << middle << " is your number." << endl;
			return tryNum;
		}

		// input validation
		while (check != 'n') {
			cout << "Bad input." << endl;
			cout << "Is " << middle << " the number? (y or n)" << endl;
			cin >> check;
			// break out of loop
			if (check == 'y') {
				cout << middle << " is your number." << endl;
				return tryNum;
			}
		}
		
		// check if it is too high or too low
		bool tooHigh = false;

		check = 'a';
		cout << "Is " << middle << " too high? (y or n)" << endl;
		cin >> check;
		// input validation
		while (check != 'n' && check != 'y') {
			cout << "Bad input." << endl;
			cout << "Is " << middle << " too high? (y or n)" << endl;
			cin >> check;
			// break out of loop
			if (check == 'y') {
				tooHigh = true;
			}
			else {
				// here just in case
				tooHigh = false;
			}
		}

		// else
		// if !tooHigh (if too low), go to second half
		// if tooHigh, go to first half
		if (tooHigh) {
			minVal = middle - 1;
		}
		else {
			maxVal = middle + 1;
		}

		// update
		
		tryNum++;
	}

	cout << "Due to the binary search algorithm, I should have guessed" <<
		" your number by now." << endl;
	return 0;
}

// Main application function
int main() {

	int tryCount = binarySearch(1, 100);

	if (tryCount == 0) {
		cout << "You cheated." << endl;
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