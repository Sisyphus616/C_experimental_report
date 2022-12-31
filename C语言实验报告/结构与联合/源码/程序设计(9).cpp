#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int num;
	struct data *last;
	struct data *next;
};

int main(){
	char s[200];
	gets(s);
	struct data *head=NULL,*tail=NULL,*p;
	for( int i=0 ; s[i]!='\0'&&s[i]!='\n' ; i++ ){
		char numa[5];
		if( (s[i]>='0'&&s[i]<='9')||(s[i]=='-'&&s[i+1]>='0'&&s[i+1]<='9') ){
			int j=0;
			while(s[i]!=' ')
				numa[j++]=s[i++];
			numa[j]='\0';
			p=(struct data *)malloc(sizeof(struct data));
			p->num=atoi(numa);
			if( head==NULL )
				head=p;
			else{
				tail->next=p;
				p->last=tail;
			}
			tail=p;
		}
		else if(s[i]==' ')	continue;
		else{
			int numx[2],result;
			numx[1]=tail->num;
			tail=tail->last;
			numx[0]=tail->num;
			switch (s[i]){
				case '+':result=numx[0]+numx[1];break;
				case '-':result=numx[0]-numx[1];break;
				case '*':result=numx[0]*numx[1];break;
				case '/':result=numx[0]/numx[1];break;
			}
			tail->num=result;
		}
	}
	printf("%d",tail->num);
	return 0;
}
