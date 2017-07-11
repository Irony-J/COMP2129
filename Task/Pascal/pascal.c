#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct node
{
    long long int data;
    Position next;
};

void PrintList(List L){
	Position p=L;
	printf("%lld",p->data);
	p=p->next;

	while(p!=NULL){
		printf(" %lld",p->data);
		p=p->next;
	}
	printf("\n");

}

void append(List L,int num){
	Position p=L;
	while(p->next!=NULL)
		p=p->next;

	Position newnode = malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	p->next=newnode;
}

void freelist(List L){
	Position p;
	while(L!=NULL){
		p=L->next;
		free(L);
		L=p;
	}
}


int main(int argc,char* argv[]){

	if(argc<2){
		printf("Missing Argument\n");
		return 1;
	}
	
	int count;
	count= strtol(argv[1],NULL,10);

	if(count<0){
		printf("Invalid Argument\n");
		return 1;
	}

	if(count==0){
		printf("1\n");
		return 0;
	}

	List L = malloc(sizeof(struct node));
	L->data=1;
	L->next=NULL;

	long long int backup;
	long long int previous;
	printf("1\n");
	while(count>0){
		//Position p1=L;
		Position p=L->next;
		backup=previous=1;
		while(p!=NULL){
				backup=p->data;
				p->data=previous + p->data;
				p=p->next;
				previous=backup;

		}
		append(L,1);
		PrintList(L);

		count--;
	}

	freelist(L);

	return 0;
}
