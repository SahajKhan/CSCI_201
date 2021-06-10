// Header
#include <iostream>
#include <string>
#include "TArray.h"
using namespace std;

int main() {

	int numPlayers;
	int value;

	cout << "Enter number of players: ";
	cin >> numPlayers;

	TArray<int> myValues(numPlayers);

	for (int i = 0; i < myValues.getSize(); i++) {
		cout << "Enter a value: ";
		cin >> value;
		myValues.set(value,i);
	}

	for (int i = 0; i < myValues.getSize(); i++) {
		cout << "value " << i << " = " <<
		myValues.get(i) << endl;
	}
	

	return 0;
}
