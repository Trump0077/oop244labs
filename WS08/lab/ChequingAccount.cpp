/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 21, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include "iAccount.h"
#include "Account.h"
#include "ChequingAccount.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
	ChequingAccount::ChequingAccount(double balance, double tFee, double mFee) :Account(balance) {
		if (tFee >= 0) {
			m_transactionFee = tFee;
		}
		else {
			m_transactionFee = 0;
		}

		if (mFee >= 0) {
			m_monthlyFee = mFee;
		}
		else {
			m_monthlyFee = 0;
		}
	}

	bool ChequingAccount::credit(double amt) {
		if (Account::credit(amt)) {
			Account::debit(m_transactionFee);
			return true;
		}
		return false;
	}

	bool ChequingAccount::debit(double amt) {
		if (Account::debit(amt)) {
			Account::debit(m_transactionFee);
			return true;
		}
		return false;
	}

	void ChequingAccount::monthEnd() {
		Account::debit(m_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& out) const {
		out << "Account type: Chequing" << endl;
		out << fixed << setprecision(2) << "Balance: $" << balance() << endl;
		out << "Per Transaction Fee: " << fixed << setprecision(2) << m_transactionFee << endl;
		out << "Monthly Fee: " << fixed << setprecision(2) << m_monthlyFee << endl;
	}

}