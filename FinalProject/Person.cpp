/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Khan's Calorie Tracker
 Instructor:	Kristopher Roberts
 *************************************************/
#include "Person.h"

/*Getters*/
std::string Person::getName() { return name; }
unsigned int Person::getAge() { return age; }
unsigned int Person::getCurrentWeight() { return currentWeight; }
unsigned int Person::getHeight() { return height; }
unsigned int Person::getGoalWeight() { return goalWeight; }
unsigned int Person::getWeightToLose() { return weightToLose; }
unsigned int Person::getMonthsToLoseWeight() { return monthsToLoseWeight; }
unsigned int Person::getDailyCalories() { return dailyCalories; }
unsigned int Person::getBMR() { return BMR; }

Person::GENDER Person::getGender() { return gender; }
Person::ExerciseLevel Person::getExerciseLevel() { return exerciseLevel; }

std::string Person::getGender_toString() {
	if (gender == MALE)
		return "Male";
	return "Female";
}
std::string Person::getExerciseLevel_toString() {
	if (exerciseLevel == LITTLE)
		return "Little";
	if (exerciseLevel == LIGHT)
		return "Light";
	if (exerciseLevel == MODERATE)
		return "Moderate";
	if (exerciseLevel == VERY)
		return "Very";
	if (exerciseLevel == EXTRA)
		return "Extra";
}

/*Setters*/
void Person::setCurrentWeight(const int currentWeight) { this->currentWeight = currentWeight; }
void Person::setGoalWeight(const int goalWeight) { this->goalWeight = goalWeight; }
void Person::setMonthsToLoseWeight(const int monthsToLoseWeight) { this->monthsToLoseWeight = monthsToLoseWeight; }
void Person::setExerciseLevel(ExerciseLevel exerciseLevel) { this->exerciseLevel = exerciseLevel; }