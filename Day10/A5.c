/*A5.
Write a c program to print alphabet triangle.
Input: 5
Output:

     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA



     1
    121
   12321
  1234321
 123454321
 */


#include <stdio.h>
void Alphabet_triangle(int n) {
    int i,j;
    char ch=65;
    for(i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            printf(" ");
        }
        for(j=0;j<=i;j++) {
            printf("%c",ch+j);
        }
        for(j=i-1;j>=0;j--) {
            printf("%c",ch+j);
        }
        printf("\n");
    }
}
int Number_triangle(int n)
{
    int i,j;
    for(i=1;i<=n;i++) {
        for(j=1;j<n-i;j++) {
            printf(" ");
        }
        for(j=1;j<=i;j++) {
            printf("%d",j);
        }
        for(j=i-1;j>=1;j--) {
            printf("%d",j);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d",&n);
    Alphabet_triangle(n);
    printf("\n\n");
    Number_triangle(n);
    return 0;
}