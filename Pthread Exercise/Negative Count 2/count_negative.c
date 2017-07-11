#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "count_negative.h"

void *count_negative_thread_worker(void *arg) 
{
	TDATA *tdata = (TDATA *)arg;

	// your code here
	if(tdata->thread_id == 0)
		negative_count++;

	tdata->results_size = 1;

	int equal_part = ((int64_t)array_size / (int64_t)number_of_threads);
	int total_over = ((int64_t)array_size % (int64_t)number_of_threads);
	int num_to_process = equal_part;

	if(tdata->thread_id+1 <= total_over)
		num_to_process++;

	int start_position = 0;
	if(tdata->thread_id+1 <= total_over)
		start_position = tdata->thread_id * (equal_part + 1);
	else
		start_position = total_over * (equal_part + 1) + (tdata->thread_id - total_over) * equal_part;

	for(int i=start_position; i<(start_position+num_to_process);i++){
		if(array[i]<0){
			pthread_mutex_lock(&negative_count_lock);
			negative_count++;
			pthread_mutex_unlock(&negative_count_lock);
		}
	}

	pthread_exit((void*)tdata);

		

	return tdata;
}
