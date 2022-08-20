/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 21, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "iAccount.h"
#include "Account.h"
#include <iostream>

namespace sdds {
	class SavingsAccount :public Account {
		double m_iRate;

	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}

#endif