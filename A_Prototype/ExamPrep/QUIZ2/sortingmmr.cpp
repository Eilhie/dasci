#include <stdio.h>

struct mmr {
    char name[20];
    int mmrvalue;
};

void swap(mmr *a, mmr *b){
    mmr t = *a;
    *a = *b;
    *b = t;
}

int partition(mmr data[], int low, int high){
    mmr pivot = data[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(data[j].mmrvalue > pivot.mmrvalue){
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[high], &data[i + 1]);
    return (i + 1);
}

void quickSort(mmr data[], int low, int high){
    if(low <= high){
        int pi = partition(data, low, high);
        quickSort(data, pi + 1, high);
        quickSort(data, low, pi - 1);
    }
}

int main(){
    int n;
    mmr data[100000];
    scanf("%d", &n); getchar();
    for(int i = 0; i < n; i++){
        scanf("%s %d", data[i].name, &data[i].mmrvalue); getchar();
    }
    quickSort(data, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%s %d\n", data[i].name, data[i].mmrvalue);
    }
    
    return 0;
}