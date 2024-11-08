/*
A4. rotate array every kth element
1 2 3 4 5 6 7 8 9
k= 3
3 2 1 6 5 4 9 8 7
*/
#include<stdio.h>
void rotate_arr(int arr[],int n,int k)
{
    int j,i,temp,num;
    for(i=0;i<n;i+=k){
        num=i+k;
        if(num>n){
            num=n;
        }
        for(j=i;j<(i+(num-i)/2);j++)
        {
            temp=arr[j];
            arr[j]=arr[num-(j-i)-1];
            arr[num-(j-i)-1]=temp;
        }
    }
}
int main(){
    int arr[100],k,n,i;
    printf("k= ");
    scanf("%d",&k);
    printf("n= ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    rotate_arr(arr,n,k);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    
}
