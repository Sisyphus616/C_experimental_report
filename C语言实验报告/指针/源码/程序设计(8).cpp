#include<stdio.h>
#include<string.h>

int delSubstr( char *str,char *substr){
	int lens=strlen(str),lenss=strlen(substr);
	int cnt=0;		//�ж��Ӵ����� 
	char *pos=str;
	while( (pos=strstr(pos,substr)) ){
		cnt++;
		strcpy(pos,pos+lenss);//�Ӵ�����ַ������ƹ���
	}
	return cnt;
}

int main(){
	char str[100],substr[100];
	gets(str);		//���������ַ��� 
    gets(substr);
	int cmp=delSubstr(str,substr);
	printf("%s\n",str);
    if( cmp )	//�ж��Ƿ�ִ��ɾ���Ӵ����� 
		printf("1");
	else printf("0");
	return 0;
} 
