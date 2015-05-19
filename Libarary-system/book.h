#ifndef BOOK_H
#define BOOK_H

template<class T>
Book<T> *sort(T &t, int dir){

}

template<typename T>
class Book{
protected:
	char *isbn;
	char *name;
	int price;
	char *position;
	bool inLib;
	static int counter;
public:
	Book();
	~Book();
	friend Book<T> *sort(T &t, int dir);

};



#endif //BOOK_H