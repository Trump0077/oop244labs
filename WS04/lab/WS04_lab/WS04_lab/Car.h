/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 7, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds {

	class Car {
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;

		void resetInfo();
	public:
		//Constructors
		Car();
		Car(const char* type,
			const char* brand,
			const char* model,
			int year = 2022,
			int code = 100,
			double price = 1);
		//Destructor
		~Car();
		//Public Members
		Car& setInfo(const char* type,
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const Car& car) const;
	};
	//Global helper functions
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);
}

#endif 
