/* Program name: CaesarEncryption.cpp
*  Author: Sahaj Khan
*  Date last updated: 2/14/2021
*  Purpose: Encrypt and decrypt a text message using a Caesar encryption scheme.
*  This will expand upon the simple Caesar scheme to incorporate the printable range of ASCII characters (i.e. Decimal 32 to 136).
*/

#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key);
string decrypt(string text, int key);

int main() {
    string text;
    int key;

    cout << "Please enter the string you would like to encrypt\n";
    cin >> text;
    cout << "\nPlease enter the cypher key\n";
    cin >> key;

    cout << "Your encrypted message is: " << encrypt(text, key) << endl;

    cout << "Please enter the string you would like to de-crypt\n";
    cin >> text;
    cout << "\nPlease enter the cypher key\n";
    cin >> key;

    cout << "Your decrypted message is: " << decrypt(text, key) << endl;
}


string encrypt(string text, int key) {
    char character;

    for (int i = 0; i < text.size(); i++) {
        if (key + text.at(i) > 136) {                   //If the ACII value plus the key exceeds the 136 limit
            character = key + text.at(i) - 136 + 32;  //Take the difference of the total (original ACII + key) and 136, then add it to 32
            text[i] = character;
        }
        else {
            character = text.at(i) + key;
            text[i] = character;
        }
    }

    return text;        
}

string decrypt(string text, int key) {
    char character;

    for (int i = 0 ; i < text.size(); i++) {
        if (text.at(i) - key < 32) {         //If the ACII value minus the key is below the 32 limit
            character = text.at(i) - key - 32 + 136;
            text[i] = character;
        }
        else {
            character = text.at(i) -key;
            text[i] = character;
        }
    }

    return text;
}
