#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_THREAD 4

pthread_mutex_t addlock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t printlock = PTHREAD_MUTEX_INITIALIZER;
int sum;

struct data_type{
	int thread_id;
	int junk;
};

typedef struct data_type data;

void* func(void* p){
	data* input = (data*)p;

	for(int i=1;i<=10;i++){
		pthread_mutex_lock(&printlock);
		printf("Thread %d is working now\n",input->thread_id);
		pthread_mutex_unlock(&printlock);
		
		pthread_mutex_lock(&addlock);
		sum += i;
		pthread_mutex_unlock(&addlock);
	}

	pthread_exit((void*)input);

	return input;

}


int main(){

	sum = 0;

	pthread_t thread[NUM_OF_THREAD];
	data* dataArray[NUM_OF_THREAD];
	data* tmp;

	for(int i=0;i<NUM_OF_THREAD;i++){
		dataArray[i] = (data*)malloc(sizeof(data));
		tmp = dataArray[i];
		dataArray[i]->thread_id = i;

		pthread_create(&thread[i],NULL,func,(void*)tmp);
	} 

	for(int i=0;i<NUM_OF_THREAD;i++){
		pthread_join(thread[i],(void**)&tmp);
	}


	printf("Sum is %d\n",sum);





	return 0;
}