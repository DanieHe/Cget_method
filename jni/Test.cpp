#include<stdio.h>
#include<string.h>
char str[]="tttt";
extern "C" float tt(float tt){
	printf("tt---------%f\n",tt);
	return 100.0;
}
extern "C" float get(char* buff,int* len){
	
	strcpy(buff, str);
	*len  = 10;
	printf("result=----------------------------- = %s.---%d\n",buff,*len);
}
