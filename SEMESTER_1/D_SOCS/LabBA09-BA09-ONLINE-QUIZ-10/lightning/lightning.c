#include <stdio.h>

int main(){
    FILE *fp;
    fp = fopen("testdata.in","r");
    int T;
    fscanf(fp, "%d\n", &T);
    for(int i = 0; i < T; i++){
        int N, bottom, top;
        char string[10000];
        fscanf(fp, "%d %d %d\n", &N, &bottom, &top);
        fscanf(fp, "%s\n", string);
        int countOne=0, countLightning=0;
        for(int j=0; j<N; j++){
            if(string[j]=='1'){
                countOne++;
            } else if(string[j]=='0'){
                countOne=0;
            }
            if(countOne>=bottom && countOne<=top && (string[j+1]=='0'|| j==N-1)){
                countLightning++;
            }
        }
        printf("Case #%d: %d\n", i+1, countLightning);
    }
    fclose(fp);
}