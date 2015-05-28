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
	Book(){}
	Book(str &name, str &author, str &isbn, double price, str &className, stockNum num);
	std::fstream& binOutput(std::fstream &fout);
	std::fstream& binInput(std::fstream &fin);
	bool find(str &targetStr);
	Book& changeTo(str& name, str& author, str& isbn, double price, str& className, stockNum num);
	//template<typename Type> bool find(Type target){

	//}
	Book& operator=(Book& book);
	friend Book *sort(Book *bookArr, int arrSize, int order);
	friend std::ofstream &operator<<(std::ofstream &fout, Book &book);
	friend std::ostream &operator<<(std::ostream &out, Book &book);
	friend std::istream &operator>>(std::istream &in, Book &book);
};

#endif //BOOK_H_LIBSYS