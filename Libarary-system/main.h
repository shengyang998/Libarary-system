#ifndef MAIN_H_LIBSYS
#define MAIN_H_LIBSYS

#define SMALL_TO_LARGE 0
#define LARGE_TO_SMALL 1

#define MAX_STR_LENGTH 100

#define USER_EXIT -1
#define ACCESS_GRANTED 0

#define SORT_SUCCESS 0

typedef long long stockNum;

typedef char str[MAX_STR_LENGTH];

template<typename T>
void mySwap(T &left, T &right){
	T temp = left;
	left = right;
	right = temp;
}

#endif //MAIN_H_LIBSYS