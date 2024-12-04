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
INPUT:
5
1
2
3
1
4
OUTPUT:  1 2 3 4
#include <stdio.h>
 
int main() {
  
  printf("Enter the n value:");
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
  {
      printf("Enter the values:");
     scanf("%d",&arr[i]);
  }
  printf("The values are:");
  for(int i=0;i<n;i++)
  {
      
      printf("%d ",arr[i]);
  }
   int duplicate;
 
  
   printf("Unique elements: ");
   for (int i = 0; i < n; i++) {
       duplicate = 0;
 
       for (int j = 0; j < i; j++) {
           if (arr[i] == arr[j]) {
               duplicate = 1;
               break;
           }
       }
 
       if (!duplicate) {
           printf("%d ", arr[i]);
 
       }
   }
 
 
   return 0;
}
 
 
OR
#include <stdio.h>
 
int main() {
   printf("Enter the n value:");
   int n;
   scanf("%d",&n);
   int arr[n];
   int temp[n];
   for(int i=0;i<n;i++)
   {
       printf("Enter the elements:");
      scanf("%d",&arr[i]);
   }
   printf("Elements are:");
   for(int i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }
  
  int unique=0;
  int n1=0;
   printf("\nunique elemets:\n");
   for(int i=0;i<n;i++)
   {
       int count=0;
       for(int j=0;j<i;j++)
       {
           if(arr[i]==arr[j])
           {
               count=1;
               break;
           }
       }
       if(count==0)
       {
          temp[unique]=arr[i];
          n1++;
          unique++;
       }
   }
  
  // printf("\nSIZE:%d\n",n1);
 
  for(int i=0;i<n1;i++)
   {
       printf("%d ",temp[i]);
   }
 
   return 0;
}
 
OR
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int compare(const void *a, const void *b) {
  return(*(int *)a - *(int *)b);
}
 
int main() {
  int N;
  printf("Enter the N value:");
  scanf("%d", &N);
  int *array = (int *)malloc(N * sizeof(int));
  if (array == NULL) {
      printf("Memory allocation failed\n");
      return 1;
  }
 
  int *visited = (int *)malloc((N + 1) * sizeof(int));
  if (visited == NULL) {
      printf("Memory allocation failed\n");
      free(array);
      return 1;
  }
 
  for (int i = 0; i <= N; i++) {
      visited[i] = 0; 
  }
 
  for (int i = 0; i < N; i++) {
      printf("Enter the  %d value:\n",i);
      scanf("%d", &array[i]);
  }
  printf("\nUnique Elements are:\n");
  qsort(array, N, sizeof(int), compare); 
  for (int i = 0; i < N; i++) {
      if (i == 0 || array[i] != array[i - 1]) { 
          printf("%d\n", array[i]);
      }
  }
   free(array);
  free(visited);
  return 0;
}
DATE COMPARISION:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFF 1024
 
int main()
{
         int nTC=0;
         char date1[BUFF],date2[BUFF];
         int day1,day2,month1,month2,year1,year2;
         char *token=NULL;
         printf("Enter the value:");
         scanf("%d",&nTC);
         while(nTC--)
         {
             printf("Enter the date1:");
                    scanf("%s",date1);
             printf("Enter the date2:");
       scanf("%s",date2);
                    //tokenize and get the date,mm and year seperated
                    // for each date
                    token = strtok(date1,"/");
                    month1 = atoi(token);
                    token = strtok(NULL,"/");
                    day1 = atoi(token);
                    token = strtok(NULL,"/");
                    year1 = atoi(token); 
 
                    // printf("\n%d %d %d\n",day1,month1,year1);
 
                    token = strtok(date2,"/");
                    month2 = atoi(token);
                    token = strtok(NULL,"/");
                    day2 = atoi(token);
                    token = strtok(NULL,"/");
                    year2 = atoi(token); 
 
                    // printf("\n%d %d %d\n",day2,month2,year2);
                    
 
                    if(year1<year2)
                    {
                              printf("E\n");
                    }
                    else if(year1 > year2)
                    {
                              printf("L\n");
                    }
                    else
                    {
                              //both years are same
                              //now check for month in this block
                              if(month1<month2)
                              {
                                        printf("E\n");
                              }
                              else if(month1 > month2)
                              {
                                        printf("L\n");
                              }
                              else
                              {
                                        // printf("\nDates compared now %d %d\n",day1,day2);
                                        //both month is equal not check for day
                                        if(day1<day2)
                                        {
                                                  printf("E\n");
                                        }
                                        else if(day1 > day2)
                                        {
                                                  printf("L\n");
                                        }
                                        else
                                        {
                                                  printf("S\n");          
                                        }
                              }
                    } 
                    
         }
}
 
 
 
 
 
