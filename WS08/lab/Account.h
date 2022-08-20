/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 21, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "iAccount.h"
namespace sdds {
	class Account :public iAccount {
		double currentBalance;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);
	protected:
		double balance() const;
	};
}

#endif