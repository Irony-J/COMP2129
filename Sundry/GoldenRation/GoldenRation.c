#include <stdio.h>
#include <math.h>

int main(){

	double a,b,tmp;
	printf("Enter two numbers: ");

	if(scanf("%lf %lf",&a,&b)!=2){
		printf("Invalid input.\n");
		return 0;
	}

	if(a<b){
		tmp=a;
		a=b;
		b=tmp;
	}

	double check= round(1000 *(a/b));

	if(check==1618)
		printf("Golden ratio!\n");
	else
		printf("Maybe next time.\n");

	return 0;
}