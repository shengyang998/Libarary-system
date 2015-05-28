#include"main.h"
#include"book.h"
#include"user.h"
using namespace std;

int menu(){
	cout << "What do you want to do? Please select one and press Enter to continue." << endl
		<< "-1.Change your username and password" << endl
		<< "0.EXIT" << endl
		<< "1.Read Data from file" << endl
		<< "2.Write Data to file" << endl
		<< "3.Input Data with keyboard" << endl
		<< "4.Search & Select" << endl
		<< "5.Sort " << endl
		<< "6.Delete the Selected one" << endl
		<< "7.Modify the Selected one" << endl;
	int choice;
	while (!(cin >> choice) || (choice < -2 || choice > 8)){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Error. Please choose again:";
	}
	cin.ignore(100, '\n');
	switch (choice){
	case -1:
		return CHANGE_UN_PW;
	case 0:
		return USER_EXIT;
	case READ_FROM_BIN_FILE:
		return READ_FROM_BIN_FILE;
	case WRITE_TO_FILE:
		return WRITE_TO_FILE;
	case INPUT_DATA:
		return INPUT_DATA;
	case SEARCH_SELECT:
		return SEARCH_SELECT;
	case SORT_DATA:
		return SORT_DATA;
	case DELETE_SELECTED:
		return DELETE_SELECTED;
	case MODIFY_SELECTED:
		return MODIFY_SELECTED;
	default:
		cerr<<"Unknown choice at menu.";
	}
	return 0;
}

int changeUNPW(User &user, fstream &fout){
	str un, pw;
	std::cout << "Please input your new username: ";
	std::cin.getline(un, STD_STR_LENGTH);
	std::cout << "Please input your new password: ";
	std::cin.getline(pw, STD_STR_LENGTH);
	user.changeUNPW(un, pw);
	user.writeUNPW(fout);
	std::cout << "Success! New User set!" << std::endl
		<< "Do you want to restart now?[Y/N] ";
	char restart;
	while (!(std::cin >> restart) || (restart != 'y'&&restart != 'Y'&&restart != 'n'&&restart != 'N')){
		std::cin.clear();
		std::cin.ignore(STD_STR_LENGTH, '\n');
		std::cout << "Error, please retry.[Y/N] ";
	}
	switch (restart){
	case 'y':
	case 'Y':
		return USER_EXIT;
		break;
	case 'n':
	case'N':
	default:
		return STAY_HERE;
		break;
	}
}


int inputData(Book &book){
	str bookName, author, isbn, className;
	stockNum num;
	double price;
	cout << "Please input bookName: ";
	cin.getline(bookName, STD_STR_LENGTH);
	cout << "Please input author: ";
	cin.getline(author, STD_STR_LENGTH);
	cout << "Please input ISBN: ";
	cin.getline(isbn, STD_STR_LENGTH);
	cout << "Please input price: ";
	while (!(cin >> price)){
		cin.clear();
		cin.ignore();
		cerr << "Error, please input the price of this book: ";
	}
	cout << "Please input 图书分类名: ";
	cin.getline(className, STD_STR_LENGTH);
	cout << "Please input the stock number: ";
	while (!(cin >> num)){
		cin.clear();
		cin.ignore();
		cerr << "Error, please input the stock number of this book: ";
	}
	cin.ignore();
	book.changeTo(bookName, author, isbn, price, className, num);
	return 0;
}

int change(Book* book, int arrSize, int* seleted){
	int i = 0;
	for (; i < arrSize; i++){
		if (seleted[i] == 1) break;
	}
	inputData(book[i]);
	return 0;
}