/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 12, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <cstring>
#include "Minister.h"
#include "MemberParliament.h"

using namespace std;

namespace sdds
{
	Minister::Minister(const char* id, int age, double year, 
		const char* name, const char* district) : MemberParliament(id, age)
	{
		strcpy(m_name, name);
		m_year = year;
		NewDistrict(district);
	}

	void Minister::changePM(const char* pm)
	{
		strcpy(m_name, pm);
	}

	void Minister::assumeOffice(double year)
	{
		m_year = year;
	}

	std::ostream& Minister::write(std::ostream& os) const
	{
		MemberParliament::write(os);
		os << " | " << m_name << "/" << m_year;
		return os;
	}

	std::istream& Minister::read(std::istream& in)
	{
		MemberParliament::read(in);
		cout << "Reports TO: ";
		in >> m_name;
		cout << "Year Assumed Office: ";
		in >> m_year;

		return in;
	}

	istream& operator>>(istream& in, Minister& m)
	{
		return m.read(in);
	}

	ostream& operator<<(ostream& os, const Minister& m)
	{
		return m.write(os);
	}
}