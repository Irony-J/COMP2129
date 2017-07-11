#include "tape.h"
#include <inttypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define MAX 20
#define MAX_THREAD 20


int number_of_thread;
pthread_t mythread[MAX_THREAD];

uint8_t *data;
uint64_t data_size;

FILE* filep[MAX_THREAD];


typedef struct{
	int thread_id;
	int read_offset;
	int head_offset;
}t_data;

void* tape_reader(void* args){

	t_data* input = (t_data*)args;

	
	// printf("data_size:%lu\n",data_size);
	// printf("read:%d\n",input->read_offset);
	if(input->head_offset<0){//check the head offset, set to the index it represents
		if(-input->head_offset == data_size)
			input->head_offset = 0;
		else
			input->head_offset = data_size - ((-input->head_offset) % data_size);
		
	}
	else{
		input->head_offset = input->head_offset % data_size;
	}

	

	if(input->read_offset >=0){

		if(input->head_offset + input->read_offset > data_size){//exceed the data array

			fwrite(&data[input->head_offset],sizeof(uint8_t),data_size - input->head_offset,filep[input->thread_id]);
			
			int count = input->read_offset - (data_size - input->head_offset);
			int loop = (int)(count/data_size);
			for(int i=0;i<loop;i++){
				fwrite(data,sizeof(uint8_t),data_size,filep[input->thread_id]);
			}

			//remain
			fwrite(data,sizeof(uint8_t),count%data_size,filep[input->thread_id]);


		}

		else{
			fwrite(&data[input->head_offset],sizeof(uint8_t),input->read_offset,filep[input->thread_id]);
		}
	}
	
	else{

		if(input->head_offset == 0){
			input->head_offset = data_size-1;
		}
		else
			input->head_offset--;

		if(input->head_offset + input->read_offset < 0){// exceed the lower bound of the data array


			for(int i=input->head_offset;i>=0;i--){
				fwrite(&data[i],sizeof(uint8_t),1,filep[input->thread_id]);
			}

			int count = (-input->read_offset) - (input->head_offset+1);
			int loop = (int)(count/data_size);


			for(int i=0;i<loop;i++){
				for(int j=data_size-1;j>=0;j--){
					fwrite(&data[j],sizeof(uint8_t),1,filep[input->thread_id]);
				}
			}

			int remain = (int)(count%data_size);

			for(int j=data_size-1;j>data_size-1-remain;j--)
					fwrite(&data[j],sizeof(uint8_t),1,filep[input->thread_id]);
		}

		else{
			for(int i=input->head_offset;i>input->head_offset + input->read_offset;i--){
				fwrite(&data[i],sizeof(uint8_t),1,filep[input->thread_id]);
			}
		}
	}
	

	//fclose(filep);
	free(args);
	pthread_exit(NULL);
	
	
}


int main(int argc, char* argv[]){

	if(argc == 1){
		printf("Tape Not Inserted\n");
		return -1;
	}

	FILE* fp = fopen(argv[1],"rb+");
	if(fp == NULL){
		printf("Cannot Read Tape\n");
		return -1;
	}

	data_size = 0;
	data = (uint8_t*) malloc(sizeof(uint8_t));
	int index = 0;
	uint8_t buffer;

	while(fread(&buffer,sizeof(uint8_t),1,fp)!=0){
		data = realloc(data,sizeof(uint8_t)*(index+1));
		data[index++] = (uint8_t)buffer;
		//printf("%d ",data[index-1]);
		data_size++;
	}


	char command[10];
	int offset_in;
	int offset[MAX];

	while((scanf("%s",command))!=0){
		
		if(strcmp(command,"QUIT")==0){
			free(data);
			for(int i=0;i<MAX_THREAD;i++){
				if(filep[i]!=NULL)
					fclose(filep[i]);
			}
			//fclose(fp);
			return 0;
		}

		else if(strcmp(command,"HEAD")==0){

			char filename[7] ="head";
			//printf("thread_id: %d\n",input->thread_id);
			if(number_of_thread+1 < 10){
				filename[4] = number_of_thread + '0' + 1;
				filename[5] = '\0';
			}
			else if(number_of_thread+1 >= 10 && number_of_thread+1 <100){
				filename[4] = (int)((number_of_thread+1) / 10) + '0' ;
				filename[5] = (number_of_thread+1) % 10 + '0';
				filename[6] = '\0';
			}
			//printf("file: %s\n",filename);
			filep[number_of_thread] = fopen(filename,"w+");


			scanf("%d",&offset_in);
			offset[number_of_thread++] = offset_in;
			if(offset_in>=0)
				printf("HEAD %d at +%d\n\n",number_of_thread,offset_in);
			else
				printf("HEAD %d at %d\n\n",number_of_thread,offset_in);
		}


		else if(strcmp(command,"READ")==0){
			scanf("%d",&offset_in);


		
			for(int i=0;i<number_of_thread;i++){
				t_data* tmp;
				tmp = (t_data*)malloc(sizeof(t_data));
				tmp->thread_id = i;
				tmp->read_offset = offset_in;
				tmp->head_offset = offset[i];
				pthread_create(&mythread[i],NULL,tape_reader,(void*)tmp);
				//free(tmp);
			}
			//printf("count before join:%d\n",count);
			for(int i=0;i<number_of_thread;i++){
				pthread_join(mythread[i],NULL);
			}
			
			for(int i=0;i<number_of_thread;i++){
				offset[i] += offset_in;
			}
			printf("Finished Reading\n\n");

		}
	}

	
	free(data);
	for(int i=0;i<MAX_THREAD;i++){
		if(filep[i]!=NULL)
			fclose(filep[i]);
	}
	return 0;
}


