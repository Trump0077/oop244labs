/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 2, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include "BarChart.h"
using namespace std;

namespace sdds {

	void BarChart::setEmpty() {
		m_title[0] = '\0';	
		m_bar = nullptr;
		m_fillCharacter = '\0';
		m_noOfSamples = -1;
		m_addSamples = -1;
	}
	void BarChart::init(const char* title, int noOfSamples, char fill) {
		if (title[0] == '\0' || noOfSamples <= 0) {
			setEmpty();
		}
		else {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			m_noOfSamples = noOfSamples;
			m_fillCharacter = fill;
			m_addSamples = 0;
			m_bar = new Bar[m_noOfSamples];
			for (int i = 0; i < m_noOfSamples; i++) {
				m_bar[i].setEmpty();
			}
		}
	}
	void BarChart::add(const char* bar_title, int value) {
		if (m_addSamples < m_noOfSamples) {
			m_bar[m_addSamples].set(bar_title, m_fillCharacter, value);
			m_addSamples++;
		}
	}
	bool BarChart::isValid() const {		
		bool val = true;
		for (int i = 0; i < m_noOfSamples && val; i++) {
			if (!m_bar[i].isValid()) {
				val = false;
			}
		}
		return val;		
	}
	void BarChart::draw() const {
		if (isValid()) {
			cout << m_title << endl;
			cout << setfill('-') << setw(71) << '-' << endl;
			for (int i = 0; i < m_noOfSamples; i++) {
				m_bar[i].draw();
			}
			cout << setfill('-') << setw(71) << '-' << endl;
		}
		else {
			cout << "Invalid Chart!" << endl;
		}
	}
	void BarChart::deallocate() {
		delete[] m_title;
		delete[] m_bar;
		setEmpty();
	}
	
}