#include<fstream>
#include"user.h"

User::User(bool flag, std::ifstream &fin){
	if (flag == 1){//open succeed
		readUNPW(fin);
	}
	else{
		str un, pw;
		std::cout << "It seems that this is your first time to use the sysem." << std::endl
			<< "Please set your own username and password firstly." << std::endl
			<< "Username: ";
		std::cin.getline(un, sizeof(str));
		std::cout << "PassWord: ";
		std::cin.getline(pw, sizeof(str));
		strcpy_s(username, STD_STR_LENGTH, un);
		strcpy_s(password, STD_STR_LENGTH, pw);
		std::cout << "Done. New user has been set." << std::endl;
		std::cout << "Please don't forget to input the data firstly." << std::endl;
	}
}

char* User::encode(str &unpw){//run before write to file
	int strlength = std::strlen(unpw);
	for (int i = 0; i < strlength; i++){
		if (unpw[i] == '\0') continue;
		unpw[i] = unpw[i] - i % 42;
	}
	return unpw;
}

char* User::decode(str &unpw){//run before using the str
	int strlength = std::strlen(unpw);
	for (int i = 0; i < strlength; i++){
		if (unpw[i] == '\0') continue;
		unpw[i] = unpw[i] + i % 42;
	}
	return unpw;
}

void User::changeUNPW(str &un, str &pw){
	strcpy_s(username, STD_STR_LENGTH, un);
	strcpy_s(password, STD_STR_LENGTH, pw);
}

void User::writeUNPW(std::ofstream &fout){
	auto fpos = fout.cur;
	fout.seekp(0, fout.beg);
	encode(username);
	encode(password);
	fout.write((char*)&username, sizeof(str));
	fout.write((char*)&password, sizeof(str));
	fout.seekp(0, fpos);
}

void User::readUNPW(std::ifstream &fin){
	auto fpos = fin.cur;
	fin.seekg(0, fin.beg);
	fin.read(username, sizeof(str));
	fin.read(password, sizeof(str));
	decode(username);
	decode(password);
	fin.seekg(fpos);
}

int login(const User &user){
	std::cout << "Welcome to the Libarary Control System." << std::endl
		<< "Please login. " << std::endl << "(input exit to exit)" << std::endl;
	str userName = {};
	str passWord = {};
	str exit = "exit";
	do{
		std::cout << "Username: ";
		std::cin.getline(userName, STD_STR_LENGTH);
		if (!strcmp(userName, exit)) return USER_EXIT;
		std::cout << "Password: ";
		std::cin.getline(passWord, STD_STR_LENGTH);
		if (!strcmp(passWord, exit)) return USER_EXIT;
	} while (strcmp(userName, user.username) || strcmp(passWord, user.password));//strcmp() returns 0 if they are equal
	return ACCESS_GRANTED;
}