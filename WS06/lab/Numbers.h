/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 30, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& s);
      Numbers& operator=(const Numbers& s);
      double average()const;
      double max()const;
      double min()const;
      int numberCount();
      bool load();
      void save();
      Numbers& operator+=(const double number);
      std::ostream& display(std::ostream& ostr) const;
      ~Numbers();
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

