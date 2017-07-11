#include "num.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t thread[2];

int main(int argc, char** argv) {

    if(argc<=1){
        printf("No Argument Specified\n");
        return 1;
    }


    int tmp = (int)strtol(argv[1],NULL,10);

    if(tmp<=0){
        printf("Argument is <= 0\n");
        return 1;
    }

    size_t input = (size_t)tmp;

    pthread_create(&thread[0],NULL,thread_odd,(void*)input);
    pthread_create(&thread[1],NULL,thread_even,(void*)input);

    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);

    return 0;
}

