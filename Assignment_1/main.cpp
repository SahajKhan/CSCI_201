/* Program name: CoffeeCup
*  Author: Sahaj Khan
*  Date last updated: 3/22/2021
*  Purpose: Practice Overloading operators
*/
#include "CoffeeCup.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

int inputNum(int, int);
bool askToChangeValue();
void change(int typeOfCase, coffeeCup &cup);

int main() {
    /*Create Data variables*/
    vector <coffeeCup> cups;                        //Vector of cups
    int numOfVectors, cupToChange, whatToChange;    //variables that will be used to save user input
    string material, color;                         //string variables used to create cup objects
    double capacity, contentLevel;                  //double variables to create cub objects

    cout << "Please enter the number of cups\n";
    cout << "Enter a number from 4 to 7\n";
    numOfVectors = inputNum(4,7);
    
    /*Fill vector with cups*/
    for (int i = 0; i < numOfVectors; i++) {
        /*Prompt User for data*/
        cout << "Please enter the material for cup " << i+1 << endl;
        material = inputString();
        cout << "Please enter the color for cup " << i+1 << endl;
        color = inputString();
        cout << "Please enter the max volume in floz for cup " << i+1 << endl;
        capacity = inputNum(0.0, 64.0);

        coffeeCup temp(material, color, capacity);
        cout << "Cup: " << i+1 << endl << temp << endl;
        cups.push_back(temp);
    }

    /*Loop until user ends program*/
    while(true) {    
        /*Check to see if the user wants to change values*/
        if (!askToChangeValue())
            return 0;

        /*Change variables*/
        cout << "Which cup would you like to change?\n";
        for (int i = 0; i < cups.size(); i++) {
            cout << "Cup # " << i+1 << "?\n";
        }

        cupToChange = inputNum(1, cups.size());

        cout << "What would you like to do?\n";
        cout << "Enter 1 for \"Pour\"\n";
        cout << "Enter 2 for \"Sip\"\n";
        cout << "Enter 3 for \"Refill\"\n";

        whatToChange = inputNum(1,3);
        change(whatToChange, cups[cupToChange]);
    }
}

/*Input int values and error check to make sure number is less than parameter*/
int inputNum(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        /*Error Checking*/
        if (!cin) {
            cout << "Please enter a number\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if (input < min || input  > max) {
            cout << "Enter a number from "<< min << " to " << max << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        break;
    }
    cin.clear();
    return input;
}

/*Input double values and error check to make sure number is less than parameter*/
double inputNum(double min, double max) {
    double input;
    while (true) {
        cin >> input;
        /*Error Checking*/
        if (!cin) {
            cout << "Please enter a number\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if (input < min || input  > max) {
            cout << "Enter a number from "<< min << " to " << max << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        break;
    }
    cin.clear();
    return input;
}

/*Function to get a string input from the user*/
string inputString() {
    string input;
    cin >> input;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return input;
}

/*Ask if the user wants to change any cup data, if false, end the program*/
bool askToChangeValue() {
    string input;
    cout << "If you would like to change a value input \'Y\', press any other key to skip.\n";
    cin >> input;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if (input == "Y" || input == "y")
        return true;
    return false;
}

/*Modify contentLevel value*/
void change(int typeOfCase, coffeeCup &cup) {
    double input;
    switch (typeOfCase) {
    case 1:
        cout << "How much would you like to pour?\n";
        input = inputNum(0.0,cup.getFillLevel());
        cup -= input;
        break;
    case 2:
        cout << "You have chosen sip, 1oz will be removed.\n";
        --cup;
        break;
    case 3:
        cout << "How much would you like to refill?\n";
        input = inputNum(0.0,cup.getFillLevel());
        cup += input;
        break;    
    default:
        cout << "That is not an option.\n";
        break;
    }
}