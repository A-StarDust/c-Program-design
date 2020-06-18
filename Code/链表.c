#include<stdio.h>
#include<stdlib.h>
struct message
{
    char name[10];
    int age;
    struct messgae *one;
};
int a;
struct message *two()
{
    struct message *Head=NULL;
    struct message *End,*New;
    a=0;
    End=New=(struct message*)malloc(sizeof(struct message));
    printf("输入名字和年龄\n结束输入在年龄一栏输入0\n");
	printf("name:");
    scanf("%s",&New->name);
	printf("age:");
    scanf("%d",&New->age);
    while(New->age!=0)
    {
        a++;
        if(a==1)
        {
            New->one=Head;
            End=New;
            Head=New;
        }
        else
        {
            New->one=NULL;
            End->one=New;
            End=New;
        }
        New=(struct message*)malloc(sizeof(struct message));
		printf("name:");
        scanf("%s",&New->name);
		printf("age:");
        scanf("%d",&New->age);
    }
    free(New);
    return Head;
}
void print(struct message *Head)
{
    struct message *b;
    int c=1;
    printf("liat hase %d member\n\n",a);
    b=Head;
    while(b!=NULL)
    {
        printf("NO:%d\n",c);
        printf("name:%s\n",b->name);
        printf("age:%d\n",b->age);
        b=b->one;
        c++;
    }
}
int main()
{
    struct message *Head;
    Head=two();
    print(Head);
    return 0;
}