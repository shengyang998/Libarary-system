#include"main.h"
#include"book.h"
#include"user.h"

int login(const User &user);
int menu();
int changeUNPW(User &user, std::fstream &fout);
int inputData(Book &book);
template<typename T> T& arrcpy(T(&arr1), int length, T(&arr2));

int Book::counter = 0;
int main(){
	system("color 0a");//set the color
	std::fstream fio;

	/* This is to set a default user */
	//fout.open("UNPW.bin", std::ios::binary);
	//str un = "admin", pw = "admin";
	//User ysy(un, pw);
	//ysy.writeUNPW(fout);

	/* Init the Username and Password */
	fio.open("UNPW.bin", std::ios::in|std::ios::out|std::ios::trunc|std::ios::binary);
	User ysy(fio.is_open(), fio);
	fio.close();
	
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
		fio.open("data.bin", std::ios::app | std::ios::out | std::ios::binary);
		fio.seekg(0, fio.beg);
		fio.read((char*)&Book::counter, sizeof(LL));
		fio.close();
		std::cout << "There are " << Book::counter << " books." << std::endl;

		Book *pBook = new Book[Book::counter];
		if (pBook == nullptr) std::cerr << "Error, don't have enough menmory" << std::endl;
		else{//new seccessfully
			/* Main menu */
			while (1){
				switch (menu()){
				case CHANGE_UN_PW:
					system("cls");
					if (!fio.is_open()) fio.open("UNPW.bin", std::ios::out | std::ios::binary);
					if (changeUNPW(ysy, fio) == USER_EXIT){
						fio.close();
						return USER_EXIT;
					}else
						break;
				case USER_EXIT:
					system("cls");
					system("color 0c");
					std::cerr << "The system is goinng to EXIT now.";
					return USER_EXIT;
					break;
				case READ_FROM_BIN_FILE:
					if (!fio.is_open()) fio.open("data.bin", std::ios::in | std::ios::binary);
					fio.seekg(2 * sizeof(str) + sizeof(LL), fio.beg);
					for (int i = 0; i < Book::counter; i++){
						pBook[i].binInput(fio);
						//fin.seekg((i + 1)*sizeof(Book), fin.beg + sizeof(LL));
					}
					fio.close();
					break;
				case WRITE_TO_FILE:
					if (!fio.is_open()) fio.open("fout.bin", std::ios::out | std::ios::binary);
					fio.write((char*)&Book::counter, sizeof(LL));
					for (int i = 0; i < Book::counter; i++){
						pBook[i].binOutput(fio);
						//fout.seekp((i + 1)*sizeof(Book), fin.beg + sizeof(LL));
					}
					std::cout << "Done. Output successfully." << std::endl;
					fio.close();
					break;
				case INPUT_DATA:
					system("cls"); system("color 0d");
					std::cout << "Please input the number of books that you want to input: ";
					int num;
					while (!(std::cin >> num)){
						std::cin.clear();
						std::cin.ignore();
						std::cerr << "Error input. Please retry: ";
					}
					std::cin.ignore();
					Book::counter += num;
					Book *newBook = new Book[Book::counter];
					arrcpy(newBook, Book::counter - num, pBook);
					for (int i = Book::counter - num; i < Book::counter; i++){
						inputData(newBook[i]);
					}
					break;
				case SEARCH_SELECT:
					system("cls");
					system("color 0b");
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
			}
		}
		break;
	}
	default:
		std::cerr << "Unknow ERROR." << std::endl;
		break;
	}

	if (fio.is_open()) fio.close();
	return 0;
}