#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atoms.h"

#define MAX 100


/*checklist for parameter:
 hasLoaded,hasStarted : flag for the game status
 num : number of player readed from stdin
 grid[width][height] : the grid Graph
 limit[width][height] : store the limitation of each grid
 players[MAX_PLAYERS] : store the information of each players
 Round : count for the Round
 CurrentPlayer : Current player
 totalStep : the step counted from the beginning
 step : used for some function (temp use)
 maxStep : the maximum step (for free)
 PlayerList : store the player still have not lost
 */


//HELP MENU
void HELP(void){
    printf("\nHELP displays this help message\n");
    printf("QUIT quits the current game\n");
    printf("\nDISPLAY draws the game board in terminal\n");
    printf("START <number of players> <width> <height> starts the game\n");
    printf("PLACE <x> <y> places an atom in a grid space\n");
    printf("UNDO undoes the last move made\n");
    printf("STAT displays game statistics\n");
    printf("\nSAVE <filename> saves the state of the game\n");
    printf("LOAD <filename> loads a save file\n");
    printf("PLAYFROM <turn> plays from n steps into the game\n\n");
}

//DISPLAY
void DISPLAY(grid_t** grid,int width,int height,char colorString[6][7]){
    //first line
    printf("\n");
    printf("+");
    for(int i=0;i<3*width-1;i++){
        printf("-");
    }
    printf("+\n");
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(grid[j][i].atom_count!=0){
                printf("|%c%d",colorString[grid[j][i].owner][0],grid[j][i].atom_count);
            }
            else{
                printf("|  ");
            }
        }
        printf("|\n");
    }
    //last line
    printf("+");
    for(int i=0;i<3*width-1;i++){
        printf("-");
    }
    printf("+\n");
    printf("\n");
}


void STAT(player_t* players,int num,char colorString[6][7]){
    
    for(int i=0;i<num;i++){
        if(players[i].grids_owned!=-1){
            printf("Player %s:\n",&colorString[i][0]);
            printf("Grid Count: %d\n\n",players[i].grids_owned);
        }
        else{
            printf("Player %s:\n",&colorString[i][0]);
            printf("Lost\n\n");
        }
    }
    
}

void PLACE(grid_t** grid,int x,int y,enum color CurrentPlayer,player_t players[MAX_PLAYERS],int** limit,int width,int height){
    
    if(grid[x][y].atom_count==0){
        grid[x][y].owner=CurrentPlayer;
        grid[x][y].atom_count++;
        players[CurrentPlayer].grids_owned++;
    }
    
    else if(grid[x][y].owner!= CurrentPlayer){//not belong to old_owner
        players[CurrentPlayer].grids_owned++;
        players[grid[x][y].owner].grids_owned--;
        grid[x][y].atom_count++;
        grid[x][y].owner = CurrentPlayer;
    }
    
    else if(grid[x][y].owner == CurrentPlayer){
        grid[x][y].atom_count++;
    }
    
    //Using recursion to expand
    if(grid[x][y].atom_count==limit[x][y]){
        grid[x][y].atom_count=0;
        players[CurrentPlayer].grids_owned--;
        if(x==0){
            if(y==0){//left-top
                PLACE(grid,x+1,y,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x,y+1,CurrentPlayer,players,limit,width,height);
            }
            else if(y==height-1){
                PLACE(grid,x,y-1,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x+1,y,CurrentPlayer,players,limit,width,height);
            }
            else{
                PLACE(grid,x,y-1,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x+1,y,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x,y+1,CurrentPlayer,players,limit,width,height);
            }
        }
        
        else if(y==0){
            if(x==width-1){
                PLACE(grid,x,y+1,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x-1,y,CurrentPlayer,players,limit,width,height);
            }
            else{
                PLACE(grid,x+1,y,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x,y+1,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x-1,y,CurrentPlayer,players,limit,width,height);
            }
        }
        
        else if(x==width-1){
            if(y==height-1){
                PLACE(grid,x,y-1,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x-1,y,CurrentPlayer,players,limit,width,height);
            }
            else{
                PLACE(grid,x,y-1,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x,y+1,CurrentPlayer,players,limit,width,height);
                PLACE(grid,x-1,y,CurrentPlayer,players,limit,width,height);
            }
        }
        
        else if(y==height-1){
            PLACE(grid,x,y-1,CurrentPlayer,players,limit,width,height);
            PLACE(grid,x+1,y,CurrentPlayer,players,limit,width,height);
            PLACE(grid,x-1,y,CurrentPlayer,players,limit,width,height);
        }
        
        else{
            PLACE(grid,x,y-1,CurrentPlayer,players,limit,width,height);
            PLACE(grid,x+1,y,CurrentPlayer,players,limit,width,height);
            PLACE(grid,x,y+1,CurrentPlayer,players,limit,width,height);
            PLACE(grid,x-1,y,CurrentPlayer,players,limit,width,height);
        }
    }
    
}


