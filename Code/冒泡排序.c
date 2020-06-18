#include<stdio.h>
int main()
{
    int c,e,a[4]={814,6,164},itemp;
    for(c=1; c<=3; c++)
    {
        for(e=3; e>=c; e--)
            if(a[e]<a[e-1])
            {
                itemp=a[e-1];
                a[e-1]=a[e];
                a[e]=itemp;
            }
    }
    for(c=1; c<=3; c++)
        printf("%d\t",a[c]);
    return 0;
}