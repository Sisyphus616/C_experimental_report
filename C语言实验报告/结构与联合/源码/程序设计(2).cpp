#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{	//存放学生信息 
	char id[20];
	char name[20];
	int score[5];
	float aver;
	struct student *next;
};
int n;
struct student *head=NULL,*tail=NULL,*p,*t;
void Input(){	//输入原信息 
	scanf("%d",&n);
	for( int i=0 ; i<n ; i++ ){	//部署链表 
		p=(struct student*)malloc(sizeof(struct student));
		scanf("%s %s %d",p->id,p->name,&p->score[0]);
		scanf("%d %d %d",&p->score[1],&p->score[2],&p->score[3]);
		if( head==NULL )
			head=p;
		else	tail->next=p;
		tail=p;
	}
	tail->next=NULL;
}
void Output(){	//输出原信息 
	t=head;
	while(t){
		printf("%s %s %d ",t->id,t->name,t->score[0]);
		printf("%d %d %d\n",t->score[1],t->score[2],t->score[3]);
		t=t->next;
	}
}
void Change(){
	t=head;
	char re[20];
	int flag,newscore;
	scanf("%s",re);
	while(t){
		if( strcmp(re,t->id)==0 ){
			scanf("%d %d",&flag,&newscore);
			t->score[flag-1]=newscore;
			break;
		}
		t=t->next;
	}
}
void Ave(int cmp){	//参数表示是否输出平均成绩 
	int sum=0;
	float ave;
	t=head;
	while(t){
		sum=0;
		for( int i=0 ; i<4 ; i++ )
			sum+=t->score[i];
		ave=sum*1.0/4;
		t->score[4]=sum;
		t->aver=ave;
		if( cmp )
			printf("%s %s %.2f\n",t->id,t->name,t->aver);
		t=t->next; 
	}
}
void Out2(){	//输出总成绩与平均成绩 
	t=head;
	while(t){
		printf("%s %s %d %.2f\n",t->id,t->name,t->score[4],t->aver);
		t=t->next;
	}
}
void sort(){
	t=head;
	struct student order[20];//存储数组 
	int cnt=0;
	while(t){
		order[cnt++]=*t;
		t=t->next;
	}
	for( int i=cnt-1 ; i>0 ; i-- )//冒泡排序 
        for( int j=0 ; j<i ; j++ )
            if( order[j].score[4]>order[j+1].score[4] ){
                struct student temp=order[j];
                order[j]=order[j+1];
                order[j+1]=temp;
            }
    head=NULL;	//构建新链表 
    for( int i=0 ; i<cnt ; i++ ){
    	p=(struct student*)malloc(sizeof(struct student));
    	*p=order[i];
    	if(head==NULL)
    		head=p;
    	else	tail->next=p;
    	tail=p;
	}
	tail->next=NULL;
} 
int main(){
	int menu;
	scanf("%d",&menu);
	while( menu!=0 ){ 
		switch (menu){	//部署菜单 
			case 1:Input();break;
			case 2:Ave(0);sort();Output();break;
			case 3:Change();break;
			case 4:Ave(0);sort();Ave(1);break;
			case 5:Ave(0);sort();Out2();break;
		}
		scanf("%d",&menu);
	}
	return 0;
}
