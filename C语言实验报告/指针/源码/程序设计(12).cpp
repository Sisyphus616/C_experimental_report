#include<stdio.h>
#include<string.h>

/****************任务函数****************/
void task0(){
	printf("task0 is called!\n");
	return ;
}
void task1(){
	printf("task1 is called!\n");
	return ;
}
void task2(){
	printf("task2 is called!\n");
	return ;
}
void task3(){
	printf("task3 is called!\n");
	return ;
}
void task4(){
	printf("task4 is called!\n");
	return ;
}
void task5(){
	printf("task5 is called!\n");
	return ;
}
void task6(){
	printf("task6 is called!\n");
	return ;
}
void task7(){
	printf("task7 is called!\n");
	return ;
}
/******************end*******************/ 
void execute( int num , void(*p[])() ){
	for( int i=0 ; i<num ; i++ )
		p[i]();
	return ;
}
void scheduler(){
	char exe[100];
	scanf("%s",exe);
	int num=strlen(exe);//快速获得num 
	void(*func[100])();
	void(*func_ori[8])()={task0,task1,task2, 
	task3,task4,task5,task6,task7};//函数表 
	for( int i=0 ; i<num ; i++ )
		func[i]=func_ori[exe[i]-'0'];
	execute(num,func);
	return ;
}
int main(){
	scheduler();
	return 0;
}
