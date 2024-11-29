#include<stdio.h>
 #include<stdlib.h>
#include<string.h>
 #include<sys/types.h>
 #include<unistd.h>
 #include<sys/wait.h>
 int main(int argc, char *argv[])
 {
     char *temp[5];
     int i;
     for(i=0;i<5;i++)
     {
         temp[i]=(char *)malloc(1024);
     }
     /*strcpy(temp[0],argv[1]);
     strcpy(temp[1],argv[2]);
     strcpy(temp[2],argv[3]);
     strcpy(temp[3],argv[4]);
     temp[4]=(char *)0;*/
     if(strcmp(argv[1],"cal")==0)
     {
         strcpy(temp[0],argv[1]);
         strcpy(temp[1],argv[2]);
         strcpy(temp[2],argv[3]);
         strcpy(temp[3],argv[4]);
         temp[4]=(char *)0;
     }/*
     else if(strcmp(argv[1],"area")==0)
     {
         strcpy(temp[0],argv[1]);
         strcpy(temp[1],argv[2]);
         strcpy(temp[2],argv[3]);
         strcpy(temp[3],argv[4]);
         temp[4]=(char *)0;
     }*/
     execv(argv[1],temp);
     printf("\nThis will not print at all\n\n");

	return 0;
}
