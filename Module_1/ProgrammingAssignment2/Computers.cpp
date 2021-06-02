/* Program name: main.cpp
*  Author: Sahaj Khan
*  Date last updated: 1/31/2021
*  Purpose: Createa a Personal Computer class and use it to store data
*/
#include <iostream>
#include <string>
#include <climits>

using namespace std;

class PersonalComputer {
    string manufacturer, model, serialNumber, CPU, operatingSystem, driveType, chipset;
    double diskSize, memory, speed;
    bool bootState;

    public:
        /*Constructor*/
        PersonalComputer(string manufacturer, string model, string serialNumber, string CPU, double memory, double speed) {
            this->manufacturer = manufacturer;
            this->model = model;
            this->serialNumber = serialNumber;
            this->CPU = CPU;
            this->memory = memory;
            this->speed = speed;
            this->operatingSystem = "Windows 10";
            this->driveType = "SSD";
            this->chipset = "X99";
            this->diskSize = 1024;
            this->bootState = true;
        }

        /*Accessor Methods*/
        string getManufacturer() {
            return manufacturer;
        }
        string getModel() {
            return model;
        }
        string getSerialNumber() {
            return serialNumber;
        }
        string getCPU() {
            return CPU;
        }
        double getMemory() {
            return memory;
        }
        double getSpeed() {
            return speed;
        }
        string getOperatingSystem() {
            return operatingSystem;
        }
        string getDriveType() {
            return driveType;
        }
        string getChipset() {
            return chipset;
        }
        double getDiskSize() {
            return diskSize;
        }
        bool getBootState() {
            return bootState;
        }

        /*Mutator Methods*/
        void setOperatingSystem(string operatingSystem) {
            this->operatingSystem = operatingSystem;
        }
        void setMemory(double memory) {
            this->memory = memory;
        }
        void setDriveType(string driveType) {
            this->driveType = driveType;
        }
        void setChipset(string chipset) {
            this->chipset = chipset;
        }
        void setDisk(double diskSize) {
            this->diskSize = diskSize;
        }
        void boot(bool bootState) {
            this->bootState = bootState;
        }


};

//This will take a double as input and perform error checking
void inputNum(double &result) {
    cin.clear();
    double input;

    while (true) {
        cin >> input;
        /*Error Checking*/
        if (!cin) {
            cout << "Please enter a number\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        /*Error Checking*/
        if (input <= 0)
            cout <<"Please enter anumber greater than zero\n";
        else 
            break;
    }
    result = input;
}

int main() {
    //Constructor variables
    string manufacturer, model, serialNumber, CPU;
    double memory, diskSize, speed;
    string input;

    cout << "Please enter the Manufacturer\n";
    cin >> manufacturer;
    cout << "Please enter the Model\n";
    cin >> model;
    cout << "Please enter the Serial Number\n";
    cin >> serialNumber;
    cout << "Please enter the CPU\n";
    cin >> CPU;
    cout << "Please enter the Speed in GHz\n";
    inputNum(speed);
    cout << "Please enter the Memory in GB\n";
    inputNum(memory);

    //Create an object pc of type PersonalComputer
    PersonalComputer pc(manufacturer, model, serialNumber, CPU, memory, speed);

    //Display attributes as per assignment
    cout << "\nManufacturer: " << pc.getManufacturer()
         << "\nModel: "        << pc.getModel()
         << "\nSerial Number: "<< pc.getSerialNumber()
         << "\nCPU: "          << pc.getCPU()
         << "\nSpeed: "        << pc.getSpeed() << endl;

    cout << "Would you like to turn the PC on or off or reboot?\n"
         << "Please enter \"On\" \"Off\" or \"Reboot\"\n";
        
    //Check if the user wants to boot, reboot, or turn off the PC
    while (true) { //Loop until a valid input is entered
        cin >> input;
        if (input == "On") {
            pc.boot(true);
            break;
        }
        if (input == "Off") {
            pc.boot(false);
            break;
        }
        if (input == "Reboot") {
            pc.boot(false);
            pc.boot(true);
            break;
        }
        //Error Validation
        cout << "Please enter only \"On\" \"Off\" or \"Reboot\"\n";
    }

    cin.clear();
    cout << "Would you like to change the Memory, Disk Size, or Operating System\n";
    cout << "Please enter \"N\" for No, \"M\" for Memory, \"D\" for Disk Size, and \"O\" for Operating System\n";
    while (true) {//Loop until a valid input is entered
        cin >> input;
        if (input == "M") {
            cout << "Please enter the amount of Memory in GB\n";
            inputNum(memory);
            pc.setMemory(memory);
            break;
        }
        if (input == "D") {
            cout << "Please enter the Disk Size in GB\n";
            inputNum(diskSize);
            pc.setDisk(diskSize);
            break;
        }
        if (input == "O") {
            cout << "Please enter the Operating System\n";
            cin.clear();
            cin >> input;
            pc.setOperatingSystem(input);
            break;
        }
        if (input == "N")
            break;
        //Error Validation
        cout << "Please enter \"N\" for No, \"M\" for Memory, \"D\" for Disk Size, and \"O\" for Operating System\n";
    }

    cin.clear();
    cout << "Would you like to change the Drive Type or Chipset?\n";
    cout << "Enter \"N\" for No, \"D\" for Drive Type, or \"C\" for Chipset\n";
    while (true) {//Loop until a valid input is entered
        cin >> input;
        
        if (input == "N")
            break;
        if (input == "D") {
            cout << "Enter the new Drive Type\n";
            cin >> input;
            pc.setDriveType(input);
            break;
        }
        if (input == "C") {
            cout << "Enter the new Chipset\n";
            cin.clear();
            cin >> input;
            pc.setChipset(input);
            break;
        }
        //Error Validation
        cout << "Enter \"N\" for No, \"D\" for Drive Type, or \"C\" for Chipset\n";
    }
    
    //Print the PC's attributes
    cout << "\nManufacturer: "     << pc.getManufacturer()
         << "\nModel: "            << pc.getModel()
         << "\nSerial Number: "    << pc.getSerialNumber()
         << "\nCPU: "              << pc.getCPU()
         << "\nSpeed: "            << pc.getSpeed()
         << "\nMemory: "           << pc.getMemory()
         << "\nOperating System: " << pc.getOperatingSystem()
         << "\nDisk Size: "        << pc.getDiskSize()
         << "\nBoot State: "       << pc.getBootState()
         << "\nDrive Type: "       << pc.getDriveType()
         << "\nChipset: "          << pc.getChipset() << endl; 


    pc.boot(false); //Turn off PC
    return 0; //End
}
