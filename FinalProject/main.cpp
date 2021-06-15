/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Khan's Calorie Tracker
 Instructor:	Kristopher Roberts
 *************************************************/
#include "UserApp.hpp"
#include "Console_File_IO.h"

using namespace std;

int main() {
	Console_IO c_in;
	Application app;
	std::string userInputString, userID, password;
	int userInputInt;

	try {

		std::cout << "Welcome, if you have an account please enter \"1\".\n";
		std::cout << "If you would like to create an account, enter \"2\".\n";
		std::cout << "If you would like to quit the program, enter \"3\".\n";

		userInputInt = c_in.input(1, 3);
		if (userInputInt == 3) {
			return 0;
		}
		if (userInputInt == 2) {
			app.registerID();
			std::cout << "Registration Complete!\n";
			//std::cout << "Please login below to sign in with your new account.\n";
			std::cout << app;
			std::cout << "Your file name is " << userID << endl;
			std::cout << "Please view your information and follow caloric limits accordingly.\n";
			return 0;
		}
		else {
			/*Login*/
			do {
				std::cout << "Please enter your User ID\n";
				userID = c_in.input();
				std::cout << std::endl;
				std::cout << "Please enter the password\n";
				password = c_in.input();

				if (!app.login(userID, password))
					std::cout << "Login failed, please try again.\n";
				else
					break;
			} while (true);
		}

		std::cout << "Let's update your file information.\n";
		app.updateUserInfo(userID, password);
		std::cout << app;
	}
	catch (exception& e) {
		std::cout << e.what();
	}
	return 0;
}
