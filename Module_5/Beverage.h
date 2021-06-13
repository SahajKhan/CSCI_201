/* Program name: Beverages
*  Author: Sahaj Khan
*  Date last updated: 4/4/2021
*  Purpose: Practice Heirarchy
*/
#pragma once
#include <iostream>
#include <string>

using std::string;

/*Class that hold attributes for a beverage*/
class Beverage {
    string name, description;
    double servingSize, calories, price;
    
    public:
        /*Constructor*/
        Beverage(string name, string description, double servingSize, double calories, double price);

        /*Destructor*/
        ~Beverage();
     
        /*Getters*/
        string getName();
        string getDescription();
        double getServingSize();
        double getCalories();
        double getPrice();

        /*Setters*/
        void setName(string newName);
        void setDescription(string newDescription);
        void setServingSize(double newServingSize);
        void setCalories(double newCalories);
        void setPrice(double newPrice);

        /*Print function*/
        void toString();
};

class Coffee:Beverage {
    // enum RoastType {LIGHT, MEDIUM, DARK, FRENCH_ROAST, ESPRESSO} roastType;
    // enum Temperature {HOT, COLD} temperature;
    bool isCaffinated;
    int strength;
    double creamer;
    double sweetner;

    public:
        enum RoastType {LIGHT, MEDIUM, DARK, FRENCH_ROAST, ESPRESSO} roastType;
        enum Temperature {HOT, COLD} temperature;  

        /*Constructor*/
        Coffee(string name, string description, double servingSize, double calories, double price,
                Temperature temperature, RoastType roastType, bool isCaffinated, int strength, double creamer, double sweetner);

        /*Destructor*/  
        ~Coffee();

        /*Getters*/
        Temperature getTemperature();
        RoastType getRoastType();
        bool getCaffinated();
        int getStrength();
        double getCreamerValue();
        double getSweetnerValue();

        /*Setters*/
        void newTemperature(Temperature temperature);
        void updateCaffinated(bool isCaffinated);
        void newStrength(int strength);
        void newCreamerValue(double creamer);
        void newSweetnerValue(double sweetner);

        /*Print function*/
        void toString();
};

class Tea:Beverage {
    enum Type {BLACK, OOLONG, GREEN, HERBAL, OTHER} type;
    enum Temperature {HOT, COLD} temperature;
    double creamer;
    double sweetner;
    bool ifLemon;

    public:
        /*Constructor*/
        Tea(string name, string description, double servingSize, double calories, double price,
                Temperature temperature, Type type, double creamer, double sweetner, bool isLemon);

        /*Destructor*/
        ~Tea();

        /*Getters*/
        Type getType();
        Temperature getTemperature();
        double getCreamerValue();
        double getSweetnerValue();
        bool getIfLemon();

        /*Setters*/
        void newTemperature(Temperature temperature);
        void newCreamerValue(double creamer);
        void newSweetnerValue(double sweetner);
        void changeIfLemon(bool ifLemon);

        /*Print function*/
        void toString();
};

class Soda:Beverage {
    string brand;
    enum Type {COLA, LEMON_LIME, BIRCH, OTHER} type;
    bool isDiet;

    public:
        /*Constructor*/
        Soda(string name, string description, double servingSize, double calories, double price,
             string brand, Type type, bool isDiet);

        /*Destructor*/
        ~Soda();

        /*Getters*/
        string getBrand();
        Type getType();
        bool getIsDiet();

        /*Setters*/
        void setBrand(string brand);
        void setType(Type type);
        void setIsDiet(bool isDiet);

        /*Print function*/
        void toString();
};

class EnergyDrink:Beverage {
    string brand;
    enum Stimulant {CAFFEINE, TAURINE, OTHER} stimulant;
    enum Sweetner  {SUGAR, SACCHARIN, ASPARTAME, ACESULFAME, SUCRALOSE, ADVANTAME, NEOTAME} sweetner;

    public:
        /*Constructor*/
        EnergyDrink(string name, string description, double servingSize, double calories, double price,
                    string brand, Stimulant stimulant, Sweetner sweetner);

        /*Destructor*/
        ~EnergyDrink();

        /*Getters*/
        string getBrand();
        Stimulant getStimulant();
        Sweetner getSweetner();

        /*Setters*/
        void setBrand(string brand);
        void setStimulant(Stimulant stimulant);
        void setSweetner(Sweetner sweetner);

        /*Print function*/
        void toString();
};