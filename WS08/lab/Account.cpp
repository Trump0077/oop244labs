/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 21, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include "Account.h"
#include "iAccount.h"

namespace sdds {
	Account::Account(double balance) {
		if (balance <= 0) {
			currentBalance = 0;
		}
		else {
			currentBalance = balance;
		}
	}

	bool Account::credit(double amt) {
		if (amt >= 0) {
			currentBalance += amt;
			return true;
		}
		return false;
	}

	bool Account::debit(double amt) {
		if (amt >= 0) {
			currentBalance -= amt;
			return true;
		}
		return false;
	}

	double Account::balance() const {
		return currentBalance;
	}

	iAccount::~iAccount() {

	}
}