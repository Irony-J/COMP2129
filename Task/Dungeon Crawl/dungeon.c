#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8192

struct room_t;
typedef struct room_t* room;

struct room_t{
	char* name;
	room north;
	room south;
	room east;
	room west;
};

room* graph;
int numofroom = 0;

void PrintGraph(int index){

	char diagram[7][9] ={ {' ','-','-','-','-','-','-','-',' '},
						  {'|',' ',' ',' ',' ',' ',' ',' ','|'}, 
						  {'|',' ',' ',' ',' ',' ',' ',' ','|'},
						  {'|',' ',' ',' ',' ',' ',' ',' ','|'},
						  {'|',' ',' ',' ',' ',' ',' ',' ','|'},
						  {'|',' ',' ',' ',' ',' ',' ',' ','|'},
						  {' ','-','-','-','-','-','-','-',' '} };

	if(graph[index]->north!=NULL)
		diagram[0][4]='N';
	if(graph[index]->south!=NULL)
		diagram[6][4]='S';
	if(graph[index]->west!=NULL)
		diagram[3][0]='W';
	if(graph[index]->east!=NULL)
		diagram[3][8]='E';

	printf("\n%s\n",graph[index]->name);
	for(int i=0;i<7;i++){
		for(int j=0;j<9;j++)
			printf("%c",diagram[i][j]);
		printf("\n");
	}
	printf("\n");
}


int main(int argc, char** argv) {
	
	if(argc<2){
		printf("No Level File Specified\n");
		return 0;
	}

	FILE *filep = fopen(argv[1],"r");
	
	if(filep==NULL){
		fclose(filep);
		return 0;
	}

	char RoomName[MAX];
	fgets(RoomName,MAX,filep);

	int name_length = strlen(RoomName);
	//printf("length: %d, %s",name_length,RoomName);
	int step = 0;
	graph = (room*)malloc(sizeof(room));

	//printf("-------------------test line-------------\n");
	
	while(step<name_length){
		//printf("-------------------test line-------------\n");
		//printf("step:%d numofroom:%d\n",step,numofroom);
		char tmp[100];
		sscanf(RoomName+step,"%s",tmp);
		int len = strlen(tmp);
		step+=len+1;

		//printf("%s\n",tmp);

		//add a new room;
		int current = numofroom;
		numofroom++;
		graph=realloc(graph,numofroom*sizeof(room));
		
		//initialize the name
		graph[current] = (room)malloc(sizeof(struct room_t));
		graph[current]->name = (char*)malloc(sizeof(char)*(len+1));
		memset(graph[current]->name,'\0',len+1);
		strcpy(graph[current]->name,tmp);

		//initialize the direction
		graph[current]->north = NULL;
		graph[current]->south = NULL;
		graph[current]->west = NULL;
		graph[current]->east = NULL;

	}

	// for(int i=0;i<numofroom;i++)
	// 	printf("Room%d: %s\n",i,graph[i]->name);

	//set the direction
	char str[100];
	//printf("-------------------test line-------------\n");
	while(fgets(str,100,filep)!=NULL){
		//printf("--WERT-----------------test line-------------\n");
		//printf("%s\n",str);
		char from[30];
		char direct[7];
		char to[30];
		sscanf(str,"%s > %s > %s",from,direct,to);
		//printf("after sscanf: %s %s %s\n",from,direct,to);

		int x,y;
		for(x=0;x<numofroom;x++){
			if(strcmp(from,graph[x]->name)==0){
				for(y=0;y<numofroom;y++){
					if(strcmp(to,graph[y]->name)==0){
						
						//printf("x:%d y:%d\n",x,y);
						//printf("ready to update: from:%s to:%s\n",from,to);
						if(strcmp("NORTH",direct)==0)
							graph[x]->north = graph[y];
						else if(strcmp("SOUTH",direct)==0)
							graph[x]->south = graph[y];
						else if(strcmp("EAST",direct)==0)
							graph[x]->east = graph[y];
						else if(strcmp("WEST",direct)==0)
							graph[x]->west = graph[y];
					}
				}
			}
		}


	}


	int CurrentRoom=0;//at the beginning of the game


	PrintGraph(0);
	char command[30];
	//printf("----%d\n",numofroom);
	while(scanf("%s",command)!=EOF){
		
		if(strcmp(command,"NORTH")==0){
			if(graph[CurrentRoom]->north==NULL){
				printf("No Path This Way\n");
			}
			else{
				//search for the index of next room

				for(int i=0;i<numofroom;i++){

					if(strcmp(graph[CurrentRoom]->north->name,graph[i]->name)==0){
						CurrentRoom = i;
						break;
					}
				}
			}
		}

		else if(strcmp(command,"SOUTH")==0){
			if(graph[CurrentRoom]->south==NULL){
				printf("No Path This Way\n");
			}
			else{
				//search for the index of next room
				for(int i=0;i<numofroom;i++){
					if(strcmp(graph[CurrentRoom]->south->name,graph[i]->name)==0){
						CurrentRoom = i;
						break;
					}
				}
			}
		}

		else if(strcmp(command,"EAST")==0){
			if(graph[CurrentRoom]->east==NULL){
				printf("No Path This Way\n");
			}
			else{
				//search for the index of next room
				for(int i=0;i<numofroom;i++){
					if(strcmp(graph[CurrentRoom]->east->name,graph[i]->name)==0){
						CurrentRoom = i;
						break;
					}
				}
			}
		}

		else if(strcmp(command,"WEST")==0){
			if(graph[CurrentRoom]->west==NULL){
				printf("No Path This Way\n");
			}
			else{
				//search for the index of next room
				for(int i=0;i<numofroom;i++){
					if(strcmp(graph[CurrentRoom]->west->name,graph[i]->name)==0){
						CurrentRoom = i;
						break;
					}
				}
			}
		}
		else if(strcmp(command,"QUIT")==0){
			break;
		}

		else{
			printf("What?\n");
		}

		PrintGraph(CurrentRoom);
	}

	for(int i=0;i<numofroom;i++){
		free(graph[i]->name);
		free(graph[i]);
	}
	free(graph);

	fclose(filep);
	return 0;
}