#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int toolong;

int wakeup(){
	toolong = 1;
}

int main(){


	toolong = 0;
	signal(SIGALRM,wakeup);
	alarm(3);
	printf("You have 3 seconds to enter a number: ");
	
	int x;
	scanf("%d",&x);

	if(toolong == 1){
		printf("Sorry you took too long to enter.\n");
	}

	else{
		printf("Thanks for playing!\n");
	}

}