#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H

#include <iostream>
#include <string>
using namespace std;
namespace sdds {

    struct info {
        char* b_name;
        int month;
        int date;
        int year;
    };
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();

    //for reading name
    bool read(char* stuName);

    //for reading student number
    bool read(int& stumonth);
    bool beginSearch(const char* filename);
    bool readBirthDate(int month);
    void sort();
    void displayBirthdays();
    void deallocate();
    void endSearch();
}
#endif
