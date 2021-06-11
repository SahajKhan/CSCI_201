/*
@author Sahaj Khan
Last updated : 2-28-21
*/

#include <iostream>
#include <set>
#include <fstream>
#include <map>

using namespace std;

void setthing() {
    set <string> s;
    ifstream inputFile;
    inputFile.open("somefile.txt");
    string in;

    while(inputFile) {
        inputFile >> in;
        s.insert(in);
    }
    
    set<string, greater<string>>::iterator it;
    for (it = s.begin(); it !=s.end(); it++) {
        cout << *it << " ";
    }
    
    inputFile.close();
}


void mapthing() {
    map <string, string> stateLongName;
    map <string, string> stateBird;
    map <string, string>::iterator it;

    ifstream inputFile;
    inputFile.open("somefile.txt");
    string in1,in2;

    while(inputFile) {
        inputFile >> in1; //Get the 2 letter abbreviation
        stateLongName[in1];
        stateBird[in1];

        //retrieve Long name
        inputFile >> in2;
        stateLongName[in1] = in2;

        //retrieve Bird
        inputFile >> in2;
        stateLongName[in1] = in2;
    }

    while (true) {
        cout << "Inser the two letter abbreviation for the state.";
        cin >> in1;

        it = stateLongName.find(in1);
        try {
            if (it == stateLongName.end())
                throw invalid_argument(in1 + " does not exist");
        } catch (invalid_argument e) {
            cout << e.what();
            continue;
        }

        cout << in1 << " " << stateLongName[in1] << " " << stateBird[in1] << endl;

        cout << "Press any key to try again, enter \'N\' to stop";
        cin >> in2;
        if (in2 == "n" || in2 == "N")
            break;
        
    }
}

int main() {}
