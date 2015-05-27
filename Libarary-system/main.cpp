#include"main.h"
#include"book.h"
#include"user.h"

int login(const User &user);
int menu();

int main(){

	//Book::counter = 0;
	system("color 0a");//set the color
	std::ifstream fin; std::ofstream fout;

	/* Init the Username and Password */
	fin.open("fout.bin", std::ios::binary);
	User ysy(fin.is_open(), fin);
	
	/* Login */
	switch (login(ysy)){
	case USER_EXIT:
		std::cerr << "Login failed: USER_EXIT" << std::endl;
		break;
	case ACCESS_GRANTED:{
		system("cls");
		std::cout << "Wlocome back " << ysy.getUN() << "!" << std::endl;
			//<< "Notice:Your last login is at " << ysy.getLastLogin()
			//<< "\n//* This should be the date read from file *//" << std::endl;

		/* Init the data */
		//fout.open("fout.bin", std::ios::app | std::ios::binary);//use it when ouput the file
		fin.seekg(sizeof(str) + sizeof(str), fin.beg);

		fin.read((char*)&Book::counter, sizeof(LL));
		std::cout << "There are " << Book::counter << " books." << std::endl;

		/* Main menu */
		switch (menu()){
		case CHANGE_UN_PW:

			break;
		case USER_EXIT:
			std::cerr << "The system is goinng to EXIT now.";
			return USER_EXIT;
		case READ_FROM_FILE:
			break;
		case WRITE_TO_FILE:
			break;
		case INPUT_DATA:
			break;
		case SEARCH_SELECT:
			break;
		case SORT_DATA:
			//sort(book, 2, SMALL_TO_LARGE);
			//std::cout << book[0] << std::endl << book[1];
			//std::cin.get();
			break;
		case DELETE_SELECTED:
			break;
		case MODIFY_SELECTED:
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