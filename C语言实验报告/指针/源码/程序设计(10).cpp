#include<stdio.h>
#include<math.h>

int main(){
	int a[201][402],b[201]={0};
	int lena=0,lenb=0,x;
	for( int i=0 ; i<201 ; i++ )
        for( int j=0 ; j<402 ; j++ )
            a[i][j]=0;		//��ʼ��a 
	char c;
	while( (c=getchar())!='\n'&&c!=EOF )//���벢����λ�� 
		a[0][lena++]=c-'0';
	while( (c=getchar())!=EOF&&c!='\n' )
		b[lenb++]=c-'0';
	for( int i=0 ; i<lena-i-1 ; i++ )//��ת����a��b 
	{int t=a[0][i];a[0][i]=a[0][lena-i-1];a[0][lena-i-1]=t;}
	for( int i=0 ; i<lenb-i-1 ; i++ )
	{int t=b[i];b[i]=b[lenb-i-1];b[lenb-i-1]=t;}
	x=0;
	for( int j=1 ; j<201 ; j++ )
        for( int k=0 ; k<201 ; k++ ){
            int t=(a[0][k]*b[j-1]+x);//��λ�˷���ʽ 
            a[j][k+j-1]=t%10;//a[j]Ϊ�˷���ʽ�ĵ�j��
            x=t/10;
        }
    x=0;
    for( int j=0 ; j<402 ; j++ ){	//a[1],a[2]��λ�߾������
        int t=x;
        for( int i=1 ; i<201 ; i++ )
        	t+=a[i][j];
        a[0][j]=t%10;
        x=t/10;
    }
    for( int j=401 ; j>=0 ; j-- ){//����aλ�� 
        if( a[0][j]==0 )
            continue;
        lena=j;
        break;
    }
    for( int i=lena ; i>=0 ; i-- )//�Ӹ�λ����λ��� 
		printf("%d",a[0][i]);
	return 0;
}
