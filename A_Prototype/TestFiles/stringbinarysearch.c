#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap_str(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

void binary_search(char *list_of_words[], int size, char *target){
    int bottom = 0;
    int mid;
    int top = size - 1;
    while(bottom <= top){
        mid = (bottom + top)/2;
        if (strcmp(list_of_words[mid], target) == 0){
            printf("%s found at location %d.\n", target, mid+1);
            return;
        } else if (strcmp(list_of_words[mid], target) > 0){
            top = mid - 1;
        } else {
            bottom = mid + 1;
        }
    }
}

int main(){

    char *verbs[5] = { "do", "make", "shit", "talk", "walk" };
    char *key[20] = {"mkn", "sy", "ak", "mw", "km", "tdr", "tdk", "tp", "bljr", "pk", "syr", "ns", "aym", "bngng", "ssh", "klo", "skt", "bs", "sk", "akn"};
    char *typed[7] = {"sy", "tdk", "sk", "mkn", "syr", "pk", "ns"};
    
    binary_search(verbs, 5, "do");
    binary_search(verbs, 5, "shit");
    binary_search(verbs, 5, "walk");
    binary_search(verbs, 5, "make");
    binary_search(verbs, 5, "talk");

    for (int i = 0; i < 20 - 1; i++){
        for (int j = 0; j < 20 - i - 1; j++){
            if (strcmp(key[j], key[j + 1]) > 0){
                swap_str(key + j, key + j + 1);
            }
        }
    }

    binary_search(key, 20, "mkn");
    binary_search(key, 20, typed[2]);
    binary_search(key, 20, typed[3]);
    binary_search(key, 20, typed[4]);
    binary_search(key, 20, typed[5]);
    binary_search(key, 20, typed[6]);
    

    return 0;
}