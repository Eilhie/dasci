#include <stdio.h>

int main(){

    long int wparr, dgarr;

    scanf("%ld %ld", &wparr, &dgarr);
    
    long int wpdmg[wparr], dgdmg[dgarr];

    for(int i = 0; i < wparr; i++){
        scanf("%ld", &wpdmg[i]);
    }

    for(int i = 0; i < dgarr; i++){
        scanf("%ld", &dgdmg[i]);
    }

    for (int i = 1; i < wparr; ++i) {
        if (wpdmg[0] < wpdmg[i]) {
            wpdmg[0] = wpdmg[i];
        }
    }

    for (int i = 1; i < dgarr; ++i) {
        if (dgdmg[0] < dgdmg[i]) {
            dgdmg[0] = dgdmg[i];
        }
    }

    if(wpdmg[0] <= dgdmg[0]){
        printf("Secret debunked\n");
    } else{
        printf("The dark secret was true\n");
    }



    return 0;
}