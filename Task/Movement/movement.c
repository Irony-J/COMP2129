#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc,char* argv[]){
	

	//determine whether the input is vailid
	
	//1. check the numbers of argument
	if(argc!=6){
		printf("Invalid Number Of Arguments\n");
		return 1;
	}

	//2. check the width

	for(int i=0;argv[1][i]!='\0';i++){
		if(argv[1][i]<'0'||argv[1][i]>'9'){
			printf("Invalid Width\n");
			return 1;
		}
	}

	//3. check the height

	for(int i=0;argv[2][i]!='\0';i++){
		if(argv[2][i]<'0'||argv[2][i]>'9'){
			printf("Invalid Height\n");
			return 1;
		}
	}

	//4. check the character properties
	for(int i=0;argv[3][i]!='\0';i++)
		if(argv[3][i]<'0'||argv[3][i]>'9'){
			printf("Invalid Character Properties\n");
			return 1;
		}


	for(int i=0;argv[4][i]!='\0';i++)
		if(argv[4][i]<'0'||argv[4][i]>'9'){
			printf("Invalid Character Properties\n");
			return 1;
		}

	for(int i=0;argv[5][i]!='\0';i++)
		if(argv[5][i]<'0'||argv[5][i]>'9'){
			printf("Invalid Character Properties\n");
			return 1;
		}

	//Conver all the command line into int

	//int width,height,x,y,limit;
	char* eptr;

	int width=(int) strtol(&argv[1][0],&eptr,10);
	int height=(int) strtol(&argv[2][0],&eptr,10);
	int x= (int) strtol(&argv[3][0],&eptr,10);
	int y= (int) strtol(&argv[4][0],&eptr,10);
	int limit= (int) strtol(&argv[5][0],&eptr,10);

	//print the framework
	printf("+");
	for(int i=0;i<2*width-1;i++)
		printf("-");
	printf("+\n");


	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if( (i!=x) || (j!=y)){
				printf("|");
				int step=abs(x-i)+abs(y-j);
				if(step<=limit)
					printf("%d",limit-step);
				else
					printf(" ");
			}
			else
				printf("|C");
		}
		printf("|\n");
	}

	printf("+");
	for(int i=0;i<2*width-1;i++)
		printf("-");
	printf("+\n");

	return 0;

}
