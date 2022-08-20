/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 30, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

   //Default constructor 
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }
   //Destructor
   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   //Copy Constructor 
   Numbers::Numbers(const Numbers& s) {
       setEmpty();
       m_isOriginal = false;
       operator = (s);
   }
   //Copy Assignment Operator
   Numbers& Numbers::operator=(const Numbers& s) {
       delete[]  m_numbers;
       m_numCount = s.m_numCount;
       m_numbers = new double[s.m_numCount];
       for (int i = 0; i < s.m_numCount; i++) {
           m_numbers[i] = s.m_numbers[i];
       }
       return *this;
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
   int Numbers::numberCount() {
       m_numCount = 0;
       string str;
       ifstream filein(m_filename);
       while (getline(filein, str)) {
           m_numCount++;
       }
       return m_numCount;
   }
   bool Numbers::load() {
       int rows = 0;
       if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           ifstream filein(m_filename);
           string str;
           while (!filein.fail() && rows < m_numCount) {
               filein >> m_numbers[rows];
               rows++;
           }
       }
       if (rows == m_numCount) {
           return true;
       }
       return false;
   }
   void Numbers::save() {
       if (m_isOriginal == true && !isEmpty()) {
           ofstream fileout(m_filename, ios::trunc);
           for (int i = 0; i < m_numCount; i++) {
               fileout << m_numbers[i] << endl;
           }
       }
   }
   Numbers& Numbers::operator+=(const double number) {
       if (!isEmpty()) {
           m_numCount++;
           double* newNumbers = nullptr;
           newNumbers = new double[m_numCount];
           for (int i = 0; i < m_numCount - 1; i++) {
               newNumbers[i] = m_numbers[i];
           }
           newNumbers[m_numCount - 1] = number;
           delete[] m_numbers;
           m_numbers = newNumbers;
           sort();
       }
       return *this;
   }
   std::ostream& Numbers::display(std::ostream& ostr) const {
       if (isEmpty()) {
           cout << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           if (m_isOriginal) {
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }
           for (int i = 0; i < m_numCount - 1; i++) {
               ostr << m_numbers[i] << ", ";
           }
           ostr << m_numbers[m_numCount - 1] << endl;
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average :        " << average() << endl;
           ostr << "=========================";
       }
       return ostr;
   }
   std::ostream& operator<<(std::ostream& os, const Numbers& N) {
       return N.display(os);
   }
   std::istream& operator>>(std::istream& istr, Numbers& N) {
       double d;
       istr >> d;
       N += d;
       return istr;
   }
   
}
