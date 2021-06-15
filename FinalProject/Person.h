/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Khan's Calorie Tracker
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <string>

class Person {
protected:
	/*Variables for a Person*/
	std::string name;
	unsigned int age;
	unsigned int currentWeight;
	unsigned int height;
	unsigned int goalWeight;
	unsigned int weightToLose;
	unsigned int monthsToLoseWeight;
	unsigned int dailyCalories;
	int BMR;
	enum GENDER { MALE = 1, FEMALE } gender;
	enum ExerciseLevel { LITTLE = 1, LIGHT, MODERATE, VERY, EXTRA} exerciseLevel;
public:
	/*Getters*/
	std::string getName();					
	unsigned int getAge();
	unsigned int getCurrentWeight();
	unsigned int getHeight();
	unsigned int getGoalWeight();
	unsigned int getWeightToLose();
	unsigned int getMonthsToLoseWeight();
	unsigned int getDailyCalories();
	unsigned int getBMR();
	GENDER getGender();
	ExerciseLevel getExerciseLevel();
	/*These getters return string forms of the Enums*/
	std::string getGender_toString();
	std::string getExerciseLevel_toString();

	/*Setters*/
	void setCurrentWeight(const int currentWeight);
	void setGoalWeight(const int goalWeight);
	void setMonthsToLoseWeight(const int monthsToLoseWeight);
	void setExerciseLevel(ExerciseLevel exerciseLevel);
};