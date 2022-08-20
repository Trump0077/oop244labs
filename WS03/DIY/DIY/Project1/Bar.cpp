/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 2, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Bar.h"
using namespace std;

namespace sdds {

	void Bar::setEmpty() {
		m_title[0] = '\0';
		m_fillChar = '\0';
		m_noOfBars = -1;
	}
	void Bar::set(const char* title, char fillChar, int noOfBars) {
		if (noOfBars >= 0 && noOfBars <= 100) {
			strcpy(m_title, title);
			m_fillChar = fillChar;
			m_noOfBars = noOfBars;
		}
		else {
			setEmpty();
		}
	}
	bool Bar::isValid() const {
		if (m_noOfBars < 0 || m_noOfBars > 100) {
			return false;
		}
		return true;
	}
	void Bar::draw() const {
		if (isValid()) {
			cout.setf(ios::left);
			cout << setfill('.') << setw(20) << m_title << "|";
			for (int i = 0; i < m_noOfBars / 2; i++) {
				cout << m_fillChar;
			}
			cout << endl;
		}
	}
}