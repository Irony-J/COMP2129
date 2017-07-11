#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char str[100]="123456745678934567";

	char **eptr;

	long num=strtol(str,eptr,10);
	printf("%ld",num);

	return 0;
}