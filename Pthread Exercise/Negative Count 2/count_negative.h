#ifndef COUNT_NEGATIVE_H
#define COUNT_NEGATIVE_H

#include <inttypes.h>


typedef struct thread_data {
	int thread_id;
	int16_t *results;
	int64_t results_size;
} TDATA;


extern uint64_t array_size;

extern int16_t *array;

extern int number_of_threads;

extern uint64_t negative_count;

extern pthread_mutex_t negative_count_lock;

extern void *count_negative_thread_worker(void *arg);

#endif
