#include<stdio.h>

int main(){
	long x;
	scanf("%ld",&x);
	char *p[4];
	for( int i=0 ; i<4 ; i++ )//�ɸߵ���ȡ��ÿ���ֽ�
		p[i]=(char*)&x+3-i;	//ָ��ǿ������ת��
	unsigned char mask1=0xf0,mask2=0x0f;//�������λ/����λ�߼���
	for( int i=0 ; i<4 ; i++ ){
		printf("%x ",(*p[i]&mask1)>>4);//�ֱ����
		printf("%x ",*p[i]&mask2);
	} 
	return 0;
}
