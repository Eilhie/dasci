#include <stdio.h>

int main() {
    FILE *fp = fopen("testdata.in", "r");
    int len; 
    fscanf(fp, "%d\n", &len);
    int arr[len];
    int freq[1000] = {0};
    for(int i = 0; i < len; i++){
        fscanf(fp, "%d", &arr[i]);
        freq[arr[i]]++;
    }
    int max = 0;
    for(int i = 0; i < 1000; i++){
        if(freq[i] > max) max = freq[i];
    }

    for(int i = 0; i < 1000; i++){
        if(freq[i] == max){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
