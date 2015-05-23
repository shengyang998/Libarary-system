#ifndef BOOK_H_LIBSYS
#define BOOK_H_LIBSYS

#include"main.h"

class Book{
protected:
	str isbn;
	str name;
	double price;
	str className;//className in lib
	bool inLib;
	static int counter;
public:
	Book(char(&isbn)[MAX_STR_LENGTH], char(&name)[MAX_STR_LENGTH], double price, char(&className)[MAX_STR_LENGTH], bool inLib);
	friend Book *sort(int order);
};

Book::Book(char(&isbn)[MAX_STR_LENGTH], char(&name)[MAX_STR_LENGTH], double price, char(&className)[MAX_STR_LENGTH], bool inLib){
	strcpy_s(this->isbn,MAX_STR_LENGTH, isbn);
	strcpy_s(this->name, MAX_STR_LENGTH, name);
	this->price = price;
	strcpy_s(this->className, MAX_STR_LENGTH, className);
	this->inLib = inLib;
}

#endif //BOOK_H_LIBSYS