#include"main.h"

char *encode(char(&str)[MAX_STR_LENGTH]){//run before write to file
	int length = sizeof(str);
	int strlength = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < strlength; i++){
		if (str[i] == '\0') continue;
		str[i] = str[i] - i%42;
	}
	return str;
}

char *decode(char(&str)[MAX_STR_LENGTH]){//run before using the str
	int length = sizeof(str);
	int strlength = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < strlength; i++){
		if (str[i] == '\0') continue;
		str[i] = str[i] + i%42;
	}
	return str;
}