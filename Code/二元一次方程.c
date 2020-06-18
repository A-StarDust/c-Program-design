#include<stdio.h>
#include<math.h>
int main()
{
    while(1)
    {
        double a,b,c,date;
        printf("请输入a的值（a不等于0）：");
        scanf("%lf",&a);
        if(a!=0)
        {
            printf("请输入b的值：");
            scanf("%lf",&b);
            printf("请输入c的值：");
            scanf("%lf",&c);
            date=sqrt(b*b-4*a*c);
            if(date>0)
            {
                printf("此二元一次方程共有两个值，分别为\n");
                printf("x1的值为%lf\tx2的值为%lf\n",(-b+date)/2*a,(-b-date)/2*a);
            }
            else if(date==0)
            {
                printf("此二元一次方程共有一个值，分别为\n");
                printf("x1=x2的值为%lf\n",-(b/2*a));
            }
            else if(date<0)
            {
                printf("此二元一次方程无值\n");
            }
        }
        else
        {
            printf("输入值有错，请重新输入\n");
        }
    }
}