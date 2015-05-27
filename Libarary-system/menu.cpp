#include"main.h"
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
	while (!(cin >> choice) || (choice < -2 || choice > 7)){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Error. Please choose again:";
	}
	cin.ignore(100, '\n');
	switch (choice){
	case -1:
		return CHANGE_UN_PW;
	case 0:
		system("color cf");
		return USER_EXIT;
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		system("cls");
		system("color 0b");
		return 4;
	case 5:
		return 5;
	case 6:
		return 6;
	default:
		cerr<<"Unknown choice at menu.";
	}
	return 0;
}