#include<stdio.h>

int RemoveSame(int a[],int n){//�������� 
	int i,j;
	for( i=1,j=0 ; i<=n ; i++,j++ ){
		while(i+1<=n&&a[i+1]==a[i])
			i++;
		a[j]=a[i];
	}
	return j;	//�����³��� 
}

int main(){
	int nums[1000];//�洢����
	int n;
	scanf("%d",&n);
	for( int i=1 ; i<=n ; i++ )
		scanf("%d",&nums[i]);
	int len=RemoveSame(nums,n);//��������
	for( int i=0 ; i<len ; i++ ){
		printf("%d",nums[i]);
        if( i!=len-1 )
            printf(" ");
    }
	printf("\n%d",len);
	return 0;
}
