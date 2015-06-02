#include"main.h"
#include"book.h"

Book::Book(str &name, str &author, str &isbn, double price, str &className, stockNum num){
	strcpy_s(this->isbn, STD_STR_LENGTH, isbn);
	strcpy_s(this->author, STD_STR_LENGTH, author);
	strcpy_s(this->name, STD_STR_LENGTH, name);
	this->price = price;
	strcpy_s(this->className, STD_STR_LENGTH, className);
	this->num = num;
}

Book& Book::changeTo(str& name, str& author, str& isbn, double price, str& className, stockNum num){
	strcpy_s(this->isbn, STD_STR_LENGTH, isbn);
	strcpy_s(this->author, STD_STR_LENGTH, author);
	strcpy_s(this->name, STD_STR_LENGTH, name);
	this->price = price;
	strcpy_s(this->className, STD_STR_LENGTH, className);
	this->num = num;
	return *this;
}

Book& Book::operator=(Book& book){
	strcpy_s(name, STD_STR_LENGTH, book.name);
	strcpy_s(author, STD_STR_LENGTH, book.author);
	strcpy_s(isbn, STD_STR_LENGTH, book.isbn);
	strcpy_s(className, STD_STR_LENGTH, book.className);
	price = book.price;
	num = book.num;
	return book;
}

Book *sort(Book *bookArr,int arrSize, int order){
	Book *pMin = &bookArr[0];
	Book *pMax = &bookArr[0];
	switch (order){
	case SMALL_TO_LARGE:
		for (int i = 0; i < arrSize; i++){//Seletion sort
			pMin = &bookArr[i];
			for (int j = i; j < arrSize; j++){
				if ((*pMin).price > bookArr[j].price) 
					pMin = &bookArr[j];
			}
			mySwap(*pMin, bookArr[i]);
		}
		break;
	case LARGE_TO_SMALL:
		for (int i = 0; i < arrSize; i++){//Seletion sort
			pMax = &bookArr[i];
			for (int j = i; j < arrSize; j++){
				if ((*pMax).price < bookArr[j].price)
					pMax = &bookArr[j];
			}
			mySwap(*pMax, bookArr[i]);
		}
		break;
	default:

		break;
	}
	return SORT_SUCCESS;
}

bool Book::find(str& targetStr){
	if ((!strcmp(name, targetStr)) || (!strcmp(author, targetStr)) || (!strcmp(isbn, targetStr)) || (!strcmp(className, targetStr)))
		return true;
	else return false;
}

std::fstream& Book::binInput(std::fstream &fin){
	//fin.read(name, sizeof(name));
	//fin.read(author, sizeof(author));
	//fin.read(className, sizeof(className));
	//fin.read(isbn, sizeof(isbn));
	//fin.read((char*)&price, sizeof(price));
	fin.read((char*)this, sizeof(Book));
	return fin;
}

std::fstream& Book::binOutput(std::fstream &fout){
	//fout.write(name, sizeof(name));
	//fout.write(author, sizeof(author));
	//fout.write(className, sizeof(className));
	//fout.write(isbn, sizeof(isbn));
	//fout.write((char*)&price, sizeof(price));
	fout.write((char*)this, sizeof(Book));
	return fout;
}

std::ofstream &operator<<(std::ofstream &fout, Book &book){
	fout << "The name is " << book.name << std::endl
		<< "Author: " << std::endl
		<< "ISBN: " << book.isbn << std::endl
		<< "Price: " << book.price << std::endl
		<< "Class Name: " << book.className << std::endl
		<< "Stock number: " << book.num << std::endl
		<< std::endl;
	return fout;
}

std::ostream &operator<<(std::ostream &out, Book &book){
	out << "The name is " << book.name << std::endl
		<< "Author: " << book.author << std::endl
		<< "ISBN: " << book.isbn << std::endl
		<< "Price: " << book.price << std::endl
		<< "Class Name: " << book.className << std::endl
		<< "Stock number: " << book.num << std::endl
		<< std::endl;
	return out;
}

std::istream &operator>>(std::istream &in, Book &book){
	in >> book.name >> book.author >> book.className >> book.isbn >>  book.price;
	return in;
}