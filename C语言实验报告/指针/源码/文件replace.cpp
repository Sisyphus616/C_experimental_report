#include<stdio.h>
#include<string.h>
// #include<stdlib.h>
int main(int argc, char *argv[]){
	FILE *op,*out=fopen("out.txt", "w+");
	char tc[50];
	char rep;
	op=fopen(argv[2],"r+");
	while(fscanf(op,"%s",tc)!=EOF){
		rep=fgetc(op);
		if(!strcmp(tc, argv[3]))
			fprintf(out,"%s%c",argv[4],rep);
        else    fprintf(out,"%s%c",tc,rep);
	}
	// rewind(op);
	rewind(out);
	while((rep=fgetc(out))!=EOF){
		putchar(rep);
	}
	// remove("out.txt");
	return 0;
}
