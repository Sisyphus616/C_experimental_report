#include<stdio.h>

int a[100][100],ans[100][100];	//����ȫ�ֱ������������������� 
void reverse(int n,int m,int (*pa)[100],int (*pans)[100]){
	int i,j;
	for( j=m-1 ; j>=0 ; j-- )
		for( i=0 ; i<n ; i++ )
			*(*(pans+m-1-j)+i)=*(*(a+i)+j);	//����ָ����� 
	return ;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;		//ѭ���������� 
	for( i=0 ; i<n ; i++ )
		for( j=0 ; j<m ; j++ )
			scanf("%d",&a[i][j]);
	int (*pa)[100]=a,(*pans)[100]=ans;	//�������ָ�� 
	reverse(n,m,pa,pans);
	for( i=0 ; i<m ; i++ )
		for( j=0 ; j<n ; j++ ){
			printf("%d",ans[i][j]);
			if( j!=n-1 )
				printf(" ");
			else if( i!=m-1 )
				printf("\n");
		}
	return 0;
}
