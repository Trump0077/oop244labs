/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 21, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include "Account.h"
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sdds {
	SavingsAccount::SavingsAccount(double balance, double iRate) :Account(balance) {
		if (iRate >= 0) {
			m_iRate = iRate;
		}
		else {
			m_iRate = 0;
		}
	}

	void SavingsAccount::monthEnd() {
		double Interest = balance() * m_iRate;
		credit(Interest);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings";
		os << fixed << setprecision(2) << endl;
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << fixed << setprecision(2) << m_iRate * 100 << endl;
	}
}