#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#define BUFF 1025
int main()
{
    int fd[2];
    pid_t cpid;
    char line[BUFF];
    pipe(fd);
    cpid=fork();
    if(cpid==0)
    {
        close(fd[0]);
        write(fd[1],"Hello World\n",12);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close(fd[1]);
        //wait(1);
        read(fd[0],line,BUFF);
        printf("\nLine read\n%s",line);
        
    }
    printf("\nEnd Program\n");
    return 0;
}
