/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 2, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H

#include "Bar.h"

namespace sdds {

    class BarChart {
        char* m_title;
        Bar* m_bar;
        char m_fillCharacter; 
        int m_noOfSamples; 
        int m_addSamples;
        
        void setEmpty();
        bool isValid() const;

    public:

        void init(const char* title, int noOfSamples, char fill);
        void add(const char* bar_title, int value);
        void draw() const;
        void deallocate();
    };

}

#endif 
