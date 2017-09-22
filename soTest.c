#include<stdio.h>
#include<dlfcn.h>
int main(){
printf("test begin\n");
void * libm_handle = NULL;
float (*cosf_method)(float);
float (*get_method)(unsigned char*,int*);
char *errorInfo;
float result;
char *str="ff";
int count = atoi(str);
int tt[31];

printf("count = %d\n",count);
printf("count = %d\n",strlen(tt));
printf("count = %d\n",sizeof(tt)/sizeof(tt[0]));
libm_handle = dlopen("./jni/libTest.so",RTLD_LAZY);
	if(!libm_handle){
		printf("Open Error:%s.\n",dlerror());
		return 0;
	}
	cosf_method = dlsym(libm_handle,"tt");
	get_method = dlsym(libm_handle,"get");
	errorInfo = dlerror();
	if(errorInfo != NULL){
		printf("Dlsym Error:%s.\n",errorInfo);
		return 0;
	}
	if(cosf_method==NULL){
		printf("Dlsym Error:cosf_method=NULL.\n");
		return 0;
	}
	if(get_method==NULL){
		printf("Dlsym Error:get_method=NULL.\n");
		return 0;
	}
	result = (*cosf_method)(0.0);

	char a[200];
	int i;
	(*get_method)(a,&i);

	printf("result = %f.--%d---%s\n",result,strlen(a),a);
	dlclose(libm_handle);
	return 0;
}
