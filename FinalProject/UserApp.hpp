/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Khan's Calorie Tracker
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include "Console_File_IO.h"
#include <iostream>
#include "Person.h"


/*Application class, used to track user information and interact with user via the terminal*/
class Application: public Person{
public:
	/*Register a new user*/
	void registerID() {
		Console_IO c_in;
		File_IO f_in;
		std::string userID;
		std::string password;

		std::cout << "Please enter your name below\n";
		name = c_in.input();

		std::cout << "Please enter your age below\n";
		age = c_in.input(14, 80);

		std::cout << "Enter a User ID, this will be required to login each time\n";
		userID = c_in.input();
		
		/*Check to see if UserID already exists, if so try again in a loop*/
		while (f_in.checkUserName(userID)) {
			std::cout << "This User ID is taken, please enter another one.\n";
			userID = c_in.input();
		}
		
		std::cout << "Enter your password, this will be required with the User ID to login each time.\n";
		password = c_in.input();

		std::cout << "Enter your weight in kg\n";
		currentWeight = c_in.input(0,250);
		
		std::cout << "Enter your height in cm\n";
		height = c_in.input(0, 300);

		std::cout << "How much would you like to weigh after dieting?\n";
		goalWeight = c_in.input(0, currentWeight);

		std::cout << "In how many months would you like to lose this weight?\n";
		monthsToLoseWeight = c_in.input(0, 60);

		std::cout << "What is your gender?\n";
		std::cout << "1: Male\n2: Female\n";
		gender = static_cast<GENDER> (c_in.input(1, 2));	//Input int from user and cast into Gender
		
		std::cout << "What is your activity level?\n";
		std::cout << "1: LITTLE\n2: LIGHT\n3: MODERATE\n4: VERY\n5: EXTRA\n";
		exerciseLevel = static_cast<ExerciseLevel> (c_in.input(1, 5));
		
		weightToLose = currentWeight - goalWeight;
		f_in.inputUserCredentials(userID, password);

		dailyCalories = calculateDailyCalories();

		Application app;
		app.name = name;
		app.age = age;
		app.height = height;
		app.gender = gender;
		app.currentWeight = currentWeight;
		app.monthsToLoseWeight = monthsToLoseWeight;
		app.goalWeight = goalWeight;
		app.dailyCalories = dailyCalories;
		app.weightToLose = weightToLose;

		f_in.createNewUserFile(userID, app);
		std::cout << "Your current Calories per day has been set to: " << dailyCalories << std::endl;
	}

	/*User can login through here*/
	bool login(std::string userID, std::string password) {
		File_IO f_in;

		if (!f_in.checkUserName(userID)) {
			std::cout << "UserID is not on record.\n";
			return false;
		}

		if (!f_in.passwordIsCorrect(userID, password)) {
			std::cout << "The password is incorrect\n";
			return false;
		}

		/*Once error checking passes, get data from file*/
		/*std::string tempGender;
		f_in.getUserFileData(userID, name, age, height, tempGender, currentWeight, goalWeight, monthsToLoseWeight, dailyCalories);
		if (tempGender == "Male")
			gender = MALE;
		else if (tempGender == "Female")
			gender = FEMALE;
		else 
			throw("Gender not within criteria.\n");

		return true;*/
	}


	/*Calculate HBF, formula provided by https://www.diabetes.co.uk/bmr-calculator.html*/
	int calculateHBF() {
		double bmr;
		try {
			/*first calculate BMR*/
			if (gender == MALE) {
				bmr = (6.67 + (13.72 * (double)currentWeight) + (5.003 * (double)height) - (6.755 * age));
			}
			else if (gender == FEMALE) {
				bmr = (655.1 + (9.563 * currentWeight) + (1.85 * height) - (4.676 * age));
			}
			else
				throw("Gender not specified");
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		/*Calculate Harris Benedict Formula using BMR and return*/
		switch (exerciseLevel) {
		case 1: return (int)(bmr * 1.2);
		case 2:	return (int)(bmr * 1.375);
		case 3:	return (int)(bmr * 1.55);
		case 4: return (int)(bmr * 1.725);
		case 5: return (int)(bmr * 1.9);
		default: break;
		}
	}

	int calculateDailyCalories() {
		int totalCaloriesToLose = weightToLose * 7700;
		int caloriesToLosePerMonth = totalCaloriesToLose / monthsToLoseWeight;
		int caloriesToLosePerDay =  caloriesToLosePerMonth / 30;
		return calculateHBF() - caloriesToLosePerDay;
	}

	/*Print data to console*/
	void print() {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "Current Weight: " << currentWeight << std::endl;
		std::cout << "Months to Lose Weight: " << monthsToLoseWeight << std::endl;
		std::cout << "Goal Weight: " << goalWeight<< std::endl;
		std::cout << "Exercise Level: " << getExerciseLevel_toString() << std::endl;
		std::cout << "Daily Caloric Limit: " << getDailyCalories() << std::endl;
	}

	/*For returning users, this will update the data and add to the chart*/
	void updateUserInfo(std::string userID, std::string password) {
		File_IO f_in;
		Console_IO c_in;

		std::cout << "Please enter your age below\n";
		age = c_in.input(14, 80);

		std::cout << "Enter your weight in kg\n";
		currentWeight = c_in.input(0, 250);

		std::cout << "Enter your height in cm\n";
		height = c_in.input(0, 300);

		std::cout << "How much would you like to weigh after dieting?\n";
		goalWeight = c_in.input(0, currentWeight);

		std::cout << "In how many months would you like to lose this weight?\n";
		monthsToLoseWeight = c_in.input(0, 60);

		std::cout << "What is your gender?\n";
		std::cout << "1: Male\n2: Female\n";
		gender = static_cast<GENDER> (c_in.input(1, 2));	//Input int from user and cast into Gender

		std::cout << "What is your activity level?\n";
		std::cout << "1: LITTLE\n2: LIGHT\n3: MODERATE\n4: VERY\n5: EXTRA\n";
		exerciseLevel = static_cast<ExerciseLevel> (c_in.input(1, 5));

		weightToLose = currentWeight - goalWeight;
		f_in.inputUserCredentials(userID, password);

		dailyCalories = calculateDailyCalories();

		Application app;
		app.age = age;
		app.height = height;
		app.gender = gender;
		app.currentWeight = currentWeight;
		app.monthsToLoseWeight = monthsToLoseWeight;
		app.goalWeight = goalWeight;
		app.dailyCalories = dailyCalories;
		app.weightToLose = weightToLose;

		dailyCalories = calculateDailyCalories();
		f_in.updateFileData(userID, app);
	}

	//operater overloading
	friend std::ostream &operator<<(std::ostream& output,  Application& app);
};

/*Overload the << operator, useful to display Player and App data*/
std::ostream& operator<<(std::ostream& output,  Application& app) {
	app.print();
	return output;
}