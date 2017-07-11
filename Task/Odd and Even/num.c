#include <pthread.h>
#include <stdio.h>

pthread_mutex_t order = PTHREAD_MUTEX_INITIALIZER;
int count = 1;

void* thread_even(void* arg) {

    int max =(int)arg;
    int i = 2;
    while(i<=max){
        if(count == 0){
            pthread_mutex_lock(&order);
            printf("Thread2: %d\n",i);
            count = 1;
            pthread_mutex_unlock(&order);
            i += 2;
        }
    }
	return NULL;
}

void* thread_odd(void* arg) {
    int max =(int)arg;
    int i = 1;
    while(i<=max){
        if(count == 1){
            pthread_mutex_lock(&order);
            printf("Thread1: %d\n",i);
            count = 0;
            pthread_mutex_unlock(&order);
            i += 2;
        }
    }
	return NULL;
}

