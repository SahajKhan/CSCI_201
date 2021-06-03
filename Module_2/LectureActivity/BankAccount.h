#pragma once
//Header Comment
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
	string accountNumber;
	string routingNumber;
	string accountHolder;
	double balance;
	string pin;
	string ssn;
public:
	BankAccount(string accountNumber, string accountHolder, string ssn, string pin, double initialDeposit = 0.00);
	~BankAccount();
	double getBalance() const;
	string getAccountHolder() const;
	void deposit(string pin, double amount) ;
	void withdraw(string pin, double amount) ;  //defensive programming -> secure programming
	void changePIN(string old_pin, string newPin) ;
	string getPin();
	void setPin(string pin);
};
