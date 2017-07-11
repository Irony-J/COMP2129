/* THIS FILE IS FOR STAFF ONLY 
 * 
 * IGNORE - DO NOT MODIFY
 * 
 * FILE IS NOT PART OF YOUR SUBMISSION
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <pthread.h>
#include <inttypes.h>

#include "count_negative.h"

uint64_t array_size;
int16_t *array;
int number_of_threads;
uint64_t negative_count;
pthread_mutex_t negative_count_lock = PTHREAD_MUTEX_INITIALIZER;

void init_data(int argc, char *argv[]) 
{
	if (argc < 2) {
		fprintf(stderr, "Not enough arguments\n");
		exit(-1);
	}
	
	char *p;
	number_of_threads = strtol(argv[1], &p, 10);
	if (*p != '\0') {
		fprintf(stderr, "Could not parse parameter: number of threads\n");
		exit(1);
	}
	if (number_of_threads < 1 || number_of_threads > 128) {
		fprintf(stderr, "Invalid range: number of threads\n");
		exit(2);
	}

	FILE *fp = stdin;
	
	int items;
	int nread = fscanf (fp, "%d", &items);
	if (nread < 1) {
		fprintf(stderr, "Invalid read: number of elements\n");
		exit(3);
	}
	if (items < number_of_threads) {
		fprintf(stderr, "Invalid range: items %d < number of threads %d\n",
			items, number_of_threads);
		exit(4);
	}
		
	array_size = items;
	array = (int16_t*)malloc(sizeof(int16_t) * array_size);
	
	int i = 0;
	while (!feof (fp) && i < items)
	{  
		int val = 0;
		int nread = fscanf (fp, "%d", &val );
		if (nread < 1) {
			fprintf(stderr, "could not read. expected integer\n");
			fclose(fp);
			free(array);
			exit(5);
		}
		
		array[i] = val;
		i++;
	}
	if (i < items) {
		fprintf(stderr, 
			"unexpected end of file. could not read all data %d of %d\n", 
			i, items);
		fclose(fp);
		free(array);
		exit(6);
	}
	
	fclose (fp); 
			
	negative_count = -1;
}

void destroy_data() {
	free(array);
}

/*
 *    ./program <number of threads> < inputfile > outputfile 2> errors
 *
 *    == inputfile format ==
 *    <n = number of elements> <elem 0> <elem 1> <elem 2>...<elem n-1>
 *
 */
int main(int argc, char *argv[])
{
	// segregating by students by wealth since 2006!
	if (sizeof(void*) < sizeof(int64_t)) {
		fprintf(stderr, "Please run this program on a 64 bit processor\n");
		exit(-1);
	}

	init_data(argc, argv);
	
	pthread_t th[number_of_threads];

	for (int i = 0; i < number_of_threads; ++i) {
		void *param = (void*)i;
		pthread_create(th + i, NULL, count_negative_thread_worker, param);
	}

	int64_t equalparts = ((int64_t)array_size/(int64_t)number_of_threads);

		
	void *elementsp;
	for (int i = 0; i < number_of_threads; ++i) {
		pthread_join(th[i], (void**)&elementsp);
		int64_t elements = (int64_t)elementsp;
		
		// give a nice message if unbalanced. we could go 128 threads.
		if ( number_of_threads > 1 && llabs( elements - equalparts) > 16) {
			fprintf(stderr, "thread %d did %ld work instead of approx %ld work\n", 
				i, elements, equalparts);
		}
	}

	printf("negative_count: %ld\n", negative_count);

	destroy_data();
	
	return 0;
}

