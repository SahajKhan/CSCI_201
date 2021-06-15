/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Khan's Calorie Tracker
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include "Person.h"
#include <map>




/*Input Library, these function will take input from the user and return correct value*/

class Console_IO {
public:
    std::string input();
    ////template <typename parameter>
    ////auto input(parameter min, parameter max);
    //template <typename parameter>
    //auto input(parameter min);

    int input(int min, int max);
    double input(double min, double max);

  

};

class File_IO {
private:
    const std::string UserCredentials_FileName = "User_Credentials.txt";         //File Name of file that stores user credentials
    std::map<std::string, std::string> User_Credentials;                         //Stores UserID and Passwords in a map
public:
    File_IO();
    void inputUserCredentials(std::string userID, std::string userPassword);     //Input UserID and Password into User_Credentials.txt
    bool checkUserName(std::string userID);                                      //Checks if given UserID is on file
    void createNewUserFile(const std::string userID, Person person);             //Creates a new file for the user containing user data
    void updateFileData(const std::string userID, Person& person);               //Updates the user's file with new data
    bool passwordIsCorrect(const std::string userID, const std::string password);//Checks to see if password matches the UserID
    void getUserFileData(const std::string userID, std::string& name,            //Grab data from User file and set into parameter
        unsigned int& age, unsigned int& height, std::string& gender,
        unsigned int& currentWeight, unsigned int& goalWeight,
        unsigned int& monthsToLoseWeight, unsigned int& dailyCalories);
};