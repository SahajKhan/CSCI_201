//@author Sahaj_Khan
//Server Side

#include <iostream>
#include <string>
#include "MySocket.h"
#include <map>
#include <fstream>

using namespace std;
using boost::asio::ip::tcp;

map<string, string> states;
map<string, string>::iterator it;



void populateMap() {
    ifstream inputFile;
    inputFile.open("State_Abbreviations.txt");
    string in1, in2;

    while (inputFile) {
        inputFile >> in1; //Get the full state name
        inputFile >> in2; //retrieve initials
        
        //store input into map
        states[in2];
        states[in2] = in1;
    }
}

string findFullName(string message) {
    map <string, string>::iterator it;
    it = states.find(message);
    try {
        if (it == states.end())
            throw invalid_argument(message + " does not exist");
    }
    catch (invalid_argument e) {
        cout << e.what();
    }

    cout << message << " is the full name\n";
}





int main()
{
    populateMap();
    string message = "Welcome";

    cout << "Running Boost Server!!!" << endl;
    try {
        MySocket socket; //Create socket
        unsigned int port;

        cout << "what port would you like to use?" << endl;
        cin >> port;
        socket.bind(port);

        while (true) {
            socket.accept(); //block - wait for connection
            cout << "Connection established\n";
            do {
                try {
                    socket.write(message);
                }
                catch (SocketClosedException& e) {
                    cout << e.what() << endl;
                    break;
                }

                cout << socket.read() << endl;
                cout << "Enter state abbreviation or \"Stop\" to stop\n";
                cin >> message;

                findFullName(message);

            } while (message != "STOP");

            socket.close();
            break;
                       
        }

    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}