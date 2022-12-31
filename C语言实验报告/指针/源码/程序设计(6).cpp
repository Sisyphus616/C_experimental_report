#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

int *num;//全局变量数组

void mysort(int a[],int size,int cmp){
	if( cmp==1 ){		//正序排序 
		for( int i=size-1 ; i>0 ; i-- )
        	for( int j=0 ; j<i ; j++ )
            	if( a[j]>a[j+1] ){
                	int t=a[j];
                	a[j]=a[j+1];
                	a[j+1]=t;
            	}
	}
    else{				//倒序排序 
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

int main(int argc, char *argv[]){//main函数参数 
	int n=atoi(argv[2]);//字符串变量转化为整型 
	int cmp;
	if( argc==3 )
		cmp=1;
	else	cmp=0;
	num=(int*)malloc(sizeof(int)*n);//动态分配空间 
	for( int i=0 ; i<n ; i++ )
		scanf("%d",&num[i]);
	mysort(num,n,cmp);
	for( int i=0 ; i<n ; i++ ){
		printf("%d",num[i]);
		if( i!=n-1 )
			printf(" ");
	}
	/******************Debug代码*****************/ 
//	printf("%d",n);
//	printf("%d\n",argc);
//	for( int i=0 ; i<argc ; i++ )
//		printf("%s\n",argv[i]);
	/********************************************/
	return 0;
}
