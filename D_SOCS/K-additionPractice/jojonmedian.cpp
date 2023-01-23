#include <stdio.h>

struct item {
    char id[11];
    char name[20];
    double price;
};


int main(){
    int n;
    scanf("%d", &n); getchar();
    item items[50000];
    for(int i = 0; i < n; i++){
        scanf("%[^\n]", items[i].id); getchar();
        scanf("%[^\n]", items[i].name); getchar();
        scanf("%lf", &items[i].price); getchar();
    }
    for (int i = 0; i < n; i++){
        if(items[i].price >= items[n/2].price)
            printf("%s %s\n", items[i].id, items[i].name);
    }
    
    return 0;
}
