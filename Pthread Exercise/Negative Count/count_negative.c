#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "count_negative.h"


// The parameter is the thread id. The id is in range [0, number_of_threads-1 ]
// The return value is the number of elements processed
void *count_negative_thread_worker(void *arg) {
    int thread_id = (int)arg;

    if(thread_id==0)
    	negative_count++;

	// your code here
	
	int equal_part = ((int64_t)array_size / (int64_t)number_of_threads);
	int total_over = ((int64_t)array_size % (int64_t)number_of_threads);
	int num_to_process = equal_part;

	if(thread_id+1 <= total_over)
		num_to_process++;

	int start_position = 0;
	if(thread_id+1 <= total_over)
		start_position = thread_id * (equal_part + 1);
	else
		start_position = total_over * (equal_part + 1) + (thread_id - total_over) * equal_part;

	for(int i=start_position; i<(start_position+num_to_process);i++){
		if(array[i]<0){
			pthread_mutex_lock(&negative_count_lock);
			negative_count++;
			pthread_mutex_unlock(&negative_count_lock);
		}
	}

	// return number of elements processed by this thread
	pthread_exit((void*)num_to_process);

	return NULL;
}

