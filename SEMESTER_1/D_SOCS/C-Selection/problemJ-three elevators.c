#include <stdio.h>

int main(){

    int x,y,z;
    scanf("%d %d %d", &x,&y,&z);

   for(int i = 0;; i++){
        if((x + i == z) && (y - i == z)){
            printf("%d\n", i);
            break;
        }
        else if((x + i > z) || (y - i < z)){
            printf("-1\n");
            break;
        }
   }

    return 0;
}