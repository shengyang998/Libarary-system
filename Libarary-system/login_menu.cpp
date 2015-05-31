#include"main.h"
#include"book.h"
#include"user.h"
using namespace std;

int login(const User &user){
	system("cls");
	std::cout << "********//Welcome to the Libarary Control System//********" << std::endl
		<< "Please login. " << std::endl 
		<< "(input \"exit\" to exit)" << std::endl;
	str userName = {};
	str passWord = {};
	str exit = "exit";
	LL count = 0;
	do{
		if (++count > 1){
			std::cout << "Your username or password are invaild." << std::endl
				<< "Please check your input and retry:" << std::endl;
		}
		std::cout << "Username: ";
		std::cin.getline(userName, STD_STR_LENGTH);
		if (!strcmp(userName, exit)) return USER_EXIT;
		std::cout << "Password: ";
		std::cin.getline(passWord, STD_STR_LENGTH);
		if (!strcmp(passWord, exit)) return USER_EXIT;
	} while (strcmp(userName, user.username) || strcmp(passWord, user.password));//strcmp() returns 0 if they are equal
	return ACCESS_GRANTED;
}

int menu(){
	system("cls"); system("color 0a");
	cout << "What do you want to do? Please select one and press Enter to continue." << endl << endl
		<< "-1.Change your username and password\t" //<< endl
		<< "0.EXIT" << endl
		<< "1.Read Data from file\t\t\t" //<< endl
		<< "2.Write Data to file" << endl
		<< "3.Input Data with keyboard\t\t" //<< endl
		<< "4.Search & Select" << endl
		<< "5.Sort\t\t\t\t\t" //<< endl
		<< "6.Delete the Selected one" << endl
		<< "7.Modify the Selected one\t\t" //<< endl
		<< "8.Print" << endl
		<< endl;
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
	case PRINT_AT_SCREEN:
		return PRINT_AT_SCREEN;
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
	cout << "Please input book name: ";
	cin.getline(bookName, STD_STR_LENGTH);
	cout << "Please input author: ";
	cin.getline(author, STD_STR_LENGTH);
	cout << "Please input ISBN: ";
	cin.getline(isbn, STD_STR_LENGTH);
	cout << "Please input price: ";
	while (!(cin >> price)){
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "Error, please input the price of this book: ";
	}
	cin.ignore(100, '\n');
	cout << "Please input class name (图书分类名): ";
	cin.getline(className, STD_STR_LENGTH);
	cout << "Please input the stock number: ";
	while (!(cin >> num)){
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "Error, please input the stock number of this book: ";
	}
	cin.ignore(100, '\n');
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

int myExit(){
		system("cls"); system("color ca");
		std::cout << std::endl << std::endl << std::endl
			<< "\t\t*************************************************" << std::endl
			<< "\t\t*\t\tPress Enter to exit.\t\t*" << std::endl
			<< "\t\t*************************************************" << std::endl;
	std::cin.get();
	return USER_EXIT;
}