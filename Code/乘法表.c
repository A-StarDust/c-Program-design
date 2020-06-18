#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    for(a=1; a<=9; a++)
    {
        for(b=1; b<=a; b++)
        {
            printf("%d*%d=%d",b,a,a*b);
            printf("\t");
        }
        printf("\n");
    }
}