#include<fstream>
#include"user.h"

User::User(std::fstream &fio){
	if (fio.is_open() && (fio.beg != fio.end)){//open succeed
		readUNPW(fio);
	}
	else{
		str un, pw;
		std::cout << "It seems that this is your first time to use the sysem." << std::endl
			<< "Please set your own username and password firstly." << std::endl << std::endl
			<< "Username: ";
		std::cin.getline(un, sizeof(str));
		std::cout << "Password: ";
		std::cin.getline(pw, sizeof(str));
		strcpy_s(username, STD_STR_LENGTH, un);
		strcpy_s(password, STD_STR_LENGTH, pw);
		writeUNPW(fio);
		std::cout << "Done. New user has been set." << std::endl;
		std::cout << "Please don't forget to input the data firstly." << std::endl;
	}
}

User::User(str& un, str& pw){
	strcpy_s(username, STD_STR_LENGTH, un);
	strcpy_s(password, STD_STR_LENGTH, pw);
}

char* encode(str &unpw){//run before write to file
	LL strlength = std::strlen(unpw);
	for (int i = 0; i < strlength; i++){
		if (unpw[i] == '\0') continue;
		unpw[i] = unpw[i] - i % 42;
	}
	return unpw;
}

char* decode(str &unpw){//run before using the str
	LL strlength = std::strlen(unpw);
	for (int i = 0; i < strlength; i++){
		if (unpw[i] == '\0') continue;
		unpw[i] = unpw[i] + i % 42;
	}
	return unpw;
}

int User::changeUNPW(str &un, str &pw){
	strcpy_s(username, STD_STR_LENGTH, un);
	strcpy_s(password, STD_STR_LENGTH, pw);
	return 0;
}

int User::writeUNPW(std::fstream &fout){
	if (!fout.is_open()){
		fout.open("UNPW.bin", std::ios::out, std::ios::binary);
	}
	auto fpos = fout.cur;
	fout.seekp(0, fout.beg);
	encode(username);
	encode(password);
	fout.write((char*)&username, sizeof(str));
	fout.write((char*)&password, sizeof(str));
	decode(username);
	decode(password);
	fout.seekp(0, fpos);
	return 0;
}

int User::readUNPW(std::fstream &fin){
	auto fpos = fin.cur;
	fin.seekg(0, fin.beg);
	fin.read(username, sizeof(str));
	fin.read(password, sizeof(str));
	decode(username);
	decode(password);
	fin.seekg(fpos);
	return 0;
}
