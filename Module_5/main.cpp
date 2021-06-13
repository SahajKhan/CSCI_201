/* Program name: Beverages
*  Author: Sahaj Khan
*  Date last updated: 4/4/2021
*  Purpose: Practice Heirarchy
*/

#include "Beverage.h"

using std::cout;

// int inputRoastType();
// int inputTemperature();
// int inputTeaType();
// int inputSodaType();
// int inputStimulant();
// int inputSweetner();

Coffee createCoffee(Beverage beverage);


int main() {
    enum Type {BLACK, OOLONG, GREEN, HERBAL, OTHER} type;
    //enum Temperature {HOT, COLD} temperature;
    enum RoastType {LIGHT, MEDIUM, DARK, FRENCH_ROAST, ESPRESSO} roastType;
    enum Stimulant {CAFFEINE, TAURINE, OTHER_STIMULANT} stimulant;
    enum Sweetner  {SUGAR, SACCHARIN, ASPARTAME, ACESULFAME, SUCRALOSE, ADVANTAME, NEOTAME} sweetner;

    Beverage beverage("Drink", "A drink", 24, 240, 4.99);
    // Coffee coffee(beverage.getName(), beverage.getDescription(), beverage.getServingSize(), beverage.getCalories(), beverage.getPrice(),
    // HOT, DARK, true, 3, 4.0, 5.0);
    // Tea tea(beverage.getName(), beverage.getDescription(), beverage.getServingSize(), beverage.getCalories(), beverage.getPrice(),
    // HOT, BLACK, 3.4, 2.4, false);
    // Soda soda("Drink", "A drink", 24, 240, 4.99
    // "redbull", OTHER, true);
    // EnergyDrink e("Drink", "A drink", 24.0, 240.0, 4.99,
    // "redbull", CAFFEINE, SUGAR);

    Coffee Coffee(beverage.getName(), " ", 23,23,23,Coffee::HOT, Coffee::LIGHT,true,23,23.0,23.90);
    
    
    return 0;
}

