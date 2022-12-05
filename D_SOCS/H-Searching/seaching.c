#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binarySearch(long int arr[], long int x, int low, int high){
    if (low > high)
        return -1;

    else{
        int mid = (low + high) / 2;
        if(x == arr[mid])
            return mid;

        else if(x > arr[mid])        // x is on the right side
            return binarySearch(arr, x, mid + 1, high);
        
        else                        // x is on the left side
            return binarySearch(arr, x, low, mid - 1);
    }
    return -1;
}

int main(){

    FILE *fp;
    fp = fopen("testdata.in", "r");

    int datacount;
    fscanf(fp, "%d\n", &datacount);
    long int studentID[100];
    char *studentName[100];
    for(int i = 0; i < datacount; i++){
        char SITemp[100], SNTemp[100];
        fscanf(fp, "%ld %s\n", &studentID[i], SNTemp);
        studentName[i] = malloc(strlen(SNTemp)*sizeof(char));
        strcpy(studentName[i], SNTemp);
    }

    int testcases;
    fscanf(fp, "%d\n", &testcases);
    for(int i = 0; i < testcases; i++){
        long int NIM;
        fscanf(fp, "%ld\n", &NIM);
        int res = binarySearch(studentID, NIM, 0, datacount);
        if(res < 0){
            printf("Case #%d: N/A\n", i + 1);
        } else printf("Case #%d: %s\n", i + 1, studentName[res]);
    }
    fclose(fp);

    return 0;
}