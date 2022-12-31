#include<stdio.h>

int main(){
	long x;
	scanf("%ld",&x);
	char *p[4];
	for( int i=0 ; i<4 ; i++ )//由高到低取出每个字节
		p[i]=(char*)&x+3-i;	//指针强制类型转换
	unsigned char mask1=0xf0,mask2=0x0f;//构造高四位/低四位逻辑尺
	for( int i=0 ; i<4 ; i++ ){
		printf("%x ",(*p[i]&mask1)>>4);//分别输出
		printf("%x ",*p[i]&mask2);
	} 
	return 0;
}
