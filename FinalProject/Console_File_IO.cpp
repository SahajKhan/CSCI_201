/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Khan's Calorie Tracker
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include "Console_File_IO.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <ctime>
#pragma warning(disable : 4996) //disables ctime deprecated error


/*template <typename parameter>
auto Console_IO::input(parameter min, parameter max) {
    auto userInput = min;
    std::cin >> userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    if (userInput < min || userInput > max) {
        std::cout << "Incorrect input, please try again.\n";
        return input();
    }
    return input;
}

template <typename parameter>
auto Console_IO::input(parameter min) {
    auto userInput = min
    std::cin >> userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    if (userInput < min) {
        std::cout << "Incorrect input, please try again.\n";
        return input();
    }
    return input;
}*/

/*Take input of type int from the user*/
int Console_IO::input(int min, int max) {
    int userInput;
    while (true) {
        std::cout << "Please enter a number between " << min << " and " << max << std::endl;
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        if (userInput < min || userInput> max) {
            std::cout << "Incorrect Input\n";
            throw "Incorrect Input";
        }
        else
            break;
    }
    
    return userInput;
}

/*Take input of type double from the user*/
double Console_IO::input(double min, double max) {
    std::cout << "Please enter a number between " << min << " and " << max << std::endl;
    double userInput;
    std::cin >> userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    if (userInput < min || userInput> max) {
        throw "Incorrect Input\n";
        return input(min, max);
    }

    return userInput;
}

/*Take input of type string from the user*/
std::string Console_IO::input() {
    std::string String;
    getline(std::cin, String);
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    return String;
}

/*Constructor saves all data in user credentials data file into the Map*/
File_IO::File_IO() {
    std::ifstream fin;
    std::string userName;
    std::string password;
    std::string input;

    fin.open(UserCredentials_FileName);
    while (fin >> userName >> password) {
        User_Credentials[userName] = password;
    }
    fin.close();
}

/*Input new User ID and Password into Map and .txt file*/
void File_IO::inputUserCredentials(std::string userID, std::string password) {
    User_Credentials[userID] = password;        //Save userID and password into map
    std::ofstream fout;
    fout.open(UserCredentials_FileName, std::ofstream::out | std::ofstream::app);
    fout << "\n" << userID << " " << password;
}

/*Checks to see if userName already exists*/
bool File_IO::checkUserName(std::string userID) {
    for (auto& i : User_Credentials)
        if (i.first == userID)
            return true;
    throw "Username Invalid";
    return false;
}

/*During Registration, a new file must be created for the user.*/
void File_IO::createNewUserFile(const std::string userID, Person person) {
    time_t now = time(0);              // current date/time based on current system
    std::string dt = ctime(&now);      // convert now to string form
    std::ofstream fout;                // variable for file manipulation
    fout.open(userID + ".txt");        // create new file with the userID

    /*Input all parameter data into the file*/
    fout << "Name: " << person.getName() << "\tAge: " << person.getAge() 
        << " years\tHeight: " << person.getHeight() << " cm\tGender: " << person.getGender_toString() <<"\n\n" 
        << "Date: " << dt << "\nWeight: " << person.getCurrentWeight()
        << "kg\tGoal Weight: " << person.getGoalWeight() << "kg\tMonths to Lose Weight: "
        << person.getMonthsToLoseWeight() << " months\tDaily Calorie Goal: " << person.getDailyCalories() << "kcal";
    fout.close();
}

//void File_IO::getUserFileData(const std::string userID, std::string& name, unsigned int& age,
//    unsigned int& height, std::string& gender, unsigned int& currentWeight, unsigned int& goalWeight,
//    unsigned int& monthsToLoseWeight, unsigned int& dailyCalories) {
//    try
//    {
//        if (!checkUserName(userID))
//            throw ("User Name does not exist");
//    }
//    catch (const std::exception&e)
//    {
//        std::cout << e.what() << std::endl;
//        return;
//    }
//    std::string date;
//    std::ifstream fin;
//    std::string temp; //used to skip uneeded file info
//    fin.open(userID);
//    fin >> temp >> name >> temp >> age >> temp >> height >> temp >> temp >> gender;
//    std::cout << name << age << height << gender << std::endl;
//    //while (fin >> date >> *currentWeight >> *monthsToLoseWeight >> *goalWeight >> *dailyCalories) {
//    //    //loops through the file until the last line, the last pieces of data will be gathered.
//    //}
//}

/*Update the File with parameter data*/
void File_IO::updateFileData(const std::string userID, Person& person) {
    time_t now = time(0);           // current date/time based on current system
    std::string dt = ctime(&now);  // convert now to string 
    std::ofstream fout;

    fout.open(userID+".txt", std::ofstream::out | std::ofstream::app);
    fout << "\n\n" << "Date: " << dt << "\nWeight: " << person.getCurrentWeight()
        << " Goal Weight: " << person.getGoalWeight() << " Months To Lose Weight: "
        << person.getMonthsToLoseWeight() << " Daily Calorie Goal: " << person.getDailyCalories();
}

/*Check if the password is correct for the given username*/
bool File_IO::passwordIsCorrect(const std::string userID, const std::string password) {
    if (User_Credentials[userID] == password)
        return true;
    return false;
}