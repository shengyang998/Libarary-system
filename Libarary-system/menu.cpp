#include<iostream>
#include"main.h"
using namespace std;


int login(char(&username)[MAX_STR_LENGTH], char(&password)[MAX_STR_LENGTH]){
	cout << "Welcome to the Libarary Control System." << endl
		<< "Please login. " << endl << "or input exit to exit. " << endl;
	char userName[MAX_STR_LENGTH] = {};
	char passWord[MAX_STR_LENGTH] = {};
	char exit[MAX_STR_LENGTH] = "exit";
	do{
		cout << "Username: ";
		cin.getline(userName, MAX_STR_LENGTH);
		if (!strcmp(userName, exit)) return USER_EXIT;
		cout << "Password: ";
		cin.getline(passWord, MAX_STR_LENGTH);
		if (!strcmp(passWord, exit)) return USER_EXIT;
	} while (strcmp(userName, username) || strcmp(passWord, password));//strcmp() returns 0 if they are equal
	return ACCESS_GRANTED;
}

int menu(){
	cout << "What do you want to do? Please select one and press Enter to continue."
		<< "0.EXIT" << endl
		<< "1.Read Data from file" << endl
		<< "2.Write Data to file" << endl
		<< "3.Input Data with keyboard" << endl
		<< "4.Sort" << endl
		<< "5.Search & Select" << endl
		<< "6.Delete the Selected data" << endl;
	int choice;
	while (!(cin >> choice) || (choice < 1 && choice > 6)){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Error. Please choose again:";
	}
	switch (choice){
	case USER_EXIT:
		return USER_EXIT;
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	case 5:
		return 5;
	case 6:
		return 6;
	default:
		cout<<"Unknown choice at menu.";
	}
	return 0;
}