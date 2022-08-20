/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		June 2, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Army.h"
using namespace std;

namespace sdds {

	void Army::setEmpty(){
		nationality[0] = '\0';
		m_units = 0;
		m_power = 0.0;
	}
	void Army::createArmy(const char* country, double pow, int troops){
		if (country == nullptr || sizeof(country) < 0 || pow < 0 || troops < 0) {
			setEmpty();
		}
		else {
			strncpy(nationality, country, MAX_NAME_LEN);
			m_units = troops;
			m_power = pow;
		}
	}
	void Army::updateUnits(int troops){
		m_units += troops;
		m_power += troops * 0.25;
	}
	const char* Army::checkNationality() const{
		return nationality;
	}
	int Army::checkCapacity() const{
		return m_units;
	}
	double Army::checkPower() const{
		cout << setiosflags(ios::fixed) << setprecision(1);
		return m_power;
	}
	bool Army::isEmpty() const{
		if (nationality[0] == '\0' ||
			m_units == 0 ||
			m_power == 0.0) {
			return true;
		}
		return false;
	}
	bool Army::isStrongerThan(const Army& army)const{
		if (m_power > army.m_power) {
			return true;
		}
		return false;
	}
	void battle(Army& arm1, Army& arm2){
		if (arm1.isStrongerThan(arm2)) {
			arm2.updateUnits(-arm2.checkCapacity() / 2);
			cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality()
				<< ", " << arm1.checkNationality() << " is victorious!" << endl;
		}
		else {
			arm1.updateUnits(-arm1.checkCapacity() / 2);
			cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality()
				<< ", " << arm2.checkNationality() << " is victorious!" << endl;
		}
	}
	void displayDetails(const Army* armies, int size){
		cout << "Armies reporting to battle: " << endl;
		for (int i = 0; i < size; i++) {
			if (!armies[i].isEmpty()) {
				cout << "Nationality: " << armies[i].checkNationality() << ", "
					<< "Units Count: " << armies[i].checkCapacity() << ", "
					<< "Power left: " << armies[i].checkPower() << endl;
			}
		}

	}
}