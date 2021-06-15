//@author Sahaj_Khan
//Client Side

#include <iostream>
#include <string>
#include "MySocket.h"
using namespace std;
using boost::asio::ip::tcp;

int main()
{
    string message = "";

    cout << "Running Boost Client!!!" << endl;
    try {
        MySocket socket; //Create socket
        string port;

        cout << "what port would you like to use?" << endl;
        cin >> port;
        socket.connect(port);
       
        cout << "Connection established\n";
        do { //read write loop
            cout << socket.read() << endl;
            cout << "Type another message or \"Stop\" to stop\n";
            cin >> message;

            if (message != "STOP") {

                try {
                    socket.write(message);
                }
                catch (SocketClosedException& e) {
                    cout << e.what() << endl;
                    break;
                }
            }
            
        } while (message != "STOP");

        socket.close();


        

    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}