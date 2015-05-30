#ifndef USER_H_LIBSYS
#define USER_H_LIBSYS

#include"main.h"
class User{
	str username;
	str password;
	//str lastLogin;
public:
	User(std::fstream&);
	User(str &un, str &pw);
	friend char *encode(str &unpw);
	friend char *decode(str &unpw);
	int readUNPW(std::fstream &fin);
	int changeUNPW(str &un, str &pw);
	int writeUNPW(std::fstream &fout);
	friend int login(const User &user);
	str &getUN(){
		return username;
	}
	//str &getLastLogin(){
	//	return lastLogin;
	//}
};

#endif //USER_H_LIBSYS