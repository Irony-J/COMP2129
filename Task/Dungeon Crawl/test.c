/*Test*/
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	FILE *filep = fopen(argv[1],"r");
	char str[8192];
	//printf("%s\n",argv[1]);
	
	if(filep==NULL){
		fclose(filep);
		return -1;
	}
	//printf("test\n");
	fgets(str,8192,filep);
	//printf("test\n");
	printf("%s\n",str);
	
	
	int step=0;
	int len = strlen(str);
	while(step<len){
		char tmp[100];
		sscanf(str+step,"%s",tmp);
		printf("%s\n",tmp);
		step += strlen(tmp) + 1;
	}

	char str2[100];

	while(fgets(str2,100,filep)!=NULL){
		printf("%s\n",str2);
	}

	


	fclose(filep);
	return 0;
}
//test insert
