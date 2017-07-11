//
//  main.cpp
//  Test
//
//  Created by Irony on 15/2/2017.
//  Copyright © 2017 Irony. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int main(void) {
    
    
    int xlen,ylen;
    if(scanf("%d %d",&xlen,&ylen)!=2){
        printf("Cannot decode\n");
        return 1;
    }
    if(xlen<0 || ylen<0){
        printf("Cannot decode\n");
        return 1;
    }
    
    int count_flag=0;
    int i,j;
    int **image;
    char tmp;
    image=(int**)malloc(ylen*sizeof(int*));
    for(i=0;i<ylen;i++)
        image[i]=(int*)malloc(xlen*sizeof(int));
    
    i=j=0;
    getchar();
    while(scanf("%c",&tmp)!=EOF){
        if(tmp!='\n'){
            image[j][i++]=(int)(tmp-'0');
            count_flag++;
            //printf("%d\n",image[j][(i-1)]);
        }
        else {
            j++;
            i=0;
        }
    }
    
    if(count_flag!=xlen*ylen){
        printf("Invalid image data\n");
        return 1;
    }
    
    
    int **x_result;//x_result[i][0] for number of gap
    int **y_result;
    
    x_result=(int**)malloc(ylen*sizeof(int*));
    for(i=0;i<ylen;i++)
        x_result[i]=(int*)malloc(xlen*sizeof(int));
    
    
    y_result=(int**)malloc(ylen*sizeof(int*));
    for(i=0;i<ylen;i++)
        y_result[i]=(int*)malloc(xlen*sizeof(int));
    
    for(j=0;j<ylen;j++)
        for(i=0;i<xlen;i++)
            x_result[j][i]=y_result[j][i]=0;
    
    
    int previous;
    for(j=0;j<ylen;j++){
        previous=0;
        for(i=0;i<xlen;i++){
            if(image[j][i]==0 && (previous!=0)){
                x_result[j][0]++;
                previous=0;
            }
            else if(image[j][i]==1){
                x_result[j][1+(x_result[j][0])]++;
                previous=1;
            }
        }
    }

    int y[1000]={0};
    
    for(i=0;i<xlen;i++){
        previous =0;
        for(j=0;j<ylen;j++){
            if(image[j][i]==0 && (previous!=0)){
                //y_result[0][i]= 1 + y_result[0][i];
                //printf("%d````", y_result[0][i]);
                y[i]++;
                previous=0;
            }
            else if(image[j][i]==1){
                y_result[ (1+y[i] )][i]=y_result[ (1+y[i] )][i] +1;
               // printf("%d",y_result[1+(y_result[0][i])][i]);
                //printf("%d %d %d\n",y_result[0][0],y_result[0][1],y_result[0][2]);
                previous=1;
            }
        }
    }
    //printf("%d %d %d\n",y_result[0][0],y_result[0][1],y_result[0][2]);

    printf("X:\n");
    for(j=0;j<ylen;j++){
        i=x_result[j][0];
        if(i==0){
            printf("0");
        }
        else{
            for(i=i+1;i>0;i--){
                if(i!=1 && x_result[j][i]!=0)
                    printf("%d ",x_result[j][i]);
                else if(x_result[j][i]!=0){
                    printf("%d",x_result[j][i]);
                }
            }
        }
        
        printf("\n");
    }
    printf("%d %d %d\n",y_result[0][0],y_result[0][1],y_result[0][2]);

    printf("\nY:\n");
    for(i=0;i<xlen;i++){
        j=y[i];
        //printf("%d %d %d",y_result[0][0],y_result[0][1],y_result[0][2]);
        if(j==0)
            printf("0");
        else{
            for(j=j+1;j>0;j--){
                if(j!=1 && y_result[j][i]!=0)
                    printf("%d ",y_result[j][i]);
                else if(y_result[j][i]!=0)
                    printf("%d",y_result[j][i]);
            }
        }
        printf("\n");
    }
    
    for(i=0;i<ylen;i++)
        free(image[i]);
    for(i=0;i<ylen;i++)
        free(x_result[i]);
    for(i=0;i<ylen;i++)
        free(y_result[i]);
    
    free(image);
    free(x_result);
    free(y_result);
    return 0;
}
