/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 7, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Car.h"
using namespace std;

namespace sdds {

	void Car::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0.0;
	}
	Car::Car() :m_type{ nullptr }, m_brand{ nullptr }, m_model{ nullptr },
		m_year{ 0 }, m_code{ 0 }, m_price{ 0.0 } {
		Car::resetInfo();
	}
	Car::Car(const char* type, const char* brand, const char* model,
		int year, int code, double price) {
		if (type && brand && model && year >= 1990 &&
			code >= 100 && code <= 999 && price > 0) {
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
	}
	Car::~Car() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}
	Car& Car::setInfo(const char* type, const char* brand, const char* model,
		int year, int code, double price) {
			delete[] m_type;
			delete[] m_brand;
			delete[] m_model;
		if (type && brand && model && year >= 1990 &&
			code >= 100 && code <= 999 && price > 0) {
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
		return *this;
	}
	void Car::printInfo() const {
		cout << "| " << setw(10) << left << m_type;
		cout << " | " << setw(16) << left << m_brand;
		cout << " | " << setw(16) << left << m_model;
		cout << " | " << m_year;
		cout << " | " << setw(4) << right << m_code;
		cout << " | " << fixed << setw(9) << setprecision(2) << right <<
			m_price;
		cout << " |" << endl;
	}
	bool Car::isValid() const {
		if (m_type && m_brand && m_model && m_year >= 1990 && 
			m_code >= 100 && m_code <= 999 && m_price > 0) {
			return true;
		}
		return false;
	}
	bool Car::isSimilarTo(const Car& car) const {
		if (car.isValid() && this->isValid()) {
			if (strcmp(m_type, car.m_type) == 1 && strcmp(m_brand,
				car.m_brand) == 1 && strcmp(m_model, car.m_model) == 1) {
				return true;
			}
			return false;
		}
		return true;
	}
	bool has_similar(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return true;
				}
			}
		}
		return false;
	}
	bool has_invalid(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			if (!car[i].isValid()) {
				return true;
			}
		}
		return false;
	}
	void print(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			if (car[i].isValid()) {
				car[i].printInfo();
			}
		}
	}
}