void SAVE(char filename[30],save_file_t savefile,int totalStep){
    FILE *fp = fopen(filename,"wb");
    if(fp==NULL){
        printf("Cannot save the file\n");
        fclose(fp);
        return;
    }
    else{
        fwrite(&savefile.width,sizeof(uint8_t),1,fp);
        fwrite(&savefile.height,sizeof(uint8_t),1,fp);
        fwrite(&savefile.no_players,sizeof(uint8_t),1,fp);
        for(int i=0;i<totalStep;i++)
            for(int j=0;j<4;j++)
                fwrite(&savefile.raw_move_data[i][j],sizeof(uint8_t),1,fp);
        
        fclose(fp);
    }
    
}


void PLAYFROM(int step,save_file_t savefile){
    
}


int main(int argc, char** argv) {
    
    char input[MAX];
    
    char command[10];//store the command from user
    char filename[30];//name of the savefile
    save_file_t savefile;
    char junk[MAX];//get the junk
    int num1=-1,num2=-1,num3=-1;//3 variables for getting the input
    int count;
    int hasStarted = 0;//a flag for detecting whether the game has started or not
    int hasLoaded = 0;//a flag for detecting whether the game has been loaded
    int width,height,num;//width, height. number of player
    grid_t** grid;// the Grid Graph
    int** limit;//Store the limitation for each grid
    
    player_t players[MAX_PLAYERS];//a array to store the information of players
    char colorString[6][7]={"Red","Green","Purple","Blue","Yellow","White"};
    int Round = 0;//used for determining which player's turn
    int CurrentNum = 0;//number of current players
    int totalStep = 0;//number of the total steps
    int step;//step we currently use for some function
    int maxStep=-1;
    enum color PlayerList[MAX_PLAYERS]={empty,empty,empty,empty,empty,empty};
    
    
    while(1){
        fgets(input,MAX,stdin);
        
        sscanf(input,"%s ",command);
        if(strcmp(command,"LOAD")!=0 && strcmp(command,"SAVE")!=0 &&strcmp(command,"PLAYFROM")!=0)
            count = sscanf(input, "%s %d %d %d %s",command,&num1,&num2,&num3,junk);
        else
            count = sscanf(input, "%s %s %d %d %s",command,filename,&num2,&num3,junk);
        
        // printf("count = %d\n",count);
        // printf("command is %s\n",command);
        // printf("num1: %d\nnum2: %d\nnum3: %d\n",num1,num2,num3);
        
        
        //----------------------------HELP----------------------------
        if(strcmp(command,"HELP")==0){
            HELP();
        }
        
        else if(hasLoaded==1 && strcmp(command,"QUIT")!=0 && strcmp(command,"PLAYFROM")!=0){
            printf("Invalid Command\n");
        }
        
        //----------------------------START----------------------------
        else if(strcmp(command,"START")==0){
            //determine whether it is a valid input
            int start_flag=0;
            CurrentNum = num = num1;
            width = num2;
            height = num3;
            if(num >= width * height){
                printf("Cannot Start Game\n");
                start_flag=1;
            }
            else if(count < 4){
                printf("Missing Arguments\n");
                start_flag=1;
            }
            else if(count > 4){
                printf("Too Many Arguments\n");
                start_flag=1;
            }
            else if(width<MIN_WIDTH || height<MIN_HEIGHT || num<MIN_PLAYERS ||
                    width>MAX_WIDTH || height>MAX_HEIGHT || num>MAX_PLAYERS){
                printf("Invalid command arguments\n");
                start_flag=1;
            }
            else if(hasStarted==1){
                printf("Invalid Command\n");
                start_flag=1;
            }
            if(start_flag!=1){
                
                
                //initialize the savefile
                savefile.raw_move_data = (uint8_t**)malloc(sizeof(uint8_t*));
                savefile.raw_move_data[0] = (uint8_t*)malloc(4 * sizeof(uint8_t));
                savefile.width = width;
                savefile.height = height;
                savefile.no_players = num;
                
                printf("Game Ready\n");
                printf("Red's Turn\n\n");
                
                
            INITIAL:
                //Ready to Start
                hasStarted=1;
                //grid[width][height]
                grid = (grid_t**)malloc(width*sizeof(grid_t*));
                limit = (int **)malloc(width*sizeof(int*));
                
                for(int i=0;i<width;i++){
                    grid[i]= (grid_t*)malloc(height*sizeof(grid_t));
                    limit[i]=(int*)malloc(height*sizeof(int));
                }
                for(int i=0;i<width;i++)
                    for(int j=0;j<height;j++){
                        //grid[i][j].owner = (player_t*)malloc(sizeof(player_t));
                        grid[i][j].owner=empty;
                        grid[i][j].atom_count = 0;
                        if(i==0 || j==0 || i==(width-1) || j==(height-1))
                            limit[i][j]=3;
                        else
                            limit[i][j]=4;
                    }
                limit[0][0]=limit[0][height-1]=limit[width-1][0]=limit[width-1][height-1]=2;
                
                //initialize the game
                // game_t game;
                // game.moves = (move_t*)malloc(sizeof(move_t));
                
                //initialie the players array
                for(int i=0;i<num;i++){
                    players[i].colour=i;
                    players[i].grids_owned = 0;
                    PlayerList[i]=i;
                }
                
            }
            
        }
        
        //----------------------------DISPLAY----------------------------
        else if(strcmp(command,"DISPLAY")==0){
            if(hasStarted==1)
                DISPLAY(grid,width,height,colorString);
            else
                printf("Invalid Command\n");
        }
        
        //----------------------------STAT----------------------------
        else if(strcmp(command,"STAT")==0){
            if(hasStarted==1)
                STAT(players,num,colorString);
            else
                printf("Invalid Command\n");
        }
        
        //----------------------------PLACE----------------------------
        else if(strcmp(command,"PLACE")==0){
            if(hasStarted==1){
                int x = num1;
                int y = num2;
                //determine the validity of the input
                if(count < 3){
                    printf("Missing Arguments\n");
                }
                else if(x<0 || y<0 || x >= width || y>=height){
                    printf("Invalid Coordinates\n");
                }
                else if( (grid[x][y].owner!=empty) && (grid[x][y].owner!=PlayerList[Round%CurrentNum])){
                    printf("Cannot Place Atom Here\n");
                }
                else{
                    enum color CurrentPlayer = PlayerList[Round%CurrentNum];
                    PLACE(grid,x,y,CurrentPlayer,players,limit,width,height);
                    
                    //update the savefile
                    savefile.raw_move_data[totalStep][0]=(uint8_t)x;
                    savefile.raw_move_data[totalStep][1]=(uint8_t)y;
                    savefile.raw_move_data[totalStep][2]=savefile.raw_move_data[totalStep][3]=(uint8_t)0;
                    savefile.raw_move_data = (uint8_t**)realloc(savefile.raw_move_data,(totalStep+2)*sizeof(uint8_t*));
                    savefile.raw_move_data[totalStep+1] = (uint8_t*)malloc(4 * sizeof(uint8_t));
                    totalStep++;
                    //After PLACE, check if someone Lost, if lost set the count to -1
                    
                    if(totalStep>num){
                        int tmp=CurrentNum;
                        for(int i=0;i<tmp;i++){
                            if(players[i].grids_owned==0){// find the losser
                                
                                players[i].grids_owned=-1;
                                //remove the player from PlayerList
                                for(int k=0;k<CurrentNum;k++)
                                    if(PlayerList[k]==i)
                                        for(int m=k;m<CurrentNum-1;m++)//move forward
                                            PlayerList[m]=PlayerList[m+1];
                                
                                CurrentNum--;
                                
                            }
                        }
                        //reset the Round
                        for(int j=0;j<CurrentNum;j++)
                            if(PlayerList[j]==CurrentPlayer)
                                Round=j;
                    }
                    
                    if(CurrentNum!=1){
                        Round++;
                        printf("%s\'s Turn\n\n",colorString[PlayerList[(Round)%CurrentNum]]);
                    }
                    //someone wins
                    else{
                        printf("%s Wins!\n",&colorString[PlayerList[0]][0]);
                        for(int i=0;i<width;i++){
                            free(grid[i]);
                            free(limit[i]);
                        }
                        free(grid);
                        free(limit);
                        if(maxStep<totalStep)
                            maxStep=totalStep;
                        for(int i=0;i<=maxStep;i++){
                            free(savefile.raw_move_data[i]);
                        }
                        free(savefile.raw_move_data);
                        exit(1);
                    }
                }
                
            }
            
        }
        
        //----------------------------SAVE----------------------------
        else if(strcmp(command,"SAVE")==0){
            if(count<2)
                printf("Missing Arguments\n");
            else if(count >2)
                printf("Too Many Arguments\n");
            else{
                SAVE(filename,savefile,totalStep);
                printf("Game Saved\n\n");
            }
        }
        
        
        //----------------------------LOAD----------------------------
        //Load the file into "savefile"
        else if(strcmp(command,"LOAD")==0){
            if(count<2)
                printf("Missing Arguments\n");
            else if(count >2)
                printf("Too Many Arguments\n");
            else if(hasStarted==1){
                printf("Restart Application To Load Save\n");
            }
            else{
                FILE *fp = fopen(filename,"rb");
                if(fp==NULL){
                    printf("Cannot Load Save\n");
                }
                else{
                    hasLoaded=1;
                    fread(&savefile.width,sizeof(uint8_t),1,fp);
                    fread(&savefile.height,sizeof(uint8_t),1,fp);
                    fread(&savefile.no_players,sizeof(uint8_t),1,fp);
                    savefile.raw_move_data = (uint8_t**)malloc(sizeof(uint8_t*));
                    savefile.raw_move_data[0] = (uint8_t*)malloc(4 * sizeof(uint8_t));
                    totalStep=0;
                    width=savefile.width;
                    height=savefile.height;
                    CurrentNum=num=savefile.no_players;
                    
                    // for(int i=0;i<CurrentNum;i++)
                    // 	PlayerList[i]=i;
                    //int flag=1;
                    while(fread(&savefile.raw_move_data[totalStep][0],sizeof(uint8_t),1,fp)!=0){
                        fread(&savefile.raw_move_data[totalStep][1],sizeof(uint8_t),1,fp);
                        //savefile.raw_move_data[totalStep][2]=savefile.raw_move_data[totalStep][3]=(uint8_t)0;
                        fread(&savefile.raw_move_data[totalStep][2],sizeof(uint8_t),1,fp);
                        fread(&savefile.raw_move_data[totalStep][3],sizeof(uint8_t),1,fp);
                        savefile.raw_move_data = (uint8_t**)realloc(savefile.raw_move_data,(totalStep+2)*sizeof(uint8_t*));
                        savefile.raw_move_data[totalStep+1] = (uint8_t*)malloc(4 * sizeof(uint8_t));
                        //                        printf("%d %d\n",savefile.raw_move_data[totalStep][0],savefile.raw_move_data[totalStep][1]);
                        totalStep++;
                    }
                    printf("Game Loaded\n\n");
                    if(maxStep<totalStep)
                        maxStep=totalStep;
                    
                    goto INITIAL;
                    
                }
            }
        }
        
        
        else if(strcmp(command,"PLAYFROM")==0&&hasLoaded==1){
            
            if(strcmp(filename,"END")==0){
                step=totalStep;
                goto RELOAD;
                //printf("Game Ready\n");
            }
            
            else{
                step=(int)strtol(filename,NULL,10);
                if(step<0){
                    printf("Invalid Turn Number\n");
                }
                else{
                RELOAD:
                    printf("Game Ready\n");
                    if(step>totalStep)
                        step=totalStep;
                    
                    //the rest steps are PLACE step times
                RECURSION:
                    totalStep=0;
                    Round=0;
                    for(int c=0;c<step;c++){
                        //PLACE(grid,x,y,CurrentPlayer,players,limit,width,height);
                        enum color CurrentPlayer = PlayerList[Round%CurrentNum];
                        PLACE(grid,savefile.raw_move_data[c][0],savefile.raw_move_data[c][1],CurrentPlayer,players,limit,width,height);
                        Round++;
                        totalStep++;
                        if(totalStep>num){
                            int tmp=CurrentNum;
                            for(int i=0;i<tmp;i++){
                                if(players[i].grids_owned==0){// find the losser
                                    
                                    players[i].grids_owned=-1;
                                    //remove the player from PlayerList
                                    for(int k=0;k<CurrentNum;k++)
                                        if(PlayerList[k]==i)
                                            for(int m=k;m<CurrentNum-1;m++)//move forward
                                                PlayerList[m]=PlayerList[m+1];
                                    
                                    CurrentNum--;
                                    
                                }
                            }
                            //reset the Round
                            for(int j=0;j<CurrentNum;j++)
                                if(PlayerList[j]==CurrentPlayer)
                                    Round=j;
                        }
                        
                    }
                    
                    //after repeating PLACE, finally start the game
                    if(CurrentNum!=1){
                        //Round++;
                        printf("%s\'s Turn\n\n",colorString[PlayerList[(Round)%CurrentNum]]);
                    }
                    //someone wins
                    else{
                        printf("%s Wins!\n",&colorString[PlayerList[0]][0]);
                        for(int i=0;i<width;i++){
                            free(grid[i]);
                            free(limit[i]);
                        }
                        free(grid);
                        free(limit);
                        if(maxStep<totalStep)
                            maxStep=totalStep;
                        for(int i=0;i<=maxStep;i++){
                            free(savefile.raw_move_data[i]);
                        }
                        free(savefile.raw_move_data);
                        exit(1);
                    }
                    
                    
                }
            }
            //Finish the LOAD, set hasLoaded to 0
            hasLoaded=0;
        }
        
        //----------------------------UNDO------------------------------
        //Using the LOAD to UNDO
        else if(strcmp(command,"UNDO")==0){
            
            if(totalStep==0){
                printf("Cannot Undo\n");
            }
            else{
                //re-initialize all the parameters
                CurrentNum=num;
                step=totalStep-1;//UNDO - move back one step
                
                for(int i=0;i<num;i++){
                    players[i].colour=i;
                    players[i].grids_owned = 0;
                    PlayerList[i]=i;
                }
                for(int i=0;i<width;i++)
                    for(int j=0;j<height;j++){
                        grid[i][j].owner=empty;
                        grid[i][j].atom_count = 0;
                    }
                if(maxStep<totalStep)
                    maxStep=totalStep;
                goto RECURSION;
                
            }
        }
        
        //----------------------------QUIT------------------------------
        else if(strcmp(command,"QUIT")==0){
            printf("Bye!\n");
            //-----------free---------
            if(hasStarted==1){
                for(int i=0;i<width;i++){
                    free(grid[i]);
                    free(limit[i]);
                }
                free(grid);
                free(limit);
                if(maxStep<totalStep)
                    maxStep=totalStep;
                for(int i=0;i<=maxStep;i++){
                    free(savefile.raw_move_data[i]);
                }
                free(savefile.raw_move_data);
            }
            exit(0);
        }
        else
            printf("Invalid Command\n");
        
    }
    
    for(int i=0;i<width;i++){
        free(grid[i]);
        free(limit[i]);
    }
    free(grid);
    free(limit);
    if(maxStep<totalStep)
        maxStep=totalStep;
    for(int i=0;i<=maxStep;i++){
        free(savefile.raw_move_data[i]);
    }
    free(savefile.raw_move_data);
    
    return 0;
}
