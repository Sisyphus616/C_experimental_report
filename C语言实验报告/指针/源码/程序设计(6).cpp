#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

int *num;//ȫ�ֱ�������

void mysort(int a[],int size,int cmp){
	if( cmp==1 ){		//�������� 
		for( int i=size-1 ; i>0 ; i-- )
        	for( int j=0 ; j<i ; j++ )
            	if( a[j]>a[j+1] ){
                	int t=a[j];
                	a[j]=a[j+1];
                	a[j+1]=t;
            	}
	}
    else{				//�������� 
    	for( int i=0 ; i<size ; i++ )
        	for( int j=size-1 ; j>i ; j-- )
            	if( a[j]>a[j-1] ){
                	int t=a[j];
                	a[j]=a[j-1];
                	a[j-1]=t;
            	}
	}
    return ;
}

int main(int argc, char *argv[]){//main�������� 
	int n=atoi(argv[2]);//�ַ�������ת��Ϊ���� 
	int cmp;
	if( argc==3 )
		cmp=1;
	else	cmp=0;
	num=(int*)malloc(sizeof(int)*n);//��̬����ռ� 
	for( int i=0 ; i<n ; i++ )
		scanf("%d",&num[i]);
	mysort(num,n,cmp);
	for( int i=0 ; i<n ; i++ ){
		printf("%d",num[i]);
		if( i!=n-1 )
			printf(" ");
	}
	/******************Debug����*****************/ 
//	printf("%d",n);
//	printf("%d\n",argc);
//	for( int i=0 ; i<argc ; i++ )
//		printf("%s\n",argv[i]);
	/********************************************/
	return 0;
}
