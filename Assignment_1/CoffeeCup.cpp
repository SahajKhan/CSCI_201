/* Program name: CoffeeCup
*  Author: Sahaj Khan
*  Date last updated: 3/22/2021
*  Purpose: Practice Overloading operators
*/
#include <iostream>
#include <string>
#include "CoffeeCup.h"

/*Constructor*/
coffeeCup::coffeeCup (string material, string color, double capacity) {
    this->material = material;
    this->color = color;
    this->capacity = capacity;
    this->contentLevel = 0;

    try {
        if (capacity > 64)
            throw std::invalid_argument("The capacity should not exceed 64oz.");
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }  
}

/*Return Member variables*/
string coffeeCup::getMaterial() {return material;}
double coffeeCup::getCapacity() {return capacity;}
double coffeeCup::getFillLevel() {return capacity - contentLevel;}
double coffeeCup::getContentLevel() {return contentLevel;}

/*Check if capacity is Empty or Full, return respective  boolean value*/
bool coffeeCup::isEmpty() {return contentLevel > 0 ? true: false;}
bool coffeeCup::isFull() {return contentLevel == capacity ? true:false;}

/*decrease contentLevel by amountToRemove, throw error if amountToRemove>contentLevel*/
void coffeeCup::pour(const double  amountToRemove) {
    try {
        if (amountToRemove > contentLevel) {
            throw underflow_error("Cannot remove more quanitity than is available");
        }
        if (amountToRemove > contentLevel) {}
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }
    contentLevel -= amountToRemove;
}

/*decrease contentLevel by amountToRemove, throw error if amountToRemove>1*/
void coffeeCup::sip (const double amountToRemove) {
    try{
        if (amountToRemove > 1)
            throw underflow_error("A sip cannot exceed 1 floz.");
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }
    pour (amountToRemove);
}

/*increase contentLevel by quantityToRefill, throw error if parameter input + contentLevel > capacity*/
void coffeeCup::refill(const double quantityToRefill) {
    try {
        if (quantityToRefill + contentLevel > capacity)
            throw overflow_error("Cannot refill above the cup's capacity.");
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }
    contentLevel+=quantityToRefill;
}

/*Operator Overloading*/
bool coffeeCup::operator==(coffeeCup otherCup) {return contentLevel == otherCup.contentLevel ? true:false;}
bool coffeeCup::operator< (coffeeCup otherCup) {return contentLevel <  otherCup.contentLevel ? true:false;}
bool coffeeCup::operator> (coffeeCup otherCup) {return contentLevel >  otherCup.contentLevel ? true:false;}
void coffeeCup::operator+=(double amountToBeAdded) {refill(amountToBeAdded);}
void coffeeCup::operator-=(double amountToBeRemoved) {pour(amountToBeRemoved);}

coffeeCup coffeeCup::operator--() {     //Prefix
    sip(1);
    return *this;
}

coffeeCup coffeeCup::operator--(int) {  //PostFix
    coffeeCup temp = *this;
    sip(1);
    return temp;
}

ostream& operator<<(ostream &output, const coffeeCup &coffeecup) {
    cout << "Cup material: " << coffeecup.material << endl;
    cout << "Cup color: " << coffeecup.color << endl;
    cout << "Cup capacity: " << coffeecup.capacity << endl;
    cout << "Cup content level: " << coffeecup.contentLevel << endl;
    return output;
}