
#include"main.h"
#include"book.h"

Book::Book(char(&isbn)[MAX_STR_LENGTH], char(&name)[MAX_STR_LENGTH], double price, char(&className)[MAX_STR_LENGTH], stockNum num){
	strcpy_s(this->isbn, MAX_STR_LENGTH, isbn);
	strcpy_s(this->name, MAX_STR_LENGTH, name);
	this->price = price;
	strcpy_s(this->className, MAX_STR_LENGTH, className);
	this->num = num;
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

		break;
	default:

		break;
	}
	return SORT_SUCCESS;
}

std::ostream &operator<<(std::ostream &out, Book &book){
	std::cout << "The name is: " << book.name << std::endl
		<< "ISBN: " << book.isbn << std::endl
		<< "Price: " << book.price << std::endl
		<< "Stock number: " << book.num << std::endl;
	return out;
}