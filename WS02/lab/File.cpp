/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 27, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   //my contributions
   bool read(char* name) { // reads name
       return fscanf(fptr, "%[^,],", name) == 1;
   }
   bool read(int& id) { // reads student id
       return fscanf(fptr, "%d,", &id) == 1;
   }
   bool read(char& grade) { //reads grade
       return fscanf(fptr, "%c\n", &grade) == 1;
   }

}