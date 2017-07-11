#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t my_thread;

void* threadF(void *arg){
	printf("Hello from our first POSIX thread.\n");
	sleep(10);
	return 0;
}

int main(){

	pthread_create(&my_thread,NULL,threadF,NULL);

	printf("hello 123\n");

	pthread_join(my_thread,NULL);

	return 0;
}