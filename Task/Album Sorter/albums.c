#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 50
struct photo{
	char* name;
	int year;
	char* genre;
	char* artist;
};

typedef struct photo photo_t;

photo_t* album;
int num=0;//number of photo in album


void DISPLAY(){
	for(int i=0;i<num;i++){
		printf("%s, %d, %s, %s",album[i].name,album[i].year,album[i].genre,album[i].artist);
	}
}

int intcmp_ASC(const void* a, const void* b){
	photo_t p1 = *(photo_t *)a;
	photo_t p2 = *(photo_t *)b;

	if(p1.year < p2.year)
		return -1;
	if(p1.year > p2.year)
		return 1;
	return 0;
}

int intcmp_DESC(const void* a, const void* b){
	photo_t p1 = *(photo_t *)a;
	photo_t p2 = *(photo_t *)b;

	if(p1.year < p2.year)
		return 1;
	if(p1.year > p2.year)
		return -1;
	return 0;
}

int name_strcmp_ASC(const void* a,const void* b){
	photo_t p1 = *(photo_t *)a;
	photo_t p2 = *(photo_t *)b;

	return strcmp(p1.name,p2.name);
}

int name_strcmp_DESC(const void* a,const void* b){
	photo_t p1 = *(photo_t *)a;
	photo_t p2 = *(photo_t *)b;

	return -strcmp(p1.name,p2.name);
}

int genre_strcmp_ASC(const void* a,const void* b){
	photo_t p1 = *(photo_t *)a;
	photo_t p2 = *(photo_t *)b;

	return strcmp(p1.genre,p2.genre);
}

int genre_strcmp_DESC(const void* a,const void* b){
	photo_t p1 = *(photo_t *)a;
	photo_t p2 = *(photo_t *)b;

	return -strcmp(p1.genre,p2.genre);
}

int artist_strcmp_ASC(const void* a,const void* b){
	photo_t p1 = *(photo_t *)a;
	photo_t p2 = *(photo_t *)b;

	return strcmp(p1.artist,p2.artist);
}

int artist_strcmp_DESC(const void* a,const void* b){
	photo_t p1 = *(photo_t *)a;
	photo_t p2 = *(photo_t *)b;

	return -strcmp(p1.artist,p2.artist);
}


int main(int argc, char** argv) {
	
	if(argc<2){
		printf("No File Specified\n");
		return 1;
	}

	FILE* filep = fopen(argv[1],"r");
	if(filep==NULL){
		printf("File Does Not Exist\n");
		return 1;
	}

	char input[MAX];
	album = (photo_t*)malloc(sizeof(photo_t));

	while(fgets(input,MAX,filep)!=NULL){
		
		//divide the input into 4 parts
		//printf("input: %s\n",input);
		
		char* in;
		//printf("%s,%d,%s,%s\n",in_name,in_year,in_genre,in_artist);
		int current = num;
		num++;
		album = realloc(album,sizeof(photo_t)*num);

		//name
		in = strtok(input,",");
		//printf("name: %s length: %lu\n",in,strlen(in));
		album[current].name = (char*)malloc(sizeof(char)*(strlen(in)+1));
		strncpy(album[current].name,in,(int)strlen(in));
		album[current].name[(int)strlen(in)] ='\0';
		//printf("%s ",album[current].name);
		
		//year
		in = strtok(NULL,",");
		//printf("year: %s length: %lu\n",in,strlen(in));
		album[current].year = (int)strtol(in,NULL,10);
		//printf("%d ",album[current].year);


		//genre
		in = strtok(NULL,",");
		//printf("genre: %s length: %lu\n",in,strlen(in));
		album[current].genre = (char*)malloc(sizeof(char)*(strlen(in)+1));
		strncpy(album[current].genre,in,(int)strlen(in));
		album[current].genre[(int)strlen(in)] ='\0';
		//printf("%s ",album[current].genre);

		//artist
		in = strtok(NULL,",");
		//printf("artist: %s length: %lu\n",in,strlen(in));
		album[current].artist = (char*)malloc(sizeof(char)*(strlen(in)+1));
		strncpy(album[current].artist,in,(int)strlen(in));
		album[current].artist[(int)strlen(in)] ='\0';
		//printf("%s\n",album[current].artist);

	}

	//start to operate

	while(fgets(input,MAX,stdin)!=NULL){
		char arg1[10];
		char arg2[10];
		char arg3[10];
		sscanf(input,"%s %s %s",arg1,arg2,arg3);
		// printf("str1:%s\n",str1);
		// printf("str2:%s\n",str2);
		// printf("str3:%s\n",str3);
		
		if(strcmp(arg1,"DISPLAY")==0){
			DISPLAY();
		}
		else if(strcmp(arg1,"QUIT")==0){
			break;
		}
		else if(strcmp(arg1,"SORT")==0){
			
			//sort by name
			if(strcmp(arg2,"0")==0){
				if(strcmp(arg3,"DESC")==0)
					qsort(album,num,sizeof(photo_t),name_strcmp_DESC);
				else
					qsort(album,num,sizeof(photo_t),name_strcmp_ASC);

			}

			//sort by year
			else if(strcmp(arg2,"1")==0){
				if(strcmp(arg3,"DESC")==0)
					qsort(album,num,sizeof(photo_t),intcmp_DESC);
				else
					qsort(album,num,sizeof(photo_t),intcmp_ASC);
			}

			//sort by genre
			else if(strcmp(arg2,"2")==0){
				if(strcmp(arg3,"DESC")==0)
					qsort(album,num,sizeof(photo_t),genre_strcmp_DESC);
				else
					qsort(album,num,sizeof(photo_t),genre_strcmp_ASC);
			}

			//sort by artist
			else if(strcmp(arg2,"3")==0){
				if(strcmp(arg3,"DESC")==0)
					qsort(album,num,sizeof(photo_t),artist_strcmp_DESC);
				else
					qsort(album,num,sizeof(photo_t),artist_strcmp_ASC);
			}

		}


		else{
			printf("Invalid Command\n");
		}


		memset(arg1,'\0',10);
		memset(arg2,'\0',10);
		memset(arg3,'\0',10);
	}


	for(int i=0;i<num;i++){
		free(album[i].name);
		free(album[i].genre);
		free(album[i].artist);

	}
	free(album);


	fclose(filep);
	return 0;
}