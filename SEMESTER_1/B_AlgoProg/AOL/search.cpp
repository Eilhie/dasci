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
int partition(housing arr[], int low, int high, int order);
void quickSort(housing arr[], int low, int high, int order);
void search(housing datas[], int size, int order, char *search);

int main(){
    housing datas[5000];
    int size = 0;
    readFile(datas, size);
    // printFile(datas, size);
    int run = 1;
    char word[100];

    do{
        puts("use 0 infront of number ex(01)");
        printf(" search : "); getchar();
        scanf("%[^\n]", word); getchar();
        const char delimiter[] = " ";

        char *token = strtok(word, delimiter);
        char *tokens[10];
        int i = 0;

        while (token != NULL) {
            tokens[i] = token;
            i++;
            token = strtok(NULL, delimiter);
        }
        if (strcmp(tokens[2], "loc1") == 0){
            search(datas, size, 1, tokens[0]);
        } else if (strcmp(tokens[2], "loc2") == 0) {
            search(datas, size, 2, tokens[0]);
        } else if (strcmp(tokens[2], "rooms") == 0) {
            search(datas, size, 3, tokens[0]);
        } else if (strcmp(tokens[2], "bathrooms") == 0) {
            search(datas, size, 4, tokens[0]);
        } else if (strcmp(tokens[2], "carparks") == 0) {
            search(datas, size, 5, tokens[0]);
        } else if (strcmp(tokens[2], "type") == 0) {
            search(datas, size, 6, tokens[0]);
        } else if (strcmp(tokens[2], "furnish") == 0) {
            search(datas, size, 7, tokens[0]);
        } else {
            printf("no column after %s\n", tokens[0]);
            run = 0;
        }
    } while(run);
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

void search(housing datas[], int size, int order, char *search){
    if(order == 1){
        quickSort(datas, 0, size, order);
        for(int i = 0; i < size; i++){
            if(strstr(datas[i].loc1, search) != NULL){
                printf("%s  | %s    | %lld | %d | %d | %d | %s | %lld | %s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
            }
        }
        return;
    } else if(order == 2){
        quickSort(datas, 0, size, order);
        for(int i = 0; i < size; i++){
            if(strstr(datas[i].loc2, search) != NULL){
                printf("%s  | %s    | %lld | %d | %d | %d | %s | %lld | %s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
            }
        }
        return;
    } else if(order == 3){
        quickSort(datas, 0, size, order);
        int number = atoi(search);
        printf("%d\n", number);
        for(int i = 0; i < size; i++){
            if(datas[i].rooms == number){
                printf("%s  | %s    | %lld | %d | %d | %d | %s | %lld | %s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
            }
        }
        return;
    } else if(order == 4){
        quickSort(datas, 0, size, order);
        int number = atoi(search);
        printf("%d\n", number);
        for(int i = 0; i < size; i++){
            if(datas[i].bathrooms == number){
                printf("%s  | %s    | %lld | %d | %d | %d | %s | %lld | %s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
            }
        }
        return;
    } else if(order == 3){
        quickSort(datas, 0, size, order);
        int number = atoi(search);
        printf("%d\n", number);
        for(int i = 0; i < size; i++){
            if(datas[i].carparks == number){
                printf("%s  | %s    | %lld | %d | %d | %d | %s | %lld | %s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
            }
        }
        return;
    } else if(order == 6){
        quickSort(datas, 0, size, order);
        for(int i = 0; i < size; i++){
            if(strstr(datas[i].type, search) != NULL){
                printf("%s  | %s    | %lld | %d | %d | %d | %s | %lld | %s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
            }
        }
        return;
    } else if(order == 7){
        quickSort(datas, 0, size, order);
        for(int i = 0; i < size; i++){
            if(strstr(datas[i].furnish, search) != NULL){
                printf("%s  | %s    | %lld | %d | %d | %d | %s | %lld | %s\n", datas[i].loc1, datas[i].loc2, datas[i].price, datas[i].rooms, datas[i].bathrooms, datas[i].carparks, datas[i].type, datas[i].area, datas[i].furnish);
            }
        }
        return;
    }
}

void swap(housing *a, housing *b){
    housing t = *a;
    *a = *b;
    *b = t; 
}

int partition(housing arr[], int low, int high, int order){
    housing pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high-1; j++){
        if(order == 1 && strcmp(arr[j].loc1, pivot.loc1) < 0){
            i++;
            swap(&arr[j], &arr[i]);
        } else if(order == 2 && strcmp(arr[j].loc2, pivot.loc2) < 0){
            i++;
            swap(&arr[j], &arr[i]);
        } else if(order == 3 && arr[j].rooms < pivot.rooms){
            i++;
            swap(&arr[j], &arr[i]);
        } else if(order == 4 && arr[j].bathrooms < pivot.bathrooms){
            i++;
            swap(&arr[j], &arr[i]);
        } else if(order == 5 && arr[j].carparks < pivot.carparks){
            i++;
            swap(&arr[j], &arr[i]);
        } else if(order == 6 && strcmp(arr[j].type, pivot.type) < 0){
            i++;
            swap(&arr[j], &arr[i]);
        } else if(order == 7 && strcmp(arr[j].furnish, pivot.furnish) < 0){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[high], &arr[i + 1]);
    return i + 1;
}

void quickSort(housing arr[], int low, int high, int order){
    if(low <= high){
        int pi = partition(arr, low, high, order);

        quickSort(arr, low, pi - 1, order);
        quickSort(arr, pi + 1, high, order);
    }
}
