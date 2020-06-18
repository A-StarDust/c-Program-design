#include<stdio.h>
int main()
{
    int a[5];
    int max,min,i,j;
    printf("选择法排序，从大到小\n");
    for(i=0; i<5; i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
    for(i=0; i<4; i++)
    {
        max=a[i];
        min=i;
        for(j=i+1; j<5; j++)
        {
            if(a[j]>max)
        //实现从小到大，只需把符号换成相反的
            {
                max=a[j];
                min=j;
            }
        }
        a[min]=a[i];
        a[i]=max;
    }
    for(i=0; i<5; i++)
        printf("%d\t",a[i]);
}
/*制作人时空尘*/