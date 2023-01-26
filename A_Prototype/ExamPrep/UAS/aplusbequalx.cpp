#include <stdio.h>
#include <stdlib.h>

int find_pairs(int *arr, int size, int target) {
    int count = 0;
    int i;
    int complement;
    int *complement_map = (int *) calloc(size, sizeof(int));
    for (i = 0; i < size; i++) {
        complement = target - arr[i];
        if (complement >= 0 && complement_map[complement] > 0) {
            count += complement_map[complement];
        }
        complement_map[arr[i]]++;
    }
    free(complement_map);
    return count;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int j = 1; j <= tc; j++){
        int size, target;
        scanf("%d %d", &size, &target);
        int arr[size];
        int i;
        for (i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
        int result = find_pairs(arr, size, target);
        printf("Case #%d : %d\n", j, result);
    }
    
    return 0;
}
