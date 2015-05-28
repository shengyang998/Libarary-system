#ifndef MAIN_H_LIBSYS
#define MAIN_H_LIBSYS

#include<cstring>
#include<fstream>
#include<iostream>

#define LL long long

#define SMALL_TO_LARGE 0
#define LARGE_TO_SMALL 1

#define STD_STR_LENGTH 100

#define CHANGE_UN_PW -2
#define READ_FROM_BIN_FILE 1
#define WRITE_TO_FILE 2
#define INPUT_DATA 3
#define SEARCH_SELECT 4
#define SORT_DATA 5
#define DELETE_SELECTED 6
#define MODIFY_SELECTED 7

#define USER_EXIT -1
#define LOW_MEMORY -100
#define ERROR_FILE_IS_EMPTY -191

#define STAY_HERE 0
#define ACCESS_GRANTED 0

#define SORT_SUCCESS 0

typedef long long stockNum;

typedef char str[STD_STR_LENGTH];

template<typename T>
void mySwap(T &left, T &right){
	T temp = left;
	left = right;
	right = temp;
}

#endif //MAIN_H_LIBSYS