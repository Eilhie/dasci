#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct housing{
    char loc1[100];
    char loc2[100];
    long long int price;
    int rooms;
    int bathrooms;
    int carparks;
    char type[100];
    long long int area;
    char furnish[100];
};

void readFile(housing datas[], int &size);
void printFile(housing datas[], int size);
void swap(housing *a, housing *b);
int partition(housing arr[], int low, int high);
void quickSort(housing arr[], int low, int high);

int main(){
    housing datas[5000];
    int size = 0;
    readFile(datas, size);
   
    quickSort(datas, 0, size);

   printFile(datas, size);
}

void readFile(housing datas[], int &size){
    FILE *fp = fopen("fileAol.csv", "r");
    char buffer[1000];
    fscanf(fp, "%[^\n]\n", buffer);
    // printf("%s\n", buffer);
    while(!feof(fp)){
       fscanf(fp, "%[^,],%[^,],%lld,%d,%d,%d,%[^,],%lld,%[^\n]\n", datas[size].loc1, datas[size].loc2, &datas[size].price, &datas[size].rooms, &datas[size].bathrooms, &datas[size].carparks, datas[size].type, &datas[size].area, datas[size].furnish);
       size += 1;
    }
}

void printFile(housing datas[], int size){
    for(int i = 0; i < size; i++){
        
       printf("%s,%s,%lld,%d,%d,%d,%s,%lld,%s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
       
    }   
}


void swap(housing *a, housing *b){
    housing t = *a;
    *a = *b;
    *b = t; 
}

int partition(housing arr[], int low, int high){
    housing pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high-1; j++){
        if(strcmp(arr[j].loc1, pivot.loc1) < 0){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[high], &arr[i + 1]);
    return i + 1;
}

void quickSort(housing arr[], int low, int high){
    if(low <= high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
