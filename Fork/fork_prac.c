#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){

	pid_t pid;
	int fileds[2];

	if(pipe(fileds)==-1){
		printf("Cannout create the pipe!\n");
		return 1;
	}


	if(!(pid = fork())){
		printf("Child's process id is %d\n",(int)pid);
		printf("I am child!\n");
		
		// for(int i=0;i<21;i=i+2){
		// 	printf("child says: %d\n",i);
		// }

		char *msg = "Greeting from child!";
		int msglen = (int)strlen(msg) + 1;
		int nwritten = write(fileds[1],msg,msglen);

		if(nwritten!=msglen){
			printf("I cannot send msg to my parent, maybe they don't love me...\n");
		}

	}

	/*parent in control*/
	

	if(pid>0){
		printf("Parent's process id is %d\n",(int)pid);
		printf("I am parent!\n");
		
		// for(int i=1;i<20;i=i+2){
		// 	printf("parent says: %d\n",i);
		// }

		char buffer[100];
		int nread = read(fileds[0],buffer,100);
		

		printf("Let me see...The msg from my child is \"%s\"\n",buffer);

		
	}


	if(pid < 0){
		printf("fork failed\n");
		exit(1);
	}

	return 0;

}