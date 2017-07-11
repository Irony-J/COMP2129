#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>


#define NUM_OF_THREAD 4

int sum;

struct data_type{
	int thread_id;
	int junk;
};

typedef struct data_type data;

pthread_barrier_t mybarrier;

void* func(void* p){

	data* input = (data*)p;

	pthread_barrier_wait(&mybarrier);

	printf("All threads arrive. I am thread %d\n",input->thread_id);

}


int main(){

	pthread_t thread[NUM_OF_THREAD];

	pthread_barrier_init(&mybarrier,NULL, NUM_OF_THREAD);

	data* tmp;

	for(int i=0;i<NUM_OF_THREAD;i++){
		pthread_create(&thread[i],NULL,func,(void*)tmp);
	}

	return 0;
}