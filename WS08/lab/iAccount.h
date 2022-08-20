/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 21, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef IACCOUNT_H
#define IACCOUNT_H

#include <iostream>

namespace sdds {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount();
	};
	iAccount* CreateAccount(const char*, double);
}

#endif