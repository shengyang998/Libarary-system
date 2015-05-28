#include"main.h"

int analyze(str &slOrls){
	int flag;
	unsigned int i = 0;
	for (; i + 2 < strlen(slOrls); i++){
		if ((slOrls[i] == 'y' || slOrls[i] == 'Y') && (slOrls[i + 1] == 'e' || slOrls[i + 1] == 'E') &&
			(slOrls[i + 2] == 's' || slOrls[i + 2] == 'S'))
			flag = SMALL_TO_LARGE;
		if ((slOrls[i] == 'n' || slOrls[i] == 'N') && (slOrls[i + 1] == 'o' || slOrls[i + 1] == 'O'))
			flag = LARGE_TO_SMALL;
		if ((slOrls[i] == 's' || slOrls[i] == 'M') && (slOrls[i + 1] == 'm' || slOrls[i + 1] == 'M') &&
			(slOrls[i + 2] == 'a' || slOrls[i+2] == 'A'))
			break;
	}
	unsigned int j = 0;
	for (; j + 2 < strlen(slOrls); j++){
		if ((slOrls[i] == 'l' || slOrls[i] == 'L') && (slOrls[i + 1] == 'a' || slOrls[i + 1] == 'A') &&
			(slOrls[i + 2] == 'r' || slOrls[i+2] == 'R'))
			break;
	}
	if (i < j)
		flag = SMALL_TO_LARGE;
	else
		flag = LARGE_TO_SMALL;
	return flag;
}