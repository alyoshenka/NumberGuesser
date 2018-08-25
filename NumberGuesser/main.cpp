#include <iostream>
using namespace std;

// This function checks if the user cheated
// Using binary search algorithm from
// http://appinventor.cs.trincoll.edu/csp/webapps/search/binarysearch.html
int testForCheater(int minVal, int maxVal) {
	// total tries = log(sub)2 (total numbers)
	// test case: log2 64 = 6
	// needs to round up ex. 6.5 -> 7
	int num = ceil(log2(maxVal - minVal + 1));
	return num;
}

int binarySearch(int minVal, int maxVal) {

	int tryNum = 1;
	int cheatNum = testForCheater(minVal, maxVal);

	cout << "Choose a number between " << minVal << " and " << 
		maxVal << " (inclusive)." << endl;
	cout << "Hit enter when ready." << endl;

	// MAKE DEPENDANT
	int arr[100] = {};

	// populate array
	for (int i = minVal; i <= maxVal; i++) {
		// so it starts at idx 0
		arr[i - 1] = i;
	}

	// initialize
	int middle = (minVal + maxVal) / 2;

	while (minVal <= maxVal) {

		// check if it is the number
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
		if (check == 'y') {
			tooHigh = true;
		}

		// else
		if (! tooHigh) {
			minVal = middle + 1;
		}
		else {
			maxVal = middle - 1;
		}

		// update
		middle = (minVal + maxVal) / 2;
		tryNum++;
		// if they cheated
		if (tryNum > cheatNum) {
			cout << "It should have only taken me " << cheatNum << " tries to guess you number." << endl;
			cout << "It is try number " << tryNum << "." << endl;
			return 0;
		}
	}
}

// Main application function
int main() {

	int minVal = 1;
	int maxVal = 100;

	int tryCount = binarySearch(minVal, maxVal);

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