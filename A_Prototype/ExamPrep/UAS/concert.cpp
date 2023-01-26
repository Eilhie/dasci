#include <stdio.h>

void best_split(int arr[], int n, int num_workers, int split_arr[][4]) {
    int best_split_start = 0;
    int best_split_end = n - 1;
    int best_split_length = n;
    int split_index = 0;
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {
            int curr_split_length = (j - i + 1);
            if(curr_split_length % num_workers == 0) {
                if(curr_split_length < best_split_length) {
                    best_split_start = i;
                    best_split_end = j;
                    best_split_length = curr_split_length;
                }
            }
        }
    }
    int k;
    for(k = best_split_start; k <= best_split_end; k += best_split_length/num_workers) {
        int l;
        for(l = k; l < k + best_split_length/num_workers; l++) {
            split_arr[split_index][l - k] = arr[l];
        }
        split_index++;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num_workers = 4;
    int split_arr[num_workers][4];
    best_split(arr, n, num_workers, split_arr);

    int i, j;
    for(i = 0; i < num_workers; i++) {
        printf("Worker %d: [", i + 1);
        for(j = 0; j < n; j++) {
            if(split_arr[i][j] != 0) {
                printf("%d ", split_arr[i][j]);
            }
        }
        printf("]\n");
    }
    return 0;
}
