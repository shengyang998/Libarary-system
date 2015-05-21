#include<iostream>
#include"main.h"
using namespace std;

#define USER_EXIT -1

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



	return 0;
}