#include <stdio.h>

int main(){
    long long int frequency, n[1000], m[1000], hargaBarang[1000][100], totalharga[1000];
    scanf("%lld", &frequency);
    for(int i = 0; i<frequency; i++){
        scanf("%lld %lld", &n[i], &m[i]);
        for(int j = 0; j<n[i]; j++){
            scanf(" %lld", &hargaBarang[i][j]);
        }
    }
    for(int i = 0; i<frequency; i++){
        for(int j = 0; j<n[i]; j++){
            totalharga[i]+=hargaBarang[i][j];
        }
        if(totalharga[i]>m[i]){
            printf("Case #%d: Wash dishes\n", i+1);
        }else{
            printf("Case #%d: No worries\n", i+1);
        }
    }
}