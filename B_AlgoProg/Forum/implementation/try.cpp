#include <stdio.h>
#include <string.h>

struct data {
    char value[20];
};

void swap(data *a, data *b){
    data t = *a;
    *a = *b;
    *b = t;
}
  

int partition(data arr[], int low, int high)
{
    data pivot = arr[high]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
   
        if (strcmp(arr[j].value, pivot.value) < 0) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  

void quickSort(data arr[], int low, int high)
{
    if (low < high) {
  
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
/* Function to print an array */
void printArray(data arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%s ", arr[i].value);
    puts("");
}
  
int interpolationSearch(data arr[], int n, char x[]) {
    int lo = 0;
    int hi = (n - 1);

    while (lo <= hi && strcmp(x, arr[lo].value) >= 0 && strcmp(x, arr[hi].value) <= 0) {
        int pos = lo + (((double)(hi-lo) / (strcmp(arr[hi].value,arr[lo].value)))*(strcmp(x, arr[lo].value)));

        if (strcmp(arr[pos].value,x) == 0)
            return pos;

        if (strcmp(arr[pos].value,x) < 0)
            lo = pos + 1;

        else
            hi = pos - 1;
    }
    return -1;
}
  
// Driver Code
int main()
{
    int size = 3;
    data arr[3] = {{"bbb"},{"aaa"},{"ccc"}};
    quickSort(arr, 0, size - 1);
    printf("Sorted array: \n");
    printArray(arr, size);
    int result = interpolationSearch(arr, size, "aaa");
    printf("%d\n", result);
    return 0;
}
  
