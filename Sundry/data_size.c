#include<stdlib.h>
#include<stdio.h>

int main(){

	printf("int: %lu bytes\n",sizeof(int));
	printf("size_t: %lu bytes\n",sizeof(size_t));
	printf("char: %lu byte\n",sizeof(char));
	printf("short: %lu bytes\n",sizeof(short));
	printf("long: %lu bytes\n",sizeof(long));
	printf("pointer: %lu bytes\n",sizeof(void*));
	printf("unsigned int: %lu bytes\n",sizeof(unsigned int));

	return 0;
}