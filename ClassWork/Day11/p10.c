#include <stdio.h>
#define MUL 2
int main() {
   int i=1,res;
   do
   {
       res=MUL*i;
       printf("\n %d * %d = %d",MUL,i,res);
       i++;
   }while(i<=10);

    return 0;
}
