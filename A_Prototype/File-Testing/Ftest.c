#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
} 

int main(){    
    FILE *fp;
    fp = fopen("testdata.in","r");
    int cases;
    fscanf(fp, "%d\n", &cases);

    for(int i = 0; i < cases; i++){
        char str[111];
        int changes;
        char search, new[30];
        int changed[100] = {0};
        int count[26] = {0};
        fscanf(fp, "%s\n", str);
        fscanf(fp, "%d\n", &changes);
        for(int j = 0; j < changes; j++){
            fscanf(fp, "%c %c\n", &search, &new[j]);
            for(int k = 0; k < strlen(str); k++){
                if((str[k] == search) && !changed[k]){
                    str[k] = new[j];
                    changed[k] = 1;
                    count[k]++;
                } else if(str[k] && !changed[k]){
                    count[k]++;
                }
            }
        }
        
        int len = strlen(str);
        for(int j = 0; j < len - 1; j++){
            for(int k = 0; k < len - 1 -j; k++){
                if(str[k] > str[k + 1]) swap(&str[k], &str[k + 1]);
            }
        }
        for(int j = 0; j < len; j++){
            printf("%c ", str[j]);
        }
        puts("");
    }
    fclose(fp);
    return 0;
}