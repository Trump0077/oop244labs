/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 27, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include <iostream>
#include <cstring>
#include "File.h"

namespace sdds {
    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };
    void sort();
    bool load(Student&);
    bool load(const char*);
    void display(const Student&);
    void display();
    void deallocateMemory();
}

#endif