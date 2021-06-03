/* Program name: Data.cpp
*  Author: Sahaj Khan
*  Date last updated: 2/7/2021
*  Purpose: Practice exceptions by entering Dates
*/
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

Date::Date(int month, int day, int year)
{

    try
    {
        if (month < 1 || month > 12)
            throw invalid_argument("The month must be from 1 to 12");
        if (day < 1 || day > 31)
            throw invalid_argument("The day cannot be less than 1 or greater than 31.");
        if (year < 1900 || year > 2020)
            throw invalid_argument("The year must be between 1809 and 2021");

        //Error validate correct number of days for non 31 day months
        if (day >= 1 || day <= 31)
        {
            if (month == 2 && month > 28)
                throw invalid_argument("February cannot be more than 28 days.");
            if (month == 4 || month == 6 || month == 9 || month == 11)
                throw invalid_argument("This month cannot have more than 30 days.");
        }
    }
    catch (exception &e)
    {
        cout << "Invalid Exception Encountered: ";
        cout << e.what() << endl;
    }

    this->month = month;
    this->day = day;
    this->year = year;
}

int Date::getDay() {
    return Date::day;
}
int Date::getMonth() {
    return Date::month;
}
int Date::getYear() {
    return Date::year;
}
void Date::setDay(int day) {
    this->day = day;
}
void Date::setMonth(int month) {
    this->month = month;
}
void Date::setYear(int year) {
    this->year = year;
}


void Date::toString() {
    switch (getMonth())
    {
    case 1:
        cout << "January ";
        break;
    case 2:
        cout << "February ";
        break;
    case 3:
        cout << "March ";
        break;
    case 4:
        cout << "April ";
        break;
    case 5:
        cout << "May ";
        break;
    case 6:
        cout << "June ";
        break;
    case 7:
        cout << "July ";
        break;
    case 8:
        cout << "August ";
        break;
    case 9:
        cout << "Septemeber ";
        break;
    case 10:
        cout << "October ";
        break;
    case 11:
        cout << "November ";
        break;
    case 12:
        cout << "December ";
        break;
    default:
        break;
    }

    cout << getDay() << ", " << getYear() << endl;
}