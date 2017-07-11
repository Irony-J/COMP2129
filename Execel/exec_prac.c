#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	if(execl("/bin/echo","echo","Hello from echo",(char*)0)==-1){
		perror("Cannot echo!\n");
		exit(1);
	}

	return 0;
}