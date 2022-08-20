/*
NAME:		JIAHENG WANG
EMAIL:		JWANG522@MYSENECA.CA
STUDENT ID:	180562217
DATE:		MAY 20, 2022
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "File.h"

using namespace std;

namespace sdds {

	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
	FILE* sfptr = nullptr;

	bool openFileForRead() {
		sfptr = fopen(SHOPPING_DATA_FILE, "r");
		return sfptr != NULL;
	}

	bool openFileForOverwrite() {
		sfptr = fopen(SHOPPING_DATA_FILE, "w");
		return sfptr != NULL;
	}

	void closeFile() {
		if (sfptr) fclose(sfptr);
	}

	bool freadShoppingRec(ShoppingRec* rec) {
		int flag = 0;
		bool success = fscanf(sfptr, "%[^,],%d,%d\n",
			rec->m_title, &rec->m_quantity, &flag) == 3;
		rec->m_bought = !!flag;
		return success;
	}

	void fwriteShoppintRec(const ShoppingRec* rec) {
		fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
	}

}