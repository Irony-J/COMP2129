#include <stdio.h>

int main(){

	printf("sizeof(char) is %lu\n",sizeof(char));
	unsigned short x=32768;
	printf("%d : %x\n",x,x);
	printf("%d>>%d : %d\n",x,15,x>>15);
	return 0;
}