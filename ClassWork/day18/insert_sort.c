#include<stdio.h>
#include<stdlib.h>
int insert_sort(int *arr,int n)
{
	int i,j,key;
	for(i=0;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j-=1;
		}
		arr[j+1]=key;
	}
}
int main() {
      int n, *arr;
      printf("Enter number of elements: ");
      scanf("%d", &n);
 
      arr = (int *)malloc(n * sizeof(int));
 
      printf("Enter the elements:\n");
      for(int i = 0; i < n; i++) {
          scanf("%d", &arr[i]);
      }
 
      insert_sort(arr,n);
 
      printf("insertstion array:\n");
      for(int i = 0; i < n; i++) {
          printf("%d\n ", arr[i]);
      }
 
      free(arr);
 
      return 0;
  }


