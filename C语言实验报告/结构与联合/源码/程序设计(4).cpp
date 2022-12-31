#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct string{	//双向链表 
	char c;
	struct string *next;
	struct string *last;
};

int main(){
	struct string *head=NULL,*tail=NULL,*p,*t1,*t2;
	char s[1000];
	scanf("%s",s);
	int len=strlen(s);
	for( int i=0 ; i<len ; i++ ){
		p=(struct string *)malloc(sizeof(struct string));
		p->c=s[i];
		if( head==NULL )
			head=p;
		else{
			tail->next=p;
			p->last=tail;
		}
		tail=p;
	}
	tail->next=NULL;
	head->last=NULL;
	int flag=0;
	t1=head;t2=tail;
	for( int i=0 ; i<len/2 ; i++ ){
		if( t1->c!=t2->c )
			break;
		if( i==len/2-1 )	//判断是否到达中心位置 
			flag=1;
	}
	if(flag)
		printf("true");
	else	printf("false");
	return 0;
}
