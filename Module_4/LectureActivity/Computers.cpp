/* Program name: Computers.cpp
*  Author: Sahaj Khan
*  Date last updated: 3/21/2021
*  Purpose: Createa a Personal Computer class and use it to store data
*/
#include <iostream>
#include <string>
#include <climits>
#include <limits>
using namespace std;

class PersonalComputer {
    string model, serialNumber, CPU, operatingSystem, driveType, chipset;
    double speed;
    int memory, diskSize;
    bool bootState;
    static string MFG_CODE, manufacturer;
    static int numOfPCs, sequenceNumber;


    public:
        /*Constructor*/
        PersonalComputer(string model, string CPU, int memory, double speed) {
            try {
                if (manufacturer == "")
                    throw invalid_argument("Manufacturer not provided");
            } catch (invalid_argument &e) {
                cout << e.what() << endl;
            }

            try {
                if (model == "")
                    throw invalid_argument("Model not provided");
            } catch (invalid_argument &e) {
                cout << e.what() << endl;
            }


            serialNumber = MFG_CODE + model.substr(0,3) + to_string(sequenceNumber);
            try {
                if (serialNumber == "")
                    throw invalid_argument("Serial Number not provided");
            } catch (invalid_argument &e) {
                cout << e.what() << endl;
            }

            try {
                if (CPU == "")
                    throw invalid_argument("CPU not provided");
            } catch (invalid_argument &e) {
                cout << e.what() << endl;
            }

            try {
                if (memory % 2 != 0)
                    throw invalid_argument("Memory size must be a power of two (2, 4, 8, 16, 32, 64, or 128 GB)");
            } catch(invalid_argument &e) {
                cout << e.what() << endl;
            }
            try {
                if (speed < 33)
                    throw invalid_argument("Speed cannot be less than 33");
            }catch(exception &e) {
                cout << e.what() << endl;
            }
            
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
            numOfPCs++;
        }

        /*Destructor*/
        ~PersonalComputer() {
            this->numOfPCs--;
        }

        /*Accessor Methods*/
        static string getManufacturer() {
            return manufacturer;
        }
        static int getNumPC() {
            return numOfPCs;
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
            try {
                if (driveType != "SSD" && driveType != "SATA")
                    throw invalid_argument("Inappropraite Drive type, only SSD or SATA are the available options");
            } catch (invalid_argument &e) {
                cout << e.what();
            }
            this->driveType = driveType;
        }
        void setChipset(string chipset) {
            try {
                if (chipset == "")
                    throw invalid_argument("Chipset not provided");
            } catch (invalid_argument &e) {
                cout << e.what() << endl;
            }
            this->chipset = chipset;
        }
        void setDisk(int  diskSize) {
            try {
            switch (diskSize) {
                case 256:
                    this->diskSize = diskSize;
                case 480:
                    this->diskSize = diskSize;
                case 1024:
                    this->diskSize = diskSize;
                case 2048:
                    this->diskSize = diskSize;
                case 4096:
                    this->diskSize = diskSize;
                case 8192:
                    this->diskSize = diskSize;
                case 12288:
                    this->diskSize = diskSize;
                default:
                    throw invalid_argument("Disk size is invalid\n");
                    break;
            }
        } catch (exception &e) {
            cout << "Invalid Argument\n";
            cout << e.what();
            cout << "The choices are: 250GB, 480GB, 1024GB, 2048GB, 4096GB, 8192GB, or 12288GB\n";
        }
            this->diskSize = diskSize;
        }
        void boot(bool bootState) {
            this->bootState = bootState;
        }

        friend ostream &operator<<(ostream &output, const PersonalComputer &PC); //overloading << for printing member variables
};



string PersonalComputer::manufacturer = "Hewlett-Packard";
string PersonalComputer::MFG_CODE = "HP";
int PersonalComputer::sequenceNumber = 7856;
int PersonalComputer::numOfPCs;


void inputDouble(double &result); //This will take a double as input and perform error checking
int inputNum();                //This will take an int as input and perform error checking
int inputMemory();             //return memory amount and error check
ostream& operator<<(ostream &output, const PersonalComputer &pc);

int main() {
    //Constructor variables
    string manufacturer, model, serialNumber, CPU;
    double memory, diskSize, speed;
    string input;

    //cout << "Please enter the Manufacturer\n";
    //cin >> manufacturer;
    cout << "Please enter the Model\n";
    getline(cin, model);
    cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max());
    //cout << "Please enter the Serial Number\n";
    //cin >> serialNumber;
    cout << "Please enter the CPU\n";
    getline(cin, CPU);
    cin.clear();
    cout << "Please enter the Speed in GHz\n";
    inputDouble(speed);
    //cout << "Please enter the Memory in GB\n";
    memory = (double) inputMemory();

    //Create an object pc of type PersonalComputer
    PersonalComputer pc(model, CPU, memory, speed);

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
            memory = (double) inputMemory();
            pc.setMemory(memory);
            break;
        }
        if (input == "D") {
            cout << "Please enter the Disk Size\n";
            diskSize = inputNum();
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
    
    //Print the PC's attributes using overloaded stream operator
    cout << pc;

    pc.boot(false); //Turn off PC
    return 0; //End
}



//This will take an int as input and perform error checking
int inputNum() {
    cin.clear();
    int input;

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
    return input;
}

//This will take a double as input and perform error checking
void inputDouble(double &result) {
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

int inputMemory() { //return memory amount and error check
    int newMemory;
    cout << "Please enter the Memory size in GB\n";
    newMemory = inputNum();                //User inputNum() to error check number
    try {
        for (int i = 2; i <=128; i*=2) {    //Check if memsize is divisible by 2,4,8,16,32,64,128
            if (newMemory % i == 0)
                return newMemory;
        }
        throw invalid_argument("Memory size must be a power of two (2, 4, 8, 16, 32, 64, or 128 GB)");
    } catch(exception &e) {
        cout << e.what() << endl;
    }
    return newMemory;
}

int inputDiskSize() {
    int diskSize;
    cout << "The choices are: 250GB, 480GB, 1024GB, 2048GB, 4096GB, 8192GB, or 12288GB\n";
    diskSize = inputNum();
    while (true) {
        try {
            switch (diskSize) {
                case 256:
                    return diskSize;
                case 480:
                    return diskSize;
                case 1024:
                    return diskSize;
                case 2048:
                    return diskSize;
                case 4096:
                    return diskSize;
                case 8192:
                    return diskSize;
                case 12288:
                    return diskSize;
                default:
                    throw invalid_argument("Disk size is invalid\n");
                    break;
            }
        } catch (exception &e) {
            cout << "Invalid Argument\n";
            cout << e.what();
            cout << "The choices are: 250GB, 480GB, 1024GB, 2048GB, 4096GB, 8192GB, or 12288GB\n";
        }
    }
}

ostream& operator<<(ostream &output, const PersonalComputer &pc) {
    cout << "\nManufacturer: "     << pc.manufacturer
         << "\nModel: "            << pc.model
         << "\nSerial Number: "    << pc.serialNumber
         << "\nCPU: "              << pc.CPU
         << "\nSpeed: "            << pc.speed
         << "\nMemory: "           << pc.memory
         << "\nOperating System: " << pc.operatingSystem
         << "\nDisk Size: "        << pc.diskSize
         << "\nBoot State: "       << pc.bootState
         << "\nDrive Type: "       << pc.driveType
         << "\nChipset: "          << pc.chipset << endl; 
    return output;
}