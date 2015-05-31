#include"main.h"
#include"book.h"
#include"user.h"

template<typename T> T& arrmov(T(&arrDistance), int length, T(&arrSource)){
	for (int i = 0; i < length; i++){
		arrDistance[i] = arrSource[i];
	}
	delete arrSource;
	arrSource = nullptr;
	return arrDistance;
}

template<typename T> T* arrmovNoZero(T*arrDistance, int length, int*sel, T*arrSource){
	for (int i = 0, j = 0; i < length; i++){
		if (sel[i] != 1){
			arrDistance[j] = arrSource[i];
			j++;
		}
	}
	delete arrSource;
	arrSource = nullptr;
	return arrDistance;
}

int login(const User &user);
int menu();
int changeUNPW(User &user, std::fstream &fout);
int inputData(Book &book);
int change(Book* book,int arrSize, int* seleted);
int analyze(str &);

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
	fio.open("UNPW.bin", std::ios::in|std::ios::out|std::ios::binary);
	if (!fio.is_open()) return FILE_OPEN_FAILED;
	else{
		User ysy(fio);
		fio.close();

		/* Login */
		switch (login(ysy)){
		case USER_EXIT:
			system("cls"); system("color ca");
			std::cout << std::endl << std::endl << std::endl;
			std::cerr << "Login failed: USER_EXIT" << std::endl;
			//std::cout << "Press Enter to exit." << std::endl;
			//std::cin.get();
			break;
		case ACCESS_GRANTED:{
			system("cls");
			std::cout << "Wlocome back " << ysy.getUN() << "!" << std::endl;
			//<< "Notice:Your last login is at " << ysy.getLastLogin()
			//<< "\n//* This should be the date read from file *//" << std::endl;

			/* Init the data */

			/* declare something useful */
			int *pSelected = nullptr; Book *newBook = nullptr; Book *pBook = nullptr; int countHit = 0;
			/* Main menu */
			while (1){
				switch (menu()){
				case CHANGE_UN_PW:
					system("cls");
					if (!fio.is_open()) fio.open("UNPW.bin", std::ios::out | std::ios::binary);
					if (changeUNPW(ysy, fio) == USER_EXIT){
						fio.close();
						std::cerr << "The system is goinng to EXIT now.";
						std::cout << "Press Enter to continue.";
						std::cin.get();
						return USER_EXIT;
					}
					else
						break;
				case USER_EXIT:
					system("cls");
					std::cerr << "The system is goinng to EXIT now.";
					std::cout << "Press Enter to continue.";
					std::cin.get();
					return USER_EXIT;
					break;
				case READ_FROM_BIN_FILE:
					system("cls");
					fio.open("data.bin", std::ios::in | std::ios::binary);
					fio.seekg(0, fio.beg);
					fio.read((char*)&Book::counter, sizeof(LL));
					std::cout << "There are " << Book::counter << " books." << std::endl;
					pBook = new Book[Book::counter];
					if (pBook == nullptr) {
						std::cerr << "Error, don't have enough menmory" << std::endl;
						std::cout << "Press Enter to continue.";
						std::cin.get();
						return LOW_MEMORY;
					}
					if (!fio.is_open()) fio.open("data.bin", std::ios::in | std::ios::binary);
					fio.seekg(sizeof(LL), fio.beg);
					for (int i = 0; i < Book::counter; i++){
						pBook[i].binInput(fio);
						//fin.seekg((i + 1)*sizeof(Book), fin.beg + sizeof(LL));
					}
					std::cout << "Done. Input successfully." << std::endl;
					if (fio.is_open()) fio.close();
					std::cout << "Press Enter to continue.";
					std::cin.get();
					break;
				case WRITE_TO_FILE:
					system("cls");
					if (pBook == nullptr)
						std::cerr << "Error. There is no books." << std::endl;
					else{
						if (!fio.is_open()) fio.open("fout.bin", std::ios::out | std::ios::binary);
						fio.write((char*)&Book::counter, sizeof(LL));
						for (int i = 0; i < Book::counter; i++){
							pBook[i].binOutput(fio);
							//fout.seekp((i + 1)*sizeof(Book), fin.beg + sizeof(LL));
						}
						std::cout << "Done. Output successfully." << std::endl;
						fio.close();
						std::cout << "Press Enter to continue.";
						std::cin.get();
					}
					break;
				case INPUT_DATA:
					system("cls");
					std::cout << "Please input the number of books that you want to input: ";
					int num;
					while (!(std::cin >> num)){
						std::cin.clear();
						std::cin.ignore(100, '\n');
						std::cerr << "Error input. Please retry: ";
						std::cout << "Press Enter to continue.";
						std::cin.get();
					}
					std::cin.ignore(100, '\n');
					Book::counter += num;
					newBook = new Book[Book::counter];
					if (newBook == nullptr) {
						std::cerr << "Error, don't have enough menmory" << std::endl;
						std::cout << "Press Enter to continue.";
						std::cin.get();
						return LOW_MEMORY;
					}
					else{//new successfully
						arrmov(newBook, Book::counter - num, pBook);
						for (int i = Book::counter - num; i < Book::counter; i++){
							inputData(newBook[i]);
						}
						pBook = newBook;
					}
					break;
				case SEARCH_SELECT:
					system("cls");
					std::cout << "Please input what you want to search: ";
					str target;
					std::cin.getline(target, STD_STR_LENGTH);
					pSelected = new int[Book::counter];
					for (int i = 0; i < Book::counter; i++) pSelected[i] = 0;
					for (int i = 0; i < Book::counter; i++){
						if (pBook[i].find(target) == true) {
							std::cout << pBook[i];
							pSelected[i] = 1;
							countHit++;
						}
					}
					std::cout << "There are " << countHit << " hitted in total.";
					std::cout << "Press Enter to continue.";
					std::cin.get();
					break;
				case SORT_DATA:
					system("cls");
					std::cout << "Sort from small to large or not? ";
					str slORls;
					std::cin.getline(slORls, STD_STR_LENGTH);
					int flag;
					if (analyze(slORls) == SMALL_TO_LARGE) flag = SMALL_TO_LARGE;
					else flag = LARGE_TO_SMALL;
					sort(pBook, Book::counter, flag);
					if (flag == SMALL_TO_LARGE) std::cout << "Done. Sort by price successfully, SMALL_TO_LARGE";
					else std::cout << "Done. Sort by price successfully, LARGE_TO_SMALL";
					std::cout << "Press Enter to continue.";
					std::cin.get();
					break;
				case DELETE_SELECTED:
					system("cls");
					if (countHit == 0){
						std::cerr << "Error. Nothing is selected." << std::endl;
						std::cout << "Press Enter to continue.";
						std::cin.get();
					}
					else{
						newBook = new Book[Book::counter - countHit];
						arrmovNoZero(newBook, Book::counter - countHit, pSelected, pBook);
					}
					break;
				case MODIFY_SELECTED:
					system("cls");
					if (countHit > 1){
						std::cerr << "Error. More than one item have been chosen." << std::endl;
						std::cout << "Press Enter to continue.";
						std::cin.get();
					}
					else {
						change(pBook, Book::counter, pSelected);
					}
					break;
				case PRINT_AT_SCREEN:
					for (int i = 0; i < Book::counter; i++)
						std::cout << pBook[i] << std::endl;
					std::cout << "Press Enter to continue.";
					std::cin.get();
					break;
				default:
					break;
				}
			}
			delete[] newBook;
			newBook = nullptr;
			delete[] pSelected;
			pSelected = nullptr;
			delete[] pBook;
			pBook = nullptr;
			break;
		}
		default:
			std::cerr << "Unknow ERROR." << std::endl;
			break;
		}

		if (fio.is_open()) fio.close();
		return 0;
	}
}