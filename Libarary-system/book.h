#ifndef BOOK_H
#define BOOK_H

#include"main.h"

template<typename T>
class Book{
protected:
	char *isbn;
	char *name;
	T price;
	char *className;//className in lib
	bool inLib;
	static int counter;
public:
	Book();
	Book(char &isbn, char &name, T price, char &className, bool inLib);
	~Book();
	friend Book<T> *sort(T &book, int order);
};

template<class T>
Book<T> *sort(T &book, int order){
	switch (order){
	case SMALL_TO_LARGE:

		break;
	case LARGE_TO_SMALL:

		break;
	default:

		break;
	}
}

//template<typename T>
//Book<T>::Book(){
//	isbn = nullptr;
//	name = nullptr;
//	price = 0;
//	className = nullptr;
//	inLib = 0;
//}

template<typename T>
Book<T>::Book(char &isbn, char &name, T price, char &className, bool inLib){
	this->isbn = isbn; 
	this->name = name; 
	this->price = price; 
	this->className = className; 
	this->inLib = inLib;
}

template<typename T>
Book<T>::~Book(){
	isbn = nullptr;
	name = nullptr;
	price = 0;
	className = nullptr;
	inLib = 0;
}

#endif //BOOK_H