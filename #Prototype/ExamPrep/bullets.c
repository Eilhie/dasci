#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int bullets, length;
        int travelabil = 100;
        double distance = 100;
        scanf("%d %d", &bullets, &length);
        int plates[length];
        for(int j = 0; j < length; j++){
            scanf("%d", &plates[j]);
        }
        
        for(int k = 0; k < bullets; k++){
            int a = 0, b = 0;
            double temp;
            distance = 100;
            for(int j = 0; j < travelabil; j++){
                if(j == plates[a]){
                    temp = distance;
                    distance -= b;
                    distance = distance - (distance * 25 / 100);
                    if(distance <= 0){
                        break;
                    } else {
                        plates[a]= 0;
                        a++;
                    }
                    // printf("%.2f\n", distance - (distance * 25 / 100));
                    // printf("%.2f\n", temp);
                    
                    b = 0;
                }
                b++;
                if(distance <= 0) break;
            }
        
        
            printf("%d\n", a);
            printf("falls on %.1f %.1f\n", plates[a- 1] + temp, temp);
        }

    }

    return 0;
}