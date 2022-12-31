#include<stdio.h>
#include<string.h>

int delSubstr( char *str,char *substr){
	int lens=strlen(str),lenss=strlen(substr);
	int cnt=0;		//判断子串个数 
	char *pos=str;
	while( (pos=strstr(pos,substr)) ){
		cnt++;
		strcpy(pos,pos+lenss);//子串后的字符串复制过来
	}
	return cnt;
}

int main(){
	char str[100],substr[100];
	gets(str);		//读入两行字符串 
    gets(substr);
	int cmp=delSubstr(str,substr);
	printf("%s\n",str);
    if( cmp )	//判断是否执行删除子串功能 
		printf("1");
	else printf("0");
	return 0;
} 
