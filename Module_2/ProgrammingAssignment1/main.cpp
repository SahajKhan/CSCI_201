/* Program name: main.cpp
*  Author: Sahaj Khan
*  Date last updated: 2/7/2021
*  Purpose: Practice exceptions by entering Dates
*/
#include <iostream>
#include <string>
#include <climits>
#include "Date.h"

using namespace std;

/*Input int values and error check*/
int inputNum() {
    int input;
    while (true) {
        cin >> input;
        /*Error Checking*/
        if (!cin) {
            cout << "Please enter a number\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        break;
    }
    return input;
}

/*Check to see if user wants to continue the program or change date variables*/
bool checkChange() {
    string userContinue;
    while (true) {
        cout << "Enter y for Yes or n for No\n";
        
        getline(cin, userContinue);

        if (userContinue == "N" || userContinue == "n") {
            cin.clear();
            return false;
        }
        if (userContinue == "Y" || userContinue == "y") {
            cin.clear();
            return true;
        }
        cin.clear();
    }
}

/*Prompt user as to which date variables to change, and proceed accordingly*/
void change(Date date) {
    string change;
    cout << "Enter \"M\" for Month, \"D\" for Day, or \"Y\" for Year\n";
    getline(cin, change);
    if (change == "M" || change == "m") {       //Change Month
        cin.clear();
        cout << "Enter the new Month\n";
        date.setMonth(inputNum());
    }
    if (change == "D" || change == "d") {       //Change Day
        cin.clear();
        cout << "Enter the new Day\n";
        date.setDay(inputNum());
    }
    if (change == "Y" || change == "y") {       //Change Year
        cin.clear();
        cout << "Enter the new Year\n";
        date.setYear(inputNum());
    }
}

int main() {
    int month, day, year;   //Use for constructing Date object

    //Input the data for the date
    cout << "Please enter the month\n";
    month = inputNum();
    cout << "Please enter the day\n";
    day = inputNum();
    cout << "Please enter the year\n";
    year = inputNum();

    //Loop while the user would like to continue with the program.
    while (true) {
        Date date (month, day, year);
        date.toString();
        cout << "Would you like to change the Month, Day, or Year?\n";
        if (checkChange()) {
            change(date);
        }
        date.toString();
        cout << "Would you like to end the program?\n";
        if (checkChange())
            break;
    }

    return 0;
}