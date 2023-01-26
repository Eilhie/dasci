#include <stdio.h>

void bublesort(int arr[], int size) {
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    FILE *fp = fopen("testdata.in", "r");
    int tc;
    fscanf(fp, "%d\n", &tc);
    for(int i = 1; i <= tc; i++){
        int x,y;
        fscanf(fp, "%d %d\n", &y, &x);
        int find[y*x];
        for(int j = 0; j < y*x; j++){
            fscanf(fp, "%d", &find[j]);
        }
        
        bublesort(find, x*y);
        if(x*y % 2 == 0)
            printf("Case #%d: %d\n", i, (find[((x*y) / 2)] + find[((x*y) / 2) + 1]) / 2);
        else
            printf("Case #%d: %d\n", i, (find[((x*y) / 2)]));
    }
    
}