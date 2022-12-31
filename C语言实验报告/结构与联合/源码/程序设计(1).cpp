#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bit{
	char a;
	unsigned char bit0:1;
	unsigned char bit1:1;
	unsigned char bit2:1;
	unsigned char bit3:1;
	unsigned char bit4:1;
	unsigned char bit5:1;
	unsigned char bit6:1;
	unsigned char bit7:1;
}flags; 

void f0(int b){
	printf("the function %d is called!\n",b);
}
void f1(int b){
	printf("the function %d is called!\n",b);
}
void f2(int b){
	printf("the function %d is called!\n",b);
}
void f3(int b){
	printf("the function %d is called!\n",b);
}
void f4(int b){
	printf("the function %d is called!\n",b);
}
void f5(int b){
	printf("the function %d is called!\n",b);
}
void f6(int b){
	printf("the function %d is called!\n",b);
}
void f7(int b){
	printf("the function %d is called!\n",b);
}

int main(){
	char s[10];
	scanf("%d",&flags.a);
	itoa(flags.a,s,2);
	void (*p[8])(int b)={f0,f1,f2,f3,f4,f5,f6,f7};
	int m=strlen(s),t=8-m;
	for( int i=7 ; i>=t ; i-- )
		if( s[i-t]=='1' )
			p[m-1-i+t](m-1-i+t);
	return 0;
}
