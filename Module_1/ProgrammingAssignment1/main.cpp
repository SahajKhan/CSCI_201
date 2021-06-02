/* Program name: main.cpp
*  Author: Sahaj Khan
*  Date last updated: 1/24/2021
*  Purpose: Save rectangle data as a class object and modify values by setters and getters
*/
#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Rectangle {
    int length, width, x_location, y_location;
    string color;

    public:
        //Constructor
        Rectangle (int length, int width, int x_location, int y_location, string color) {
            this->length = length;
            this->width = width;
            this->x_location = x_location;
            this->y_location = y_location;
            this->color = color;
        }
        //Getters
        int getLength() {
            return length;
        }
        int getWidth() {
            return width;
        }
        int getX() {
            return x_location;
        }
        int getY() {
            return y_location;
        }
        string getColor(){
            return color;
        }

        //Setters
        void setLength(int length) {
            this->length = length;
        }
        void setWidth(int width) {
            this->width = width;
        }
        void setX(int x_location) {
            this->x_location = x_location;
        }
        void setY(int y_location) {
            this->y_location = y_location;
        }
        void setColor(string color) {
            this->color = color;
        }

        //This method will return the total area
        int getArea() {
            return length*width;
        }

};

int inputInt();
void modify(Rectangle r);
void print(Rectangle r);

int main() {
    //Create local rectangle variables
    int length, width, x_location, y_location;
    string color;
    
    //Prompt the user for input, and submit input into variables
    cout << "Hello\nPlease enter the Length.\n";
    length = inputInt();
    cout << "Please enter the Width.\n";
    width = inputInt();
    cout << "Please enter the location of X.\n";
    x_location = inputInt();
    cout << "Please enter the location of Y.\n";
    y_location = inputInt();
    cout << "Please enter the color of the rectangle.\n";
    cin >> color;

    //Create class
    Rectangle rectangle(length, width, x_location, y_location, color);
    //Print values
    print(rectangle);

    //Check if user wants to modify values and do so if needed
    modify(rectangle);
    
    cout << "These are the final values\n";
    print(rectangle);

}

//This will take input for int values, error checking will be performed
int inputInt() {
    int input;

    while (true) {
        cin >> input;
        /*Error Checking*/
        if (!cin) {
            cout << "Please enter an integer\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        /*Error Checking*/
        if (input <= 0)
            cout <<"Please enter an integer greater than zero\n";
        else 
            break;
    }
    return input;
}

//userMutator will check if the user would like to modify any values
//then it will proceed to modify the correct values
void modify(Rectangle r) {
    string answer; //User input

    while (true) { //Loop until user would no longer wishes to modify
        cout << "Would you like to change any values? Enter yes or no below\n";

        while (true) { //Loop until correct string is given
            cin >> answer;

            if (answer == "Yes" || answer == "yes")
                break;
            if (answer == "No" || answer == "no")
                return;

            //If answer is not yes or no, stay in the loop
            cout << "Please only enter yes or no.\n";
        }

        cout << "Which value would you like to modify?\n";

        while (true) { //Loop until a useable answer is given
            cout << "Please enter one of the following\n";
            cout << "Length, Width, X, Y, or Color\n";
            cin >> answer;

            if (answer == "Length" || answer == "length") {
                cout << "What is the new length?\n";
                r.setLength(inputInt());
                break;
            } else if (answer == "Width" || answer == "width") {
                cout << "What is the new width?\n";
                r.setWidth(inputInt());
                break; 
            } else if (answer == "X" || answer == "x") {
                cout << "What is the new location of X?\n";
                r.setX(inputInt());
                break;
            } else if (answer == "Y" || answer == "y") {
                cout << "What is the new location of Y?\n";
                r.setY(inputInt());
                break;
            } else if (answer == "Color" || answer == "color") {
                cout << "What is the new color?\n";
                cin >> answer;
                break;
                r.setColor(answer);
            }
        }


        print(r); 
    }
}

//This function prints all values for a rectangle object
void print (Rectangle r) {
    cout << "The current values\n";
    cout << "Length: " << r.getLength() << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Location of X: " << r.getX() << endl;
    cout << "Location of Y: " << r.getY() << endl;
    cout << "The color: " << r.getColor() << endl;
    cout << "The area: " << r.getArea() << endl;
}
