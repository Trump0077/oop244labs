//Name: Jiaheng Wang
//ID:	180562217
//Email:jwang522@myseneca.ca
//Date:	Aug 8, 2022
//Section: NKK

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	//Find with 3 parameters
	template <typename T1, typename T2>
	bool find(T1* t_Array, int index, T2 t_key) {
		return (t_Array[index] == t_key);
	}
	//Find with 4 parameters
	template <typename T1, typename T2, typename T3>
	int find(T1* t_Array, int size, T2 t_key1, T3 t_key2) {
		for (int i = 0; i < size; i++) {
			if (t_Array[i] == t_key1 && t_Array[i] == t_key2)
				return i;
			else
				return -1;
		}
	}
	//Insertion operator
	template <typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& t_col) {
		for (int i = 0; i < t_col.size(); i++) {
			os << t_col[i] << std::endl;
		}
		return os;
	}
	//Load Collection
	template <typename T>
	Collection<T>& loadCollection(Collection<T>& t_col, T t_item) {
		t_col += t_item;
		return t_col;
	}

}
#endif // !SDDS_SEARCH_H_

