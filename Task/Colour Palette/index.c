#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//You may add/modify/remove structs

uint32_t width,height;
uint16_t magic;
int count=0;
int num=0; //number of types of pixel


struct pixel_t;
typedef struct pixel_t* PtrToPixel;
typedef PtrToPixel Position;
typedef PtrToPixel List;


struct pixel_t {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t empty;
	int index;
	Position next;
};

List pixel;

int checkList(List L, uint8_t R,uint8_t G,uint8_t B){
	Position p = L->next;
	while(p!=NULL){
		if((p->red==R) && (p->green==G) && (p->blue==B))
			return p->index;
		p=p->next;
	}
	return -1;
}

void append(List L, uint8_t R,uint8_t G,uint8_t B,int num){
	Position tmp=L;
	while(tmp->next!=NULL)
		tmp=tmp->next;

	Position newnode = (Position)malloc(sizeof(struct pixel_t));
	newnode->index=num;
	newnode->red=R;
	newnode->green=G;
	newnode->blue=B;
	newnode->next=NULL;
	tmp->next=newnode;

}


void freeList(List L){
	void* tmp;
	while(L!=NULL){
		tmp=L;
		L=L->next;
		free(tmp);
	}
}


int main(int argc, char** argv) {

	int** array;
	int check=-1;
	
	//determine the validity of the arguments
	if(argc<2){
		printf("No Filename Specified\n");
		exit(1);
	}
	else{
		FILE *fp=fopen(argv[1],"rb");
		if(fp==NULL){
			printf("File Does Not Exist\n");
			exit(1);
		}

		fread(&width,sizeof(uint32_t),1,fp);
		fread(&height,sizeof(uint32_t),1,fp);
		fread(&magic,sizeof(uint16_t),1,fp);
		//printf("width: %d, height: %d\n",width,height);
		if(magic!=60535){
			printf("Invalid Image Header\n");
			fclose(fp);
			exit(1);
		}

		//ready to read the graph
		pixel=(List)malloc(sizeof(struct pixel_t));
		pixel->next=NULL;

		array =(int**)malloc(height*sizeof(int*));
		for(int i=0;i<height;i++)
			array[i]=(int*)malloc(width*sizeof(int));



		uint8_t tmpR,tmpG,tmpB,padding;

		while(fread(&tmpR,sizeof(uint8_t),1,fp)!=0){
			fread(&tmpG,sizeof(uint8_t),1,fp);
			fread(&tmpB,sizeof(uint8_t),1,fp);
			fread(&padding,sizeof(uint8_t),1,fp);
			count++;

			check=checkList(pixel,tmpR,tmpG,tmpB);
			if(check==-1){
				append(pixel,tmpR,tmpG,tmpB,num);
				//printf("count: %d, i: %d, j: %d\n",count,count/(width+1),(count-1)%width);
				array[(int)((count-1)/width)][(count-1)%width] = num;
				num++;
			}
			else{
				//printf("count: %d, i: %d, j: %d\n",count,count/(width+1),(count-1)%width);
				array[(int)((count-1)/width)][(count-1)%width] = check;
			}

		}

		if(count!=width*height){
			printf("Invalid Image Data\n");
			freeList(pixel);
		    for(int i=0;i<height;i++)
			   free(array[i]);
		    free(array);
		    exit(1);
		}

		for(int i=0;i<height;i++){
			printf("[");
			for(int j=0;j<width-1;j++){
				printf(" %d,",array[i][j]);
			}

			printf(" %d ]\n",array[i][width-1]);
		}

		freeList(pixel);
		for(int i=0;i<height;i++)
			free(array[i]);
		free(array);


	}
	return 0;
}
