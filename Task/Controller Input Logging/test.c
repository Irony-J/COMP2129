#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>

int main(void){
	char buffer[5];

	for(int i=0;i<2;i++){
		read(0,buffer,5);
	printf("sizeof(char):%lu\n",sizeof(buffer[0]));
	printf("buffer:%s\n",buffer);
	}
	
}