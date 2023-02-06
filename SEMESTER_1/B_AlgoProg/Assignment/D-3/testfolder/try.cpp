#include <stdio.h>
#include <string.h>

char data[4][10] = {"anderson", "amelia", "derian", "georion"};

void contains_search(char* key) {
    printf("Results for contains search: ");
    for (int i = 0; i < 4; i++) {
        if (strstr(data[i], key) != NULL) {
            printf("%s ", data[i]);
        }
    }
    printf("\n");
}

void starts_search(char* key) {
    printf("Results for starts search: ");
    for (int i = 0; i < 4; i++) {
        if (strncmp(data[i], key, strlen(key)) == 0) {
            printf("%s ", data[i]);
        }
    }
    printf("\n");
}

void ends_search(char* key) {
    printf("Results for ends search: ");
    for (int i = 0; i < 4; i++) {
        int keyLen = strlen(key);
        int dataLen = strlen(data[i]);
        if (strncmp(data[i] + dataLen - keyLen, key, keyLen) == 0) {
            printf("%s ", data[i]);
        }
    }
    printf("\n");
}

void filter_search_num(int key, char *opr, int *datas,int size) {
    printf("Results for filter search %s: ", opr);
    for (int i = 0; i < size ; i++) {
        if (strcmp(opr, ">") == 0 && datas[i] > key) {
            printf("%d ", datas[i]);
        }
        else if (strcmp(opr, "<") == 0 && datas[i] < key) {
            printf("%d ", datas[i]);
        }
    }
    printf("\n");
}

int main() {
    char search_key[10];
    strcpy(search_key, "ri");
    contains_search(search_key);
    strcpy(search_key, "a");
    starts_search(search_key);
    strcpy(search_key, "an");
    ends_search(search_key);

    int data_num[7] = {10, 30, 20, 40, 70, 60, 50};
    int search_key_num = 45;
    filter_search_num(search_key_num, ">", data_num, 7);
    filter_search_num(search_key_num, "<", data_num, 7);

    return 0;
}
