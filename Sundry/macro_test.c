#include<stdio.h>

#define min(a,b) ((a)>(b)? (printf("a is bigger\n")):(printf("b is bigger\n")))

int main(){

	int x = 100;
	int y = 50;
	min(x,y);
	printf("Here is line %d\n",__LINE__);
	printf("The file name is %s\n",__FILE__);
}