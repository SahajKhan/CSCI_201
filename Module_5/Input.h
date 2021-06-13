#pragma once
#include <string>
//using namespace std;


/*Input Library, these function will take input from the user and return correct value*/

class SahajInputClass {
    public:
        std::string input();
        template <typename parameter>
        auto input(parameter min, parameter max);
        template <typename parameter>
        auto input(parameter min);

};