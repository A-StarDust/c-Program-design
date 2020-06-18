#include<stdio.h>
#include<stdlib.h>
#include<time.h>//用来获取随随机数
int main()
{
    int a,b,point,c;
    do
    {
        printf("输入你猜的骰子点数\n只能是1—6的数字\n");
        scanf("%d",&b);
        srand((unsigned int)time(0));//初始化种子
        for(a=0; a<1; a++) //循环生成数字
        {
            point=rand()%6+1;//产生随机数点数，%6+1是生成范围1-6的数值
        }
        if(b==point)
            printf("正确\n");
        else
            printf("错误，正确答案是%d\n",point);
        printf("是否退出\n是输入0否输入1\n");
        scanf("%d",&c);
    } while(c);
}
/*
时空尘，猜骰子点数
注:半成品
*/