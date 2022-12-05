#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void binary_search(char *list_of_words[], int size, char *target){
    int bottom= 0;
    int mid;
    int top = size - 1;

    while(bottom <= top){
        mid = (bottom + top)/2;
        if (strcmp(list_of_words[mid], target) == 0){
            printf("%s found at location %d.\n", target, mid+1);
            return;
        } else if (strcmp(list_of_words[mid], target) > 0){
            top    = mid - 1;
        } else if (strcmp(list_of_words[mid], target) < 0){
            bottom = mid + 1;
        }
    }
}

int main(){

    char *verbs[5] = { "do", "make", "shit", "talk", "walk" };

    binary_search(verbs, 5, "shit");

    return 0;
}