#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str1[10];
char str2[10];
char str3[10];

int compare(const void *c1, const void *c2) {
	char ch1 = *(char*)c1;
	char ch2 = *(char*)c2;
	
	printf("ch1:%c ch2:%c\n",ch1,ch2);
	if(ch1<ch2)
		return -1;
	if(ch1>ch2)
		return 1;
	return 0;
	//return *(char *)c1 - *(char *)c2;
}

int intcmp(const void *a, const void *b){
	
}

int main(){

	char input[30];
	while(fgets(input,30,stdin)!=NULL){
		
		sscanf(input,"%s %s %s",str1,str2,str3);
		printf("str1:%s\n",str1);
		printf("str2:%s\n",str2);
		printf("str3:%s\n",str3);

		//int (*comp)(const void*,const void*);
		//comp=compare;
		qsort(str1,strlen(str1),sizeof(str1[0]),compare);
		qsort(str2,strlen(str2),sizeof(char),compare);
		qsort(str3,strlen(str3),sizeof(char),compare);

		printf("After sorting:\n");
		printf("str1:%s\n",str1);
		printf("str2:%s\n",str2);
		printf("str3:%s\n",str3);


		memset(str1,'\0',10);
		memset(str2,'\0',10);
		memset(str3,'\0',10);
	}

	return 0;
}