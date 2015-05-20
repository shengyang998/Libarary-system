#include<iostream>
#include<fstream>

using namespace std;

#define USER_EXIT -1

int login(char (&username)[100], char (&password)[100]){
	cout << "Welcome to the Libarary Control System." << endl
		<< "Please login. " << endl << "or input exit to exit. " << endl;
	char userName[100] = {};
	char passWord[100] = {};
	char exit[100] = "exit";
	do{
		cout << "Username: ";
		cin.getline(userName, 100);
		if (!strcmp(userName, exit)) return USER_EXIT;
		cout << "Password: ";
		cin.getline(passWord, 100);
		if (!strcmp(passWord, exit)) return USER_EXIT;
	} while (strcmp(userName, username) || strcmp(passWord, password));



	return 0;
}