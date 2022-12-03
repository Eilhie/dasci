// aan curang 
// tiap genap -2000
// tiap ganjil -2500

#include <stdio.h>

int main(){

    int jumlah;
    scanf("%d", &jumlah);
    int aan[jumlah], kenken[jumlah];
    for (int i = 0; i < jumlah; i++){
        scanf("%d", &aan[i]);
    }
    for (int i = 0; i < jumlah; i++){
        scanf("%d", &kenken[i]);
    }

    // if(jumlah % 2 == 0){
    //     aan[1] += 2000;
    // } else {
    //     aan[0] += 2500;
    // }
    int totalaan = 0, totalkenken = 0;
    for(int i = 0; i < jumlah; i++){
        totalaan += aan[i];
        totalkenken += kenken[i];
    }
    if(jumlah % 2 == 0){
        printf("%d %d", totalaan + (jumlah / 2 * 2000), totalkenken);
    } else {
        printf("%d %d", totalaan + ((jumlah - (jumlah % 2)) * 2500), totalkenken);
    }
    
    

    return 0;
}