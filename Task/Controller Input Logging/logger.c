#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>

#define CONTROLLER_DEV "controller0"

struct data{	
	unsigned left:1;
	unsigned right:1;
	unsigned up:1;
	unsigned down:1;
	unsigned x:1;
	unsigned y:1;
	unsigned a:1;
	unsigned b:1;
	unsigned bk:1;
	unsigned st:1;
	unsigned se:1;
	unsigned mo:1;
	unsigned z:1;
	unsigned w:1;
	unsigned lt:1;
	unsigned rt:1;
	unsigned ltrig:4;
	unsigned rtrig:4;
	unsigned Controller_Id:8;
};

typedef struct data data_t;

data_t logger;

int isNumber(char* num){

	int i=0;
	if(num[0]=='-')
		i=1;

	for(;num[i]!='\0';i++){
		if(num[i]<'0' || num[i]>'9')
			return 0;
	}

	return 1;
}

/*void print_packet() {
  printf("#%u - left: %u right: %u up: %u down: %u x: %u y: %u a: %u b: "
  "%u bk: %u st: %u se: %u mo: %u z: %u w: %u lt: %u rt: %u ltrig: %u "
  "rtrig: %u\n",
  );
}*/

int main(int argc, char** argv) {


	int num=0;
	char buffer[4];

	if(argc<2){
		printf("No Argument Specified\n");
		return 1;
	}

	if(isNumber(argv[1])){
		//negative num
		if(argv[1][0]=='-'){
			printf("Invalid Arguments\n");
			return 1;
		}

		num = (int)strtol(argv[1],NULL,10);
	}
	//not a number
	else{
		printf("Invalid Arguments\n");
		return 1;
	}


	int flag = open(CONTROLLER_DEV,O_RDWR);

	if(flag==-1){
		//cannot open the file
		perror("Controller Does Not Exist\n");
		return 1;
	}

	size_t readsize = num*8*sizeof(buffer[0]);
	write(flag,&readsize,sizeof(readsize));


	for(int i=0;i<num;i++){

		read(flag,buffer,4);

		//printf("buffer: %s\n",buffer);

		logger.left = (buffer[0]) & 0x1;
		logger.right = (buffer[0]>>1) & 0x1;
		logger.up = (buffer[0]>>2) & 0x1;
		logger.down = (buffer[0]>>3) & 0x1;

		logger.x = (buffer[0]>>4) & 0x1;
		logger.y = (buffer[0]>>5) & 0x1;
		logger.a = (buffer[0]>>6) & 0x1;
		logger.b = (buffer[0]>>7) & 0x1;

		logger.bk = (buffer[1]) & 0x1;
		logger.st = (buffer[1]>>1) & 0x1;
		logger.se = (buffer[1]>>2) & 0x1;
		logger.mo = (buffer[1]>>3) & 0x1;

		logger.z = (buffer[1]>>4) & 0x1;
		logger.w = (buffer[1]>>5) & 0x1;
		logger.lt = (buffer[1]>>6) & 0x1;
		logger.rt = (buffer[1]>>7) & 0x1;

		logger.ltrig = (buffer[2]) & 0xF;
		logger.rtrig = (buffer[2]>>4) & 0xF;

		logger.Controller_Id = buffer[3];

	
		printf("#%u - left: %u right: %u up: %u down: %u x: %u y: %u a: %u b: "
  "%u bk: %u st: %u se: %u mo: %u z: %u w: %u lt: %u rt: %u ltrig: %u "
  "rtrig: %u\n", logger.Controller_Id,logger.left,logger.right,logger.up,logger.down,logger.x,logger.y,logger.a,logger.b,logger.bk,logger.st,logger.se,logger.mo,logger.z,logger.w,logger.lt,logger.rt,logger.ltrig,logger.rtrig
  );

	}
	



  	return 0;
}


