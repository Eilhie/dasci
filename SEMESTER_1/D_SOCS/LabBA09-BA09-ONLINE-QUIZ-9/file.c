#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){    
    FILE *fp;
    fp = fopen("testdata.in","r");
    int datacount;
    fscanf(fp,"%d\n",&datacount);
    char *sstr[100];
    char *lstr[100];
    char stemp[150], ltemp[150];
    for(int i = 0; i < datacount; i++){
        fscanf(fp,"%[^#]#%[^\n]\n", stemp, ltemp);
        sstr[i] = malloc(strlen(stemp)*sizeof(char*));
        strcpy(sstr[i], stemp);
        lstr[i] = malloc(strlen(ltemp)*sizeof(char*));
        strcpy(lstr[i], ltemp);
    }
    int cases;
    fscanf(fp,"%d\n",&cases);
    for(int i = 0; i < cases; i++){
        char string[150];
        fscanf(fp, "%[^\n]\n", string);
        char list[100][150];
        char *token = strtok(string, " ");
        int l = 0;
        while(token!=NULL){
            strcpy(list[l], token);
            token = strtok(NULL, " ");
            l++;
        }
        printf("Case #%d:\n", i + 1);
        for(int j = 0; j < l; j++){
            for(int k = 0; k < datacount; k++){
                if(strcmp(list[j], sstr[k]) == 0){
                    strcpy(list[j], lstr[k]);
                }
            }
            if(j == l - 1) printf("%s\n", list[j]);
            else printf("%s ", list[j]);
        }
    }
    fclose(fp);
    return 0;
}