
#include<stdio.h>
#include<conio.h>
#include<pthread.h>
#include<time.h>

#define HIGHT 16
#define WIDE 15
#define SNAKESIZE (HIGHT-2)*(WIDE-2)-2

int map[HIGHT][WIDE];

int Long=3,Game=0,Eat=0,fx=5,fy=10;
int Direction=4;

struct Body
{
    int x;
    int y;
} Body[SNAKESIZE];

int print(int a[HIGHT][WIDE])
{
    int i,j;
    printf("%d分\n",Eat);
    for(i=0; i<HIGHT; i++)
    {
        for(j=0; j<WIDE; j++)
        {
            switch(a[i][j])
            {
            case 0:
                printf("🛣🛤");
                break;
            case 1:
                printf("😶");
                break;
            case 2:
                printf("🍎");
                break;
            case 3:
                printf("😃");
                break;
            case 4:
                printf("●");
                break;
            case 5:
                printf("◆");
                break;
            }
        }
        printf("\n");
    }
}

int maps(int a[HIGHT][WIDE],int model)
{
    int i,j;
    if(model==1)
    {
        for(i=0; i<HIGHT; i++)
        {
            for(j=0; j<WIDE; j++)
            {
                a[i][j]=0;
                /*a[i][0]=a[0][j]=1;
                a[i][WIDE-1]=a[HIGHT-1][j]=1;
                */
            }
        }
    }
    food(map);
    //else;
}

int begin(int a[HIGHT][WIDE],int model)
{
    int i,j;
    if(model==1)
    {
        a[HIGHT/2][WIDE/2]=a[HIGHT/2][WIDE/2-1]=2;
        a[HIGHT/2][WIDE/2-2]=2;
        Direction=4;
        Body[0].x=Body[1].x=Body[2].x=HIGHT/2;
        Body[0].y=WIDE/2;
    }
}

int move(int a[HIGHT][WIDE],int model)
{
    int i,j,k=Long-1,v;
    switch(Direction)
    {

    case 1:
    {
        if(Body[0].x==0)
            Body[0].x=HIGHT;
            Body[0].x--;
    }
    break;
    case 2:
    {
        if(Body[0].x==HIGHT-1)
            Body[0].x=-1;
            Body[0].x++;
    }
    break;
    case 3:
    {
        if(Body[0].y==0)
            Body[0].y=WIDE;
            Body[0].y--;
    }
    break;
    case 4:
    {
        if(Body[0].y==WIDE-1)
            Body[0].y=-1;
            Body[0].y++;
    }
    break;
    }
    for(; k>0; k--)
    {
        Body[k].x=Body[k-1].x;
        Body[k].y=Body[k-1].y;
    }
    maps(map,model);
    for(v=Long-1; v>=0; v--)
    {
        if(a[Body[v].x][Body[v].y]==2)
        {
            Long++;
            a[Body[v].x][Body[v].y]=1;
            a[Body[0].x][Body[0].y]=3;
        }
        a[Body[v].x][Body[v].y]=1;
    }
    food(map);

}

int food(int a[HIGHT][WIDE])
{
    int i,j,n=0,x,y;
    if(Eat+3!=Long)
    {
        while(1)
        {
            fx=rand()%HIGHT-1;
            fy=rand()%WIDE-1;
            if(a[fx][fy]!=1||a[fx][fy]!=2)
            {
                a[fx][fy]=2;
                Eat++;
                break;

            }
        }
    }
    else
    {
        a[fx][fy]=2;
        return;
    }
}

int judge(int a[HIGHT][WIDE])
{
    switch(Direction)
    {
    case 1:
    {
        if(a[Body[0].x-1][Body[0].y]==1)
            Game=1;
        else if(a[Body[0].x-1][Body[0].y]==2)
            Long++;
    }
    break;
    case 2:
    {
        if(a[Body[0].x+1][Body[0].y]==1)
            Game=1;
        else if(a[Body[0].x+1][Body[0].y]==2)
            Long++;
    }
    break;
    case 3:
    {
        if(a[Body[0].x][Body[0].y-1]==1)
            Game=1;
        else if(a[Body[0].x][Body[0].y-1]==2)
            Long++;
    }
    break;
    case 4:
    {
        if(a[Body[0].x][Body[0].y+1]==1)
            Game=1;
        else if(a[Body[0].x][Body[0].y+1]==2)
            Long++;
    }
    break;
    }
}

void* play(void* th)
{
    for(; Game==0;)
    {
        switch(getch())
        {
        case '2':
        {
            if(Direction!=2)
                Direction=1;
        }
        break;
        case '8':
        {
            if(Direction!=1)
                Direction=2;
        }
        break;
        case '4':
        {
            if(Direction!=4)
                Direction=3;
        }
        break;
        case '6':
        {
            if(Direction!=3)
                Direction=4;
        }
        break;

        }
    }
}
int main()
{
    //for(;;)
    {
    int model=1,speed=200000,Frame=0;
    maps(map,model);
    begin(map,model);
    Direction=4;
    pthread_t th;
    pthread_create(&th,NULL,play,NULL);
    while(Game==0)
    {
        move(map,model);
        judge(map);
        Frame++;
        clrscr();
        print(map);
        usleep(speed);
    }
    printf("game over");
    Game=0;
    Long=3;
    Eat=0;
    Direction=4;
    getch();
    }
    return 0;
}