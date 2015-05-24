#ifndef BOOK_H_LIBSYS
#define BOOK_H_LIBSYS

#include<iostream>
#include<fstream>
#include<cstring>
#include"main.h"

class Book{
protected:
	str isbn;
	str name;
	double price;
	str className;//className in lib
	stockNum num;
	static int counter;
public:
	Book(char(&isbn)[MAX_STR_LENGTH], char(&name)[MAX_STR_LENGTH], double price, char(&className)[MAX_STR_LENGTH], stockNum num);
	friend Book *sort(Book *bookArr, int arrSize, int order);
	friend std::ostream &operator<<(std::ostream &out, Book &book);
};

#endif //BOOK_H_LIBSYS