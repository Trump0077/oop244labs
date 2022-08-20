/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 12, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include <iostream>
#include "MemberParliament.h"

namespace sdds
{
	class Minister : public MemberParliament
	{
		char m_name[50]; // The name of the Prime Minister
		double m_year;    // The year the minister assumed office

	public:
		Minister(const char* id, int age, double year, const char* district, const char* name);
		void changePM(const char* pm);
		void assumeOffice(double year);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::istream& operator>>(std::istream& in, Minister& m);
	std::ostream& operator<<(std::ostream& out, const Minister& m);
}
#endif