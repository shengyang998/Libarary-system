#ifndef USER_H_LIBSYS
#define USER_H_LIBSYS

#include"main.h"
class User{
	str username;
	str password;
	//str lastLogin;
public:
	User(bool, std::fstream&);
	User(str &un, str &pw);
	char *encode(str &unpw);
	char *decode(str &unpw);
	void readUNPW(std::fstream &fin);
	void changeUNPW(str &un, str &pw);
	void writeUNPW(std::fstream &fout);
	friend int login(const User &user);
	str &getUN(){
		return username;
	}
	//str &getLastLogin(){
	//	return lastLogin;
	//}
};

#endif //USER_H_LIBSYS