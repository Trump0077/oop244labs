#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BirthDate.h"
//#include "File.h"
using namespace std;

namespace sdds {
    int TotalRecords;
    info* birthdays;
    int globalmonth;
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

    bool read(char* stuName) {
        return fscanf(fptr, "%[^,],", stuName) == 1;
    }

    bool read(int& stumonth) {
        return fscanf(fptr, "%d/", &stumonth) == 1;
    }

    bool load(info& birthdays) {
        char sname[128];
        if (read(sname) && read(birthdays.month) && read(birthdays.date) && read(birthdays.year)) {
            birthdays.b_name = new char[strlen(sname) + 1];
            strcpy(birthdays.b_name, sname);

            // for(int i=0;i<(int)strlen(sname);i++){
            //         birthdays.b_name[i] = birthdays.b_name[i+1];
            // }
        }
        return true;
    }
    bool beginSearch(const char* filename) {
        globalmonth = 0;
        TotalRecords = 0;
        int i = 0, j = 0;
        if (openFile(filename)) {
            TotalRecords = noOfRecords();
            birthdays = new info[TotalRecords];  // this is where error is occuring
            for (j = 0; j < TotalRecords; j++) {
                i += load(birthdays[j]);
            }
            if (i != TotalRecords) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted.\n";
            }
            closeFile();
        }
        cout << "Birthdate search program\n";
        return true;
    }

    bool readBirthDate(int month) {
        for (int i = 0; i < TotalRecords; i++) {
            if (birthdays[i].month == month) {
                globalmonth = month;
                return true;
            }
        }
        return false;
    }
    void sort() {
        // sort the array by year and then by month
        int i, j;
        info temp;
        for (i = TotalRecords - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (birthdays[j].year > birthdays[j + 1].year) {
                    temp = birthdays[j];
                    birthdays[j] = birthdays[j + 1];
                    birthdays[j + 1] = temp;
                }
                else if (birthdays[j].year == birthdays[j + 1].year && birthdays[j].month > birthdays[j + 1].month) {
                    temp = birthdays[j];
                    birthdays[j] = birthdays[j + 1];
                    birthdays[j + 1] = temp;
                }
            }
        }

    }

    void displayBirthdays() {
        //count the number of records where months == globalmonth
        int count = 0, ind = 1;
        for (int i = 0; i < TotalRecords; i++) {
            if (birthdays[i].month == globalmonth) {
                count++;
            }
        }
        cout << count << " birthdates found:\n";
        for (int i = 0; i < TotalRecords; i++) {
            if (birthdays[i].month == globalmonth) {
                cout << ind << ") ";
                string s;
                for (int j = 1; j < (int)strlen(birthdays[i].b_name); j++) {
                    s += birthdays[i].b_name[j];
                }
                cout << s << ":" << endl;
                cout << birthdays[i].year << "-" << birthdays[i].month << "-" << birthdays[i].date << endl;
                cout << "===================================\n";
                ind++;
            }
        }
    }
    void deallocate() {

        for (int i = 0; i < TotalRecords; i++) {
            delete[] birthdays[i].b_name;
        }
        delete[] birthdays;

    }
    void endSearch() {
        cout << "Birthdate Search Program Closed.\n";
    }
}