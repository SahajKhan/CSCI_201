/* Program name: Data.h
*  Author: Sahaj Khan
*  Date last updated: 2/7/2021
*  Purpose: Header File for Data.cpp
*/
#pragma once

#include <iostream>

using namespace std;

class Date
{
    int month, day, year;

public:
    Date(int month, int day, int year);
    void toString();
    int getMonth();
    int getDay();
    int getYear();
    void setMonth(int);
    void setDay(int);
    void setYear(int);
};