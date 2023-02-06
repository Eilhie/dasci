#include <stdio.h>

int main(){

    int len;
    scanf("%d", &len);
    int list, count = 0;
    for(int i = 0; i < len; i++){
        scanf("%d", &list);
        if(list == 1) count++;
    }
    if(count > 0) printf("not easy\n");
    else printf("easy\n");
    return 0;
}