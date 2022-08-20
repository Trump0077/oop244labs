/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 30, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H
#include <iostream>
#include <cstring>

namespace sdds {
	struct Birthday {
		char* m_name;
		int m_month;
		int m_day;
		int m_year;
	};
	bool read(char* name);
	bool read(int& date);
	bool load(Birthday& birthdays);
	bool beginSearch(const char* filename);
	bool readBirthDate(int month);
	void sort();
	void displayBirthdays();
	void deallocate();
	void endSearch();	
}

#endif