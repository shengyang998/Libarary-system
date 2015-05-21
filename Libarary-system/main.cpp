#include"book.h"
#include<iostream>
#include<fstream>

int login(char(&username)[MAX_STR_LENGTH], char(&password)[100]);
char *encode(char(&str)[MAX_STR_LENGTH]);
char *decode(char(&str)[MAX_STR_LENGTH]);

int main(){
	system("color 0a");
	char userName[100] = "admin";//it should be read from file
	//strcpy_s(userName, 100, decode(userName));
	char passWord[100] = "aeolr";
	//strcpy_s(passWord, 100, decode(passWord));

	login(userName, passWord);
}