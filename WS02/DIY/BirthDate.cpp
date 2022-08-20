/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 30, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BirthDate.h"
using namespace std;

namespace sdds {
	int noOfRecs = 0;
	int searchMonth;
	Birthday* bd;
	FILE* fptr;

	bool read(char* name) {
		return fscanf(fptr, "%[^,],", name) == 1;
	}

	bool read(int& date) {
		return fscanf(fptr, "%d/", &date) == 1;
	}

	bool load(Birthday& birthdays) {
		char name[128];
		if (read(name) && read(birthdays.m_month) && read(birthdays.m_day) && read(birthdays.m_year)) {
			birthdays.m_name = new char[strlen(name) + 1];
			strcpy(birthdays.m_name, name);
		}
		return true;
	}
	bool beginSearch(const char* filename) {
		char ch;
		fptr = fopen(filename, "r");
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		bd = new Birthday[noOfRecs];
		for (int i = 0; i < noOfRecs && load(bd[i]); i++);
		if (fptr != NULL) {
			cout << "Birthdate search program" << endl;
			return true;
		}
		else {
			cout << "Data file \"filename goes here\" not found!" << endl;
			return false;
		}	
		fclose(fptr);
	}
	bool readBirthDate(int month) {
		for (int i = 0; i < noOfRecs; i++) {
			if (bd[i].m_month == month) {
				searchMonth = month;
				return true;
			}
		}
		return false;
	}
	void sort() {
		int i, j;
		Birthday temp;
		for (i = noOfRecs - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (bd[j].m_year > bd[j + 1].m_year) {
					temp = bd[j];
					bd[j] = bd[j + 1];
					bd[j + 1] = temp;
				}
			}
		}
	}
	void displayBirthdays() {
		int matchRecs = 0, index = 1;
		for (int i = 0; i < noOfRecs; i++) {
			if (bd[i].m_month == searchMonth) {
				matchRecs++;
			}
		}
		cout << matchRecs << " birthdates found:" << endl;
		for (int i = 0; i < noOfRecs; i++) {
			if (bd[i].m_month == searchMonth) {
				cout << index << ") ";
				string s;
				for (int j = 1; j < (int)strlen(bd[i].m_name); j++) {
					s += bd[i].m_name[j];
				}
				cout << s << ":" << endl;
				cout << bd[i].m_year << "-" << bd[i].m_month << "-" << bd[i].m_day << endl;
				cout << "===================================" << endl;
				index++;
			}
		}
	}
	void deallocate() {
		for (int i = 0; i < noOfRecs; i++) {
			delete[] bd[i].m_name;
		}
		delete[] bd;
	}
	void endSearch() {
		fclose(fptr);
		cout << "Birthdate Search Program Closed." << endl;
	}
}
