/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 13, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include "CleanerBot.h"
using namespace std;

namespace sdds {

	CleanerBot::CleanerBot() {
		m_location = nullptr;
		m_battery = 0;
		m_brush = 0;
		m_active = false;
	}
	CleanerBot::CleanerBot(const char* location, const double battery,
		const int brush, const bool active) {
		m_location = new char[strlen(location) + 1];
		strcpy(m_location, location);
		m_battery = battery;
		m_brush = brush;
		m_active = active;
	}
	CleanerBot::~CleanerBot() {
		delete[] m_location;
	}
	CleanerBot& CleanerBot::set(const char* location, const double battery,
		const int brush, const bool active) {
		delete[] m_location;
		m_location = new char[strlen(location) + 1];
		strcpy(m_location, location);
		m_battery = battery;
		m_brush = brush;
		m_active = active;
		return *this;
	}
	CleanerBot CleanerBot::setLocation(const char* location) {
		delete[] m_location;
		m_location = new char[strlen(location) + 1];
		strcpy(this->m_location, location);
		return *this;
	}
	void CleanerBot::setActive(const bool active) {
		m_active = active;
	}
	char* CleanerBot::getLocation() const {
		return this->m_location;
	}
	double CleanerBot::getBettery() const {
		return this->m_battery;
	}
	int CleanerBot::getBrush() const {
		return this->m_brush;
	}
	bool CleanerBot::isActive() const {
		return this->m_active;
	}
	bool CleanerBot::isValid() const {
		if (m_location != nullptr && m_battery >= 0 && m_brush >= 0) {
			return true;
		}
		return false;
	}
	void CleanerBot::display() {
		cout << "| " << setw(10) << left << m_location;
		cout << " | " << setw(7) << right << fixed << setprecision(1) << m_battery;
		cout << " | " << setw(18) << right << m_brush;
		if (isActive()) {
			cout << " | " << setw(7) << left << "YES" << "|" << endl;
		}
		else {
			cout << " | " << setw(7) << left << "NO" << "|" << endl;
		}
	}
	int report(CleanerBot* bot, short num_bots) {
		int needCharge = 0;
		cout << "         ------ Cleaner Bots Report -----" << endl;
		cout << "     ---------------------------------------" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
		for (int i = 0; i < num_bots; i++) {
			if (bot[i].isValid()) {
				bot[i].display();
				if (bot[i].getBettery() < 30) {
					needCharge++;
				}
			}
		}
		cout << endl;
		cout << "|====================================================|" << endl;
		cout << "| LOW BATTERY WARNING:                               |" << endl;
		cout << "|====================================================|" << endl;
		cout << "| Number of robots to be charged: ";
		cout << setw(19) << left << needCharge << "|" << endl;
		cout << "| Sorting robots based on their available power:     |" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
		CleanerBot temp;
		for (int j = 0; j < num_bots - 1; j++) {
				for (int i = 0; i < num_bots - 1 - j; i++) {
					if (bot[i].getBettery() < bot[i + 1].getBettery()) {
						temp = bot[i];
						bot[i] = bot[i + 1];
						bot[i + 1] = temp;
					}
				}
		}
		for (int i = 0; i < num_bots; i++) {
			if (bot[i].isValid()) {
				bot[i].display();
			}
		}
		cout << "|====================================================|" << endl;
		return 0;
	}
}
