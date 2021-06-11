/* Program name: CoffeeCup
*  Author: Sahaj Khan
*  Date last updated: 3/21/2021
*  Purpose: Practice Overloading operators
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class coffeeCup{
    string material, color;
    double capacity, contentLevel;

    public:
        coffeeCup (string material, string color, double capacity); //Constructor
        
        string getMaterial();       //returns material of the cup
        string getContents();       //returns the type of liquid in the cup
        double getCapacity();       //returns the max capacity of the cup
        double getFillLevel();      //returns the amount of empty space in the cup
        double getContentLevel();   //returns how full the cup is
        bool isEmpty();             //returns true if cup is empty, false otherwise
        bool isFull();              //returns true of cup is full, false otherwise

        void pour(const double);    //decreases contentLevel by parameter value
        void sip(const double);     //decreases contentLevel by parameter value
        void refill(const double);  //increases contentLevel by parameter value

        bool operator==(coffeeCup); //overload == to check if object contentLevels are equal
        bool operator<(coffeeCup);  //overload  < to check if object contentLevels are less than
        bool operator>(coffeeCup);  //overload  > to check if object contentLevels are more than

        coffeeCup operator--();     //overload -- prefix  to remove 1oz of contentLevel
        coffeeCup operator--(int);  //overload -- postfix to remove 1oz of contentLevel

        void operator+=(double amountToBeAdded);    //+= for contentLevel within object
        void operator-=(double amountToBeRemoved);  //-= for contentLevel within object

        friend ostream &operator<<(ostream &output, const coffeeCup &coffeecup); //overloading << for printing member variables
};