#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    
    if(argc<4){
        printf("Invalid arguments length\n");
        return 1;
    }
    
    char *eptr;
    
    long start= strtol(&argv[2][0],&eptr,10);
    long iteration= strtol(&argv[3][0],&eptr,10);

    int strlength;
    int position=start;
    int flag;
    int count;

    for(count=0;argv[2][count]!='\0';count++);
    for(strlength=0;argv[1][strlength]!='\0';strlength++);

    for(int i=0;i<count;i++)
        if(argv[2][i]<'0'||argv[2][i]>'9')
        {
            printf("Invalid start position\n");
            return 1;
        }
    
    if(iteration<0){
        printf("Invalid iteration count\n");
        return 1;
    }
    
    
    if(start<0||start>strlength-1){
        printf("Invalid start position\n");
        return 1;
    }

       if(start!=strlength-1)
        flag=0;
    else
        flag=1;

    if(strlength==1)
        for(;iteration>0;iteration--)
            printf("%c",argv[1][0]);
    
    for(iteration+=1;iteration>0;iteration--){
        if(flag%2==0){
            printf("%c",argv[1][position++]);
            if(position==strlength-1)
                flag++;
        }
        else if(flag%2==1){
            printf("%c",argv[1][position--]);
            if(position==0)
                flag++;
        }
    }
    
    printf("\n");
    
}