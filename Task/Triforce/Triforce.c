#include <stdio.h>
#include <stdlib.h>
int main(){
	
	char input[30];
	char* eptr;

	printf("Enter height: ");
	scanf("%s",input);
	printf("\n");

	//determine whether the input is vailid
	
	for(int i=0;input[i]!='\0';i++){
		if(input[i]<'0'||input[i]>'9'){
			printf("Invalid height.\n");
			return 1;
		}
	}

	int height=(int) strtol(input,&eptr,10);
	if((height<2) || (height>20)){
		printf("Invalid height.\n");
		return 1;
	}

	int i,j,front_blank;


	//print the triangle in the top
	for(i=0;i<height;i++){
		//print the blank in the front
		for (front_blank=2*height-i-1;front_blank>0;front_blank--)
			printf(" ");

		printf("/");
		if(i!=height-1){
		     for(j=i*2;j>0;j--)
			    printf(" ");
		}
		
		else{
			for(j=i*2;j>0;j--)
				printf("_");
		} 
		printf("\\\n");
	}

	//print other two triangle
	for(i=0;i<height;i++){
		for (front_blank=height-i-1;front_blank>0;front_blank--)
			printf(" ");

		//first part
		printf("/");
		if(i!=height-1){
		     for(j=i*2;j>0;j--)
			    printf(" ");
		}
		
		else{
			for(j=i*2;j>0;j--)
				printf("_");
		} 

		printf("\\");

		//the blank
		for(int mid_blank=2*(height-i-1);mid_blank>0;mid_blank--)
			printf(" ");


		//second part
		printf("/");
		if(i!=height-1){
		     for(j=i*2;j>0;j--)
			    printf(" ");
		}
		
		else{
			for(j=i*2;j>0;j--)
				printf("_");
		} 

		printf("\\\n");


	}

	return 0;

}

