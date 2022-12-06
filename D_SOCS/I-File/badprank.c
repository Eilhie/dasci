#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int linearsearch(char **key, char *target, int datacount){
    for(int k = 0; k < datacount; k++){
        if(strcmp(target, key[k]) == 0){
            return k;
        }
    }
    return -1;
}

int main(){    
    FILE *fp;
    fp = fopen("testdata.in","r");
    int testcases;

    char key[] = {'O', 'I', 'E', 'A', 'S', 'G', 'T', 'B', '\0'};
    char num[8] = {'0', '1', '3', '4', '5', '6', '7', '8'};
    int datacount = strlen(key);

    fscanf(fp,"%d\n",&testcases);
    char str[1050];
    for(int i = 0; i < testcases; i++){
        int shift;
        fscanf(fp, "%d\n", &shift);
        fscanf(fp,"%[^\n]\n", str);
        for(int j = 0; j < strlen(str); j++){
            for(int k = 0; k < datacount; k++){
                if(str[j] == num[k]){
                    str[j] = key[k];
                }
            }
            if(str[j] != ' '){
                if(str[j] > 64 && str[j] < 91){
                    if(str[j] - shift < 64)
                        str[j] = 26 + (str[j] - shift);
                    else    
                        str[j] = str[j] - shift;
                } else if(str[j] > 96 && str[j] < 123){
                    if(str[j] - shift < 96)
                        str[j] = 26 + (str[j] - shift);
                    else    
                        str[j] = str[j] - shift;
                }
            }
                
        }
    
        printf("Case #%d: %s\n", i + 1, str);
    }
    fclose(fp);
    return 0;
}