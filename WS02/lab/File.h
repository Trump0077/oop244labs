/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 27, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   //my contributions
   bool read(char*);
   bool read(int&);
   bool read(char&);
  
}
#endif // !SDDS_FILE_H_
