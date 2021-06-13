#include "Input.h"
#include <iostream>
#include <limits>

template <typename parameter>
auto SahajInputClass::input (parameter min, parameter max) {
    SahajInputClass::parameter input;
    getline(std::cin, input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.clear();
    if (input < min || input > max) {
        std::cout << "Incorrect input, please try again.\n";
        return input();
    }
    return input;
}

template <typename parameter>
auto SahajInputClass::input(parameter min) {
    SahajInputClass::parameter input;
    getline(std::cin, input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.clear();
    if (input < min) {
        std::cout << "Incorrect input, please try again.\n";
        return input();
    }
    return input;
}

std::string SahajInputClass::input() {
    std::string String;
    getline(std::cin, String);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.clear();
    return String;
}
