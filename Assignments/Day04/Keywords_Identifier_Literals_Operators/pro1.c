#include<stdio.h>
int main()
{
        int i,k=0;
	const int num=10;
/*        for(i = 0;i < 9;i++)
        {
                k = k + 1;
        } */
        //num = num + k; /* Compiler gives the error here */
        printf("final value of k:%d\n",k);
        printf("value of num:%d\n",num);
        return 0;
}

