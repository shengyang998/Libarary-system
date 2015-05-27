#ifndef BOOK_H_LIBSYS
#define BOOK_H_LIBSYS

#include"main.h"

class Book{
public:
	static int counter;
protected:
	str name;
	str author;
	str isbn;
	double price;
	str className;//className in lib
	stockNum num;

public:
	Book(str &name, str &author, str &isbn, double price, str &className, stockNum num);
	std::ofstream& Book::binOutput(std::ofstream &fout);
	friend Book *sort(Book *bookArr, int arrSize, int order);
	friend std::ostream &operator<<(std::ostream &out, Book &book);
	friend std::istream &operator>>(std::istream &in, Book &book);
};

#endif //BOOK_H_LIBSYS