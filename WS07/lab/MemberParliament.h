/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 12, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include<iostream>

namespace sdds
{
	class MemberParliament
	{
		char m_parliamentId[32];
		char m_districtMP[64];
		int m_ageMP;

	public:
		MemberParliament(const char* id, int age);
		void NewDistrict(const char* district);

		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os) const;
	};

	std::istream& operator>>(std::istream& in, MemberParliament& mp);
	std::ostream& operator<<(std::ostream& os, const MemberParliament& mp);
}

#endif
