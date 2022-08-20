/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 27, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
using namespace std;

namespace sdds {
    int noOfStudents;
    Student* students;

    void sort() {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (students[j].m_grade > students[j + 1].m_grade) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }
    bool load(Student& stu) {
        char name[128];       
        if (read(name) && read(stu.m_studentNumber) && read(stu.m_grade)) {
            stu.m_name = new char[strlen(name) + 1];
            strcpy(stu.m_name, name);            
            return true;
        }
        else {
            return false;
        }
    }
    bool load(const char* filename) {
        if (openFile(filename)) {
            noOfStudents = noOfRecords();
            students = new Student[noOfStudents];
            int i;
            for (i = 0; i < noOfStudents && load(students[i]); i++);
            if (i != noOfStudents) {
                std::cout << "Error: incorrect number of records read; the data is possibly corrupted."
                    << std::endl;
                closeFile();
                return false;
            }
            else {
                closeFile();
                return true;
            }
        }
        else {
            closeFile();
            return false;
        }
    }
    void display(const Student& stu) {
        std::cout << stu.m_name << ", " << stu.m_studentNumber << ": " << stu.m_grade << std::endl;
    }
    void display() {
        sort();
        for (int i = 0; i < noOfStudents; i++ ) {
            std::cout << i + 1 << ": ";
            display(students[i]);
        }
    }
    void deallocateMemory() {
        for (int i = 0; i < noOfStudents; i++) {
            delete[] students[i].m_name;
        }
        delete[] students;
    }
}