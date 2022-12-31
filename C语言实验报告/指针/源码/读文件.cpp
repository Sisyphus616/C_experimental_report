#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	// 请在此处编辑您的代码
	/********** Begin **********/
    FILE *fp;
    char cmd[20],cho[20],name[20];
    scanf("%s %s",cmd,cho);
    if( strlen(cmd)<5 )
        printf("指令错误");
    else{
        fp=fopen("F:\\写写程序\\C\\sum_fac.cpp","r");
        char c;
        int line=1;
        printf("1  ");
        while((c=fgetc(fp))!=EOF){
            putchar(c);
            if( c=='\n' )
                printf("%d  ",++line);
        }
        fclose(fp);
    }
	/********** End **********/
	return 0; 
}
