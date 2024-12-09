/*A1. Check whether a given number can be expressed as the sum of two prime number

i/p
Enter a positive integer: 34
Output
34 = 3 + 31

34 = 5 + 29
34 = 11 + 23
34 = 17 + 17
NoofWays = 4
*/


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int isPrime(int n)
{
    int i;
    if(n<=1)
        return false;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int find_prime(int N){
    int count=0,i;
    for(i=2;i<=N/2;i++){
        if(isPrime(i)&&isPrime(N-i)){
            printf("\n%d = %d + %d",N,i,N-i);
            count++;
        }
    }
    printf("\n\nNoofWays = %d",count);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    find_prime(n);
    return 0;
}
https://github.com/mehak0205/DND-client-server-implementation/blob/main/HDR/server_header.h
