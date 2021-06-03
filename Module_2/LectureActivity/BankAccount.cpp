//Header Comment
#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;


	BankAccount::BankAccount(string accountNumber, string accountHolder, string ssn, string pin, double initialDeposit) {
		
		if (accountNumber.size() != 10) {
			throw invalid_argument("Account number must be size 10");
		}
		try {
			if (initialDeposit < 0) {
				throw underflow_error("Deposit must be >= 0");
			}
			balance = initialDeposit;
		}
		catch (underflow_error& e) {
			cout << e.what() << endl;
			cout << "Setting balance to zero" << endl;
			balance = 0;
		}
		
		this->accountNumber = accountNumber;
		this->accountHolder = accountHolder;
		this->ssn = ssn;
		
		routingNumber = "01342345";
		this->pin = pin;
		cout << "Opening Bank Account " << accountNumber << " with deposit of " << initialDeposit << endl;

	}
	BankAccount::~BankAccount() {
		cout << "Closing Account " << accountNumber << endl;
		if (balance > 0) {
			cout << "Issuing check to " << accountHolder << " for $" << balance << endl;
		}
		else if (balance < 0) {
			cout << "Turning " << accountHolder << " over to collections department!!!" << endl;
		}
		cout << "Have a nice day!!!" << endl;
	}
	
	double BankAccount::getBalance() const{
		return balance;
	}
	
	string BankAccount::getAccountHolder() const{
		return accountHolder;
	}
	
	void BankAccount::deposit(string pin, double amount) {
		if (amount < 0) {
			throw underflow_error("Deposit must be greater than 0");
		}
		cout << "Depositing $ " << amount << " to " << accountNumber << endl;
		balance += amount;
	}
	
	void BankAccount::withdraw(string pin, double amount) {
		try {
			if (getPin() != pin)
				throw invalid_argument("The pin is incorrect!");
			if (amount > balance) {
				throw underflow_error("Cannot withdraw more than balance");
			}
		}
		catch (underflow_error& e) {
			cout << "Sending email to accountholder!!!!";
			throw;  // rethrows the exception
		}
		catch (invalid_argument& e) {
			cout << "Sending recovery code to email!";
		}
		cout << "Withdrawing $ " << amount << " from " << accountNumber << endl;
		balance -= amount;

	}
	
	void BankAccount::changePIN(string old_pin, string newPin) {
		if (old_pin == getPin())
			pin = newPin;
		try {
			if (old_pin != getPin())
				throw invalid_argument("The pin is not correct!");
		} catch (invalid_argument& e) {
			cout << "Sending recovery code to email!";
		}
	}

	string BankAccount::getPin() {
		return BankAccount::pin;
	}

	void BankAccount::setPin(string pin) {
		this->pin = pin;
	}


