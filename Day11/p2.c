 #include<stdio.h>
  2 #include<stdlib.h>
  3 int main()
  4 {
  5         int n,*a,i,end,sum,currentsum=0;
  6         scanf("%d",&n);
  7         a=(int *)malloc(n*sizeof(int));
  8         for(i=0;i<n;i++)
  9         {
 10                 scanf("%d",&a[i]);
 11         }
 12         printf("\nsum = ");
 13         scanf("%d",&sum);
 14         for(i=0;i<n;i++)
 15         {
 16                 for(end=i;end<n;end++)
 17                 {
 18                         currentsum+=a[end];
 19                         if(currentsum==sum)
 20                                 printf("\nSum found between indexes %d and %d",i,end);
 21                 }
 22         }
 23 }
