#include"book.h"


int login(char(&username)[100], char(&password)[100]);

int main(){
	char userName[100] = "admin";
	char passWord[100] = "admin";
	login(userName, passWord);
}