INPUT:  It is a simple problem
              Raspberry is sweet
              test
#include <stdio.h>
#include<string.h>
 
int findPosition(char *str,char *sub)
{
   char *pos=strstr(str,sub);
   if(pos!=NULL)
   {
       return pos-str;
   }
   return -1;
}
int main() {
   int n;
   scanf("%d",&n);
   getchar();
   for(int i=0;i<n;i++)
   {
       char str[100];
       fgets(str,100,stdin);
      str[strcspn(str,"\n")] = '\0';
       int posA =  findPosition(str,"a");
       int posIs = findPosition(str, "is");
       int sum=posA+posIs;
      printf("%d\n",sum);
   }
   return 0;
}
 
INPUT:  ANNMMC
             LLDKKD
            ANNLLDKKCMMD
OUTPUT: YES
 
#include <stdio.h>
#include <string.h>
 
int main() {
   char A[100], B[100], C[100];
   printf("Enter string A: ");
   fgets(A, sizeof(A), stdin);
   A[strcspn(A, "\n")] = 0; 
  
   printf("Enter string B: ");
   fgets(B, sizeof(B), stdin);
   B[strcspn(B, "\n")] = 0; 
  
   printf("Enter string C: ");
   fgets(C, sizeof(C), stdin);
   C[strcspn(C, "\n")] = 0;
  
   int canForm = 1;
  
  
   for (int i = 0; A[i] != '\0'; i++) {
       char found = 0;
       for (int j = 0; C[j] != '\0'; j++) {
           if (A[i] == C[j]) {
               C[j] = ' '; 
               found = 1;
               break;
           }
       }
       if (!found) {
           canForm = 0; 
           break;
       }
   }
  
  
   if (canForm) {
       for (int i = 0; B[i] != '\0'; i++) {
           char found = 0;
           for (int j = 0; C[j] != '\0'; j++) {
               if (B[i] == C[j]) {
                   C[j] = ' '; 
                   found = 1;
                   break;
               }
           }
           if (!found) {
               canForm = 0; 
               break;
           }
       }
   }
  
   if (canForm) {
       for (int i = 0; C[i] != '\0'; i++) {
           if (C[i] != ' ') {
               canForm = 0;
               break;
           }
       }
   }
   if (canForm) {
       printf("YES\n");
   } else {
       printf("NO\n");
   }
 
   return 0;
}
 
INPUT: velocity
               loc
                6
OUTPUT:   velocilocty
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char* addstring(char* ss,char* sss,int arr){
   int len1 = strlen(ss);
   int len2 = strlen(sss);
   int len3 = len1+len2;
   char* res = (char*)malloc((len3+1)*sizeof(char));
   int i,j,k=0;
   for(i =0;i<arr;i++){
       res[k++]=ss[i];
   }
   for(j = 0;j<len2;j++){
       res[k++]=sss[j];
   }
   for(i=arr;i<len1;i++){
       res[k++]=ss[i];
   }
   res[k]='\0';
   return res;
}
int main() {
   char ss[1000], sss[1000]; 
   int arr;
 
   printf("Enter the first string (ss): ");
   fgets(ss, sizeof(ss), stdin);
   ss[strcspn(ss, "\n")] = 0; 
 
   printf("Enter the second string (sss): ");
   fgets(sss, sizeof(sss), stdin);
   sss[strcspn(sss, "\n")] = 0; 
 
   printf("Enter the insertion index (arr): ");
   scanf("%d", &arr);
 
   char* result = addstring(ss, sss, arr);
   if (result != NULL) {
       printf("Resulting string: %s\n", result);
       free(result); 
   }
 
   return 0;
}
GOOD ARRAY OR NOT:
INPUT:  5
              3  12 120 24 1
