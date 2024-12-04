 #include<stdio.h>
 #include<stdlib.h>
 int main()
 {
         int n,*a,i,end,sum,currentsum=0;
         scanf("%d",&n);
         a=(int *)malloc(n*sizeof(int));
         for(i=0;i<n;i++)
         {
                scanf("%d",&a[i]);
         }
         printf("\nsum = ");
         scanf("%d",&sum);
         for(i=0;i<n;i++)
         {
                 for(end=i;end<n;end++)
                 {
                         currentsum+=a[end];
                         if(currentsum==sum)
                                 printf("\nSum found between indexes %d and %d",i,end);
                 }
         }
 }
