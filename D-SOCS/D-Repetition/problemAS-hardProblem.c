#include <stdio.h>
#include <math.h>

int main(){

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
         int len;

        char str[100];
        char key[100];
        scanf("%d", &len);
        scanf("%s", str);
        scanf("%s", key);

        double score = 0;

        for(int j = 0; j < len; j++){
            if(str[j] == key[j]){
                score++;
            }
        }
        
        printf("Case #%d: %.0f\n", i+1, floor(score*100/len));
    }

    return 0;
}