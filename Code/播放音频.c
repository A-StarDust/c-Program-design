#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
int main()
{ 
	
	int a;
	scanf("%d",&a);
	if(a=1)
		sndPlaySound(TEXT("C:\\Users\\Administrator\\Desktop\\01\\1.wav"),NULL,SND_FILENAME |SND_ASYNC);
	else if(a=2)
		sndPlaySound(TEXT("C:\\Users\\Administrator\\Desktop\\01\\2.wav"),NULL,SND_FILENAME | SND_ASYNC);
	return a;

}