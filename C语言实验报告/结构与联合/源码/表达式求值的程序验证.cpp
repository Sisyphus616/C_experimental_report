#include<stdio.h>

char u[]="UVWXYZ",v[]="xyz";
struct T{
	int x;
	char c;
	char *t;
}a[]={{11,'A',u},{100,'B',v}},*p=a;

int main(){
	int n;
	scanf("%d",&n);
	switch (n){
		case 1:printf("%d\n",((++p)->x));break;
		case 2:printf("%c\n",(p++,p->c));break;
		case 3:printf("%c\n",(*p++->t,*p->t));break;
		case 4:printf("%c\n",*(++p)->t);break;
		case 5:printf("%c\n",*++p->t);break;
		case 6:printf("%c\n",++*p->t);break;
	}
	return 0;
}
