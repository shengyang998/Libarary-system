#include"main.h"
#include"book.h"

#include<iostream>
#include<fstream>

int login(char(&username)[MAX_STR_LENGTH], char(&password)[MAX_STR_LENGTH]);
char *encode(char(&str)[MAX_STR_LENGTH]);
char *decode(char(&str)[MAX_STR_LENGTH]);
int menu();


int main(){
	system("color 0a");
	char userName[100] = "admin";//it should be read from file
	//strcpy_s(userName, 100, decode(userName));
	char passWord[100] = "admin";
	//strcpy_s(passWord, 100, decode(passWord));
	char lastLogin[100] = "2015/05/21 09:49:45";
	
	switch (login(userName, passWord)){
	case USER_EXIT:
		std::cerr << "Login failed: USER_EXIT" << std::endl;
		break;
	case ACCESS_GRANTED:{
		system("cls");
		std::cout << "Wlocome back " << userName << "!" << std::endl
			<< "Notice:Your last login is at " << lastLogin
			<< "\n//* This should be the date read from file *//" << std::endl;

		char isbn1[MAX_STR_LENGTH] = "ABCDEFGHIJKLMN";
		char bookName1[MAX_STR_LENGTH] = "The Lord Of The Ring";
		char classname1[MAX_STR_LENGTH] = "TLOTR";
		
		char isbn2[MAX_STR_LENGTH] = "NMLKJIHGFEDCBA";
		char bookName2[MAX_STR_LENGTH] = "The Matrix";
		char classname2[MAX_STR_LENGTH] = "TM";

		Book book[2] = { Book(isbn1, bookName1, 100, classname1, 10), Book(isbn2, bookName2, 10, classname2, 0) };

		switch (menu()){
		case USER_EXIT:
			std::cout << "The system is goinng to EXIT now.";
			return USER_EXIT;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			sort(book, 2, SMALL_TO_LARGE);
			std::cout << book[0] << std::endl << book[1];
			std::cin.get(); std::cin.get();
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
		break;
	}
	default:
		std::cerr << "Unknow ERROR." << std::endl;
		break;
	}
	return 0;
}