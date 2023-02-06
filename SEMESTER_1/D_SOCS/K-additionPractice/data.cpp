#include <stdio.h>
#include <string.h>

struct data{
    char name[100];
    int score;
};
void bubbleSort(data datas[],int size){
	for(int i=0;i<size;i++){
		for(int j=0; j < size-i-1;j++){
            if(datas[j].score > datas[j+1].score){
                data temp = datas[j];
				datas[j] = datas[j+1];
				datas[j+1] = temp; 
            }
            
			if(strcmp(datas[j].name,datas[j+1].name) > 0 && datas[j].score == datas[j + 1].score){
				data temp = datas[j];
				datas[j] = datas[j+1];
				datas[j+1] = temp; 
			}
		}
	}
};
int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int num;
        scanf("%d", &num); getchar();
        data datas[num];
        for(int j = 0; j < num; j++){
            scanf("%[^#]#%d", datas[j].name, &datas[j].score); getchar();
        }
        printf("Case #%d:\n", i + 1);
        bubbleSort(datas, num);
        for(int j = 0; j < num; j++){
            printf("%s - %d\n", datas[j].name, datas[j].score);
        }
    }

    return 0;
}