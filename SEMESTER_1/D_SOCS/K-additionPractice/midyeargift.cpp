#include<stdio.h>

struct data{
	char string[200];
	int num; 
};

int main(){
	struct data datas[2005];
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%s %d",&datas[i].string,&datas[i].num);
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<t-1;j++){
			if(datas[j].num > datas[j+1].num){
				data temp = datas[j];
				datas[j] = datas[j+1];
				datas[j+1] = temp;
			}
		}
	}
	for(int i=0;i<t;i++){
		printf("Lecturer #%d: %s\n",i+1,datas[i].string);
	}
	return 0;
}