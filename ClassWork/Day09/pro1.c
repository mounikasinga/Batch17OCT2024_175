/*store odd values in array*/
#include <stdio.h>
int main() {
    // Write C code here
    int n,m,arr[100],i,count=0;
    scanf("%d %d",&n,&m);
    for(i=n;i<=m;i++)
    {
        if(i%2!=0)
        {
            arr[count]=i;
        }
    }
    for(i=0;i<=sizeof(arr[count]);i++)
    {
        printf("%d ",arr[i]);
        
    }

    return 0;
}
