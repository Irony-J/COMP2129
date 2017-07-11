#ifndef COUNT_NEGATIVE_H
#define COUNT_NEGATIVE_H

#include <inttypes.h>

// assume > number_of_threads
extern uint64_t array_size;

// assume already allocated with data
extern int16_t *array;


// assume > 0
extern int number_of_threads;

// assume initially -1
extern uint64_t negative_count;

// assume PTHREAD_MUTEX_INITIALIZER
extern pthread_mutex_t negative_count_lock;


extern void *count_negative_thread_worker(void *arg);

#endif
