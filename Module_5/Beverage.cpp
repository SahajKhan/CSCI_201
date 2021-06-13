/* Program name: Beverages
*  Author: Sahaj Khan
*  Date last updated: 4/4/2021
*  Purpose: Practice Heirarchy
*/

#include "Beverage.h"
using std::cout;
using std::endl;

/*Constructor*/
Beverage::Beverage(string name, string description, double servingSize, double calories, double price) {
    this->name = name;
    this->description = description;
    this->servingSize = servingSize;
    this->calories = calories;
    this->price = price;
}

/*Destructor*/
Beverage::~Beverage () {
    cout << "Beverage has been deleted.\n";
}

/*Getters*/
string Beverage::getName()        { return name; }
string Beverage::getDescription() { return description; }
double Beverage::getServingSize() { return servingSize; }
double Beverage::getCalories()    { return calories; }
double Beverage::getPrice()       { return price; }

/*Setters*/
void Beverage::setName(string name)               { this->name = name; }
void Beverage::setDescription(string description) { this->description = description; }
void Beverage::setServingSize(double servingSize) { this->servingSize = servingSize; }
void Beverage::setCalories(double calories)       { this->calories = calories; }
void Beverage::setPrice(double price)             { this->price = price; }

/*Print function*/
void Beverage::toString() {
    cout << "Beverage: "     << name        << endl;
    cout << "Description: "  << description << endl;
    cout << "Serving Size: " << servingSize << endl;
    cout << "Calories: "     << calories    << endl;
    cout << "Price: "        << price       << endl;
}


/**********************************Coffee Class**********************************/


/*Constructor*/
Coffee::Coffee(string name, string description, double servingSize, double calories,
                double price, Temperature temperature, RoastType roastType, bool isCaffinated,
                int strength, double creamer, double sweetner)
                :Beverage(name, description, servingSize, calories, price) {   
    this->temperature = temperature;
    this->roastType = roastType;
    this->isCaffinated = isCaffinated;
    this->strength = strength;
    this->creamer = creamer;
    this->sweetner = sweetner;
}

/*Destructor*/
Coffee::~Coffee() {
    cout << "This coffee has been deleted\n";
}

/*Getters*/
Coffee::Temperature Coffee::getTemperature() { return temperature; }
Coffee::RoastType Coffee::getRoastType()     { return roastType; }
bool Coffee::getCaffinated()                 { return isCaffinated; }
int Coffee::getStrength()                    { return strength; }
double Coffee::getCreamerValue()             { return creamer; }
double Coffee::getSweetnerValue()            { return sweetner; }

/*Setters*/
void Coffee::newTemperature(Temperature temperature) { this->temperature = temperature;}
void Coffee::updateCaffinated(bool isCaffinated)     { this->isCaffinated = isCaffinated;}
void Coffee::newStrength(int strength)               { this->strength = strength; }
void Coffee::newCreamerValue(double creamer)         { this->creamer = creamer; }
void Coffee::newSweetnerValue(double sweetner)       { this->sweetner = sweetner; } 

/*Print function*/
void Coffee::toString() {
    Beverage::toString();

    cout << "Temperature: ";
    temperature == HOT ? cout << "Hot\n" : cout << "Cold\n";
    cout << "Type of Roast: ";
    switch (roastType)
    {
    case LIGHT:
        cout << "Light\n";
        break;
    case MEDIUM:
        cout << "Medium\n";
        break;
    case DARK:
        cout << "Dark\n";
        break;
    case FRENCH_ROAST:
        cout << "French Roast\n";
        break;
    case ESPRESSO:
        cout << "Espresso\n";
        break; 
    default:
        break;
    }
}



/*************************************Tea Class**********************************/

/*Constructor*/
Tea::Tea(string name, string description, double servingSize, double calories, double price,
         Temperature temperature, Type type, double creamer, double sweetner, bool isLemon)
         :Beverage(name, description, servingSize, calories, price) {
            this->temperature = temperature;
            this->type = type;
            this->creamer = creamer;
            this->sweetner = sweetner;
            this->ifLemon = ifLemon;
        }

/*Destructor*/
Tea::~Tea() {
    cout << "This tea has been deleted.\n";
}

/*Getters*/
Tea::Type Tea::getType()               { return type; }
Tea::Temperature Tea::getTemperature() { return temperature; }
double Tea::getCreamerValue()          { return creamer; }
double Tea::getSweetnerValue()         { return sweetner; }
bool Tea::getIfLemon()                 { return ifLemon; }

/*Setters*/
void Tea::newTemperature(Temperature temperature) { this->temperature = temperature; }
void Tea::newCreamerValue(double creamer)         { this->creamer = creamer; }
void Tea::newSweetnerValue(double sweetner)       { this->sweetner = sweetner; }
void Tea::changeIfLemon(bool ifLemon)             { this->ifLemon = ifLemon; }


/**********************************Soda Class***********************************/


/*Constructor*/
Soda::Soda(string name, string description, double servingSize, double calories, double price,
           string brand, Type type, bool isDiet) 
           :Beverage(name, description, servingSize, calories, price) {
            this->brand = brand;
            this->type = type;
            this->isDiet = isDiet;
        }

/*Destructor*/
Soda::~Soda() {
    cout << "This Soda has been deleted.\n";
}

/*Getters*/
string Soda::getBrand()     { return brand; }
Soda::Type Soda::getType()  { return type; }
bool Soda::getIsDiet()      { return isDiet; }

/*Setters*/
void Soda::setBrand(string brand) { this->brand = brand; }
void Soda::setType(Type type)     { this->type = type; }
void Soda::setIsDiet(bool isDiet) { this->isDiet = isDiet; }


/******************************Energy Drink Class********************************/


/*Constructor*/
EnergyDrink::EnergyDrink(string name, string description, double servingSize, double calories, double price,
            string brand, Stimulant stimulant, Sweetner sweetner)
            :Beverage(name, description, servingSize, calories, price) {
                this->brand = brand;
                this->stimulant = stimulant;
                this->sweetner = sweetner;
            }

/*Destructor*/
EnergyDrink::~EnergyDrink() {
    cout << "This EnergyDrink has been deleted.\n";
}

/*Getters*/
string EnergyDrink::getBrand()                      { return brand; }
EnergyDrink::Stimulant EnergyDrink::getStimulant()  { return stimulant; }
EnergyDrink::Sweetner EnergyDrink::getSweetner()    { return sweetner; }

/*Setters*/
void EnergyDrink::setBrand(string brand)            { this->brand = brand; }
void EnergyDrink::setStimulant(Stimulant stimulant) { this->stimulant = stimulant; }
void EnergyDrink::setSweetner(Sweetner sweetner)    { this->sweetner = sweetner; }