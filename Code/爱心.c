#include<stdio.h>
int main()
{
    int n,k,m,p,q;
    for(n=1; n<=2; n++)
    {
        for(k=1; k<=15-n; k++)
            printf(" ");
        for(m=1; m<=2*n; m++)
            printf("*");
        for(p=1; p<=5-2*n; p++)
            printf(" ");
        for(q=1; q<=2*n; q++)
            printf("*");
        printf("\n");
    }
    for(n=3; n<=7; n++)
    {
        for(k=1; k<=10+n; k++)
            printf(" ");
        for(m=1;m<=15-2*n;m++)
        printf("*");
        printf("\n");
    }
    return 0;
}