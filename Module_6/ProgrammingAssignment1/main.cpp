/* 
*  Program name: Player
*  Author: Sahaj Khan
*/
#include "Players.cpp"
#include <vector>
#include <limits>

int inputInt(int, int);
string inputString();
/*const string playerTypes[] = {"Offence","Defence","Special"};
	const string offenceType[] = {"Quarterback", "Wide Receiver", "Tight End", "Running Back", "Offensive Lineman"};
	const string defenceType[] = {"Defensive Lineman", "Linebacker", "Defensive Back"};
	const string specialType[] = {"Kicker", "Holer", "Punter", "Returner"};*/
int main() {
	vector<Team*> team;
	string name;
	int playerID;
	int userInputPlayerTier1, userInputPlayerTier2;
	/*Player Types*/
	const string playerType[4][5] = {{"Offence","Defence","Special"},
									 {"Quarterback", "Wide Receiver", "Tight End", "Running Back", "Offensive Lineman"},
									 {"Defensive Lineman", "Linebacker", "Defensive Back"},
									 {"Kicker", "Holder", "Punter", "Returner"}};

	Team* temp; //Used to input into team vector
	while (true) {
		cout << "Select which player would you like to create.\n";

		for (int i = 0; i < 3; i++) {
			cout << i << ": " + playerType[0][i] << endl;
		}
		userInputPlayerTier1 = inputInt(0, 2);
		cout << "Please select the type of " << playerType[0][userInputPlayerTier1] << "player\n";
		for (int i = 0; i < sizeof(playerType[0]) / sizeof(playerType[0][0]); i++) {
			cout << i << ": " + playerType[userInputPlayerTier1+1][i] << endl;
		}
		if (userInputPlayerTier1 == 0)
			userInputPlayerTier2 = inputInt(0, 4);
		if (userInputPlayerTier1 == 1)
			userInputPlayerTier2 = inputInt(0, 2);
		if (userInputPlayerTier1 == 2)
			userInputPlayerTier2 = inputInt(0, 3);

		cout << "What is the name of the player?\n";
		name = inputString();
		cout << "Input the player's ID\n";
		playerID = inputInt(0, 99);


		if (userInputPlayerTier1 == 1) {
			switch (userInputPlayerTier2) {
			case 1:
				/*QuarterBack* qb = new QuarterBack;
				qb->setName(name);
				qb->setPlayerID(playerID);
				temp = qb;*/
				temp = new QuarterBack(name, playerID);
				break;
			case 2:
				temp = new WideReceiver(name, playerID);
				break;
			case 3:
				temp = new TightEnd(name, playerID);
				break;
			case 4:
				temp = new RunningBack(name, playerID);
				break;
			case 5:
				temp = new OffensiveLineman(name, playerID);
				break;
			default:
				break;
			}
			team.push_back(temp);
		}

		//Create Defense

		if (userInputPlayerTier1 == 2) {
			switch (userInputPlayerTier2) {
			case 1:
				temp = new DefensiveLineman(name, playerID);
				break;
			case 2:
				temp = new LineBacker(name, playerID);
				break;
			case 3:
				temp = new DefensiveBack(name, playerID);
				break;
			default:
				break;
			}
			team.push_back(temp);
		}

		//Create specail players
		if (userInputPlayerTier1 == 3) {
			switch (userInputPlayerTier2) {
			case 1:
				temp = new Kicker(name, playerID);
				break;
			case 2:
				temp = new Holder(name, playerID);
				break;
			case 3:
				temp = new Punter(name, playerID);
				break;
			case 4:
				temp = new Returner(name, playerID);
				break;
			default:
				break;
			}
			team.push_back(temp);
		}
	}

	return 0;
}

int inputInt(int min, int max) {
	int input;
	while (true) {
		cout << "Enter a number from " << min << " to " << max << endl;
		cin >> input;
		/*Error Checking*/
		if (!cin) {
			cout << "Please enter a number\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (input < min || input  > max) {
			cout << "Enter a number from " << min << " to " << max << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	cin.clear();
	return input;
}

string inputString() {
	string input;
	cin >> input;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}
