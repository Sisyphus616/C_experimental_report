#include <stdio.h>
#include <stdlib.h>
struct s_list{
    int data;
    struct s_list *next;
    struct s_list *last;//结构体新增内容，指向上一结点 
};
void create_list(struct s_list **headp,int *p);
int main(void){
    struct s_list *head=NULL,*p;
    int s[]={1,2,3,4,5,6,7,8,0};
    create_list(&head,s);
    p=head;
    while (p){
        printf("%d\t",p->data);
        p=p->last;
    }
    printf("\n");
    return 0;  
}
void create_list(struct s_list **headp,int *p){
    struct s_list *loc_head=NULL,*tail,*temp;//声明临时结构指针变量temp 
    if(p[0]==0);
    else {
        loc_head=(struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data=*p++;
        tail=loc_head;
        while (*p)
        {
            tail->next=(struct s_list *)malloc(sizeof(struct s_list));
            temp=tail;//temp暂时存放上一个结点 
            tail=tail->next;
            tail->last=temp;//新节点的last指向上一节点 
            tail->data=*p++;
        }
        loc_head->last=NULL;//先建结点的上一个结点为NULL 
    }
    *headp=tail;
}
