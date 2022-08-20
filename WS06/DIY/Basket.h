/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		July 8, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

namespace sdds {

	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket {
		struct Fruit* m_fruits;
		int m_cnt;
		double m_price;

	public:
		Basket();
		Basket(const Fruit* fruits, int cnt, double price);
		Basket(const Basket& basket);
		~Basket();
		void setPrice(double price);
		operator bool() const;
		Basket& operator+=(Fruit fruit);
		void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, const Basket& b);
}

#endif
