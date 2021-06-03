// Header Comment
#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;


int main() {

	string accountHolder, accountNumber,ssn,pin;
	double initialDeposit, amount;
	cout << "Enter AccountHolder: ";
	cin >> accountHolder;
	cout << "Enter AccountNumber: ";
	cin >> accountNumber;
	cout << "Enter SSN: ";
	cin >> ssn;
	cout << "Enter PIN: ";
	cin >> pin;
	cout << "Enter initial deposit: ";
	cin >> initialDeposit;


	// create block just to ensure destructor is called before program ends;
	{
		try {
			BankAccount myAccount(accountNumber, accountHolder, ssn, pin, initialDeposit);

			cout << "Your balance is: " << myAccount.getBalance() << endl;

			try {
				cout << "How much would you like to deposit? ";
				cin >> amount;

				myAccount.deposit(pin, amount);
			}
			catch (underflow_error& e) {
				cout << "Underflow Exception: ";
				cout << e.what();
			}

			cout << "Your balance is: " << myAccount.getBalance() << endl;


			try {
				cout << "How much would you like to withdraw? ";
				cin >> amount;

				myAccount.withdraw(pin, amount);
			}
			catch (underflow_error& e) {
				cout << "Underflow Exception: ";
				cout << e.what();
			}
			cout << "Your balance is: " << myAccount.getBalance() << endl;

			

		}  //destructor would be called here
		catch (invalid_argument &e) {
			cout << "Invalid Argument Exception Encountered: ";
			cout << e.what() << endl;

		}
	}

	cout << "Thank you for banking at Bank of CSCI 201!!!!" << endl;

	return 0;
}