OUTPUT: YES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int compare(const void *a,const void *b){
   return(*(int*)a-*(int* )b);
}
char* solve(int a_count, int* a){
  qsort(a,a_count,sizeof(int),compare);
   for(int i=0;i<a_count-1;i++){
       if(a[i+1]%a[i]!=0){
           return "No";
       }
   }
   return "Yes";
}
int main() {
   int a_count;
   scanf("%d", &a_count);
   int* a = (int*)malloc(a_count * sizeof(int)); 
   for (int i = 0; i < a_count; i++) {
       scanf("%d", &a[i]);
   }
 
   char* result = solve(a_count, a);
   printf("%s\n", result);
   free(a);
   return 0;
}
#include <stdio.h>
#include <stdlib.h>

void sort(long arr[], int n)
{
    int i, j;
    long temp;
    for(i = 0; i < n - 1; i++) // Fix the loop condition
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j]) // Descending order
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

long* solution(int array_count, long* array, int* result_count)
{
    int maxsize = 100;
    int idx = 0;
    long* size = (long*)malloc(sizeof(long) * maxsize); // Dynamic memory allocation

    sort(array, array_count); // Corrected function call

    for(int i = 0; i < array_count; i++)
    {
        // Fix duplicate removal logic
        if(i == 0 || array[i] != array[i - 1]) // Compare with previous element
        {
            size[idx++] = array[i];
        }
    }

    *result_count = idx;
    return size;
}

int main() {
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n); // Corrected scanf usage

    long* arr = (long*)malloc(sizeof(long) * n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }

    int result_count;
    long* result = solution(n, arr, &result_count);

    printf("Sorted array without duplicates:\n");
    for(int i = 0; i < result_count; i++)
    {
        printf("%ld ", result[i]);
    }

    free(arr);  // Free the dynamically allocated memory
    free(result);  // Free the result array
    return 0;
}
#include <stdio.h>
  2 #include <string.h>
  3 #define MAX 20
  4 int ispanagram(char *,int);
  5 char *reverse(char *,int);
  6 char *rotate(char *,int);
  7 int main()
  8 {
  9     int stlen;
10     char str[MAX];
11     fgets(str,MAX,stdin);
12     str[strlen(str)-1]='\0';
13     stlen=strlen(str);
14     if(ispanagram(str,stlen)==0)
15         printf("\nTrue\n");
16     else
17         printf("\nfalse\n");
18     return 0;
19 }
20
21 int ispanagram(char *input,int n)
22 {
23     int i=0;
24     char temp1[n];
25     char temp2[n];
26     char temp3[n];
27     strcpy(temp1,input);
28     strcpy(temp2,input);
29     while(i<n)
30     {
31         strcpy(temp3,input);
32         if(strcmp(temp2,reverse(temp3,n))==0)
33         {
34             return 0;
35         }
36         input=rotate(temp1,n);
37
38         i++;
39     }
40     return 1;
41 }
42
43 char *reverse(char *string,int n)
44 {
45     int i;
46     char temp;
47     int mid=n/2;
48     for(i=0;i<mid;i++)
49     {
50         temp=string[n-i-1];
51         string[n-i-1]=string[i];
52         string[i]=temp;
53     }
54     return string;
55 }
56 char *rotate(char *st,int n)
57 {
58     int i;
59     char temp;
60     char temp1;
61     temp=st[0];
62     st[0]=st[n-1];
63     for(i=1;i<n;i++)
64     {
65         temp1=st[i];
66         st[i]=temp;
67         temp=temp1;
68     }
69     return st;
70
71 }

#include <stdio.h>
#include <string.h>

#define MAX 20

int getD(char *, char *, int);

int main() {
    int N;
    char D[MAX] = "";  // Initialize D as an empty string with enough space
    printf("\n%s", D);

    char M[MAX];
    fgets(M, MAX, stdin);
    
    N = strlen(M) - 1;  // Remove the newline character added by fgets
    if (getD(M, D, N) == 0)
        printf("%s", D);  // Print the resulting string D
    else
        return 1;
    
    return 0;
}

int getD(char *M, char *D, int N) {
    int i, j = 0, k = N / 2;

    if (N == 0) {
        printf("\nThe M string is empty\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        if ((i + 1) % 2 != 0) {  // Odd index (1-based)
            D[j] = M[i];
            j++;
        } else {  // Even index (1-based)
            D[k] = M[i];
            k++;
        }
    }

    D[N] = '\0';  // Properly null-terminate the string
    return 0;
}
