/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 12, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "MemberParliament.h"

using namespace std;

namespace sdds
{
    MemberParliament::MemberParliament(const char* id, int age)
    {
        strcpy(m_parliamentId, id);
        m_ageMP = age;
        strcpy(m_districtMP, "Unassigned");
    }

    void MemberParliament::NewDistrict(const char* district)
    {
        cout << "|" << right << setw(8) << m_parliamentId << "| |"
            << setw(20) << right << m_districtMP
            << " ---> "
            << setw(23) << left << district << "|\n";
        strcpy(m_districtMP, district);
    }

    ostream& MemberParliament::write(ostream& os) const
    {
        os << "| " << m_parliamentId << " | " 
            << m_ageMP << " | " << m_districtMP;
        return os;
    }

    istream& MemberParliament::read(istream& in)
    {
        cout << "Age: ";
        in >> m_ageMP;
        cout << "Id: ";
        in >> m_parliamentId;
        cout << "District: ";
        in >> m_districtMP;
        return in;
    }

    ostream& operator<<(ostream& os, const MemberParliament& mp)
    {
        return mp.write(os);
    }

    istream& operator>>(istream& in, MemberParliament& mp)
    {
        return mp.read(in);
    }
}