/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 8, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <cstring>
#include "Basket.h"

using namespace std;

namespace sdds {
	// the default constructor
	Basket::Basket() {
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;
	}
	// the custom constructor
	Basket::Basket(const Fruit* fruits, int cnt, double price) {
		if (fruits != nullptr && cnt > 0 && price > 0) {
			m_fruits = new Fruit[cnt];
			for (int i = 0; i < cnt; i++) {
				m_fruits[i] = fruits[i];
			}
			m_cnt = cnt;
			m_price = price;
		}
		else {
			*this = Basket();
		}
	}
	// the copy constructor
	Basket::Basket(const Basket& basket) {
		m_cnt = basket.m_cnt;
		m_price = basket.m_price;
		if (basket.m_fruits != nullptr) {
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = basket.m_fruits[i];
			}
		}
		else {
			*this = Basket();
		}
	}
	//destructor
	Basket::~Basket() {
		delete[] m_fruits;
	}

	void Basket::setPrice(double price) {
		m_price = price;
	}

	Basket::operator bool() const {
		return m_fruits != nullptr;
	}

	Basket& Basket::operator+=(Fruit fruit) {
		if (*this) {
			int rezise = m_cnt;
			Fruit temp[20]{};
			for (int i = 0; i < rezise; i++) {
				temp[i] = m_fruits[i];
			}
			delete[] m_fruits;
			
			temp[rezise] = fruit;
			rezise = ++m_cnt;
			m_fruits = new Fruit[rezise];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = temp[i];
			}
		}
		else {
			m_fruits = new Fruit[1];
			m_fruits[0] = fruit;
			m_cnt = 1;
		}
		return *this;
	}

	void Basket::display(ostream& os) const {
		if (m_fruits != nullptr && m_cnt > 0 && m_price > 0) {
			os << "Basket Content:" << endl;
			for (int i = 0; i < m_cnt; i++) {
				cout.width(10);
				os << m_fruits[i].m_name << ": ";
				cout.setf(ios::fixed);
				cout.precision(2);
				os << m_fruits[i].m_qty << "kg" << endl;
				cout.unsetf(ios::fixed);
			}
			cout.setf(ios::fixed);
			cout.precision(2);
			os << "Price: " << m_price << endl;
			cout.unsetf(ios::fixed);
		}
		else {
			os << "The basket is empty!" << endl;
		}
	}

	std::ostream& operator<<(ostream& os, const Basket& b) {
		b.display(os);
		return os;
	}
}