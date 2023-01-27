#include <stdio.h>
#include <string.h>

struct data {
    int vocount;
    char string[101];
};

int vocounting(struct data a){
    int count = 0;
    for(int i = 0; i < strlen(a.string); i++){
        if(a.string[i] == 'a' || a.string[i] == 'i' || a.string[i] == 'u' || a.string[i] == 'e' || a.string[i] == 'o') count++;
    }
    return count;
}

void swap(struct data *a, struct data *b){
    struct data temp = *a;
    *a = *b;
    *b = temp;
}

void bubleSort(struct data datas[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(datas[j].vocount > datas[j + 1].vocount){
                swap(&datas[j], &datas[j + 1]);
            } else if(datas[j].vocount == datas[j + 1].vocount && strcmp(datas[j].string, datas[j + 1].string) > 0) {
                swap(&datas[j], &datas[j + 1]);
            }
        }
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);
    struct data datas[n];
    for (int i = 0; i < n; i++){
        scanf("%s", datas[i].string);
        datas[i].vocount = vocounting(datas[i]);
    }
    bubleSort(datas, n);
    for(int i = 0; i < n; i++){
        printf("%s\n", datas[i].string);
    }
    

    return 0;
}