#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int n, m;
        scanf("%d %d", &n, &m);

        int rooms[n];
        for(int j = 0; j < n; j++){
            rooms[j] = 0;
        }

        int pattern[m];
        for(int j = 0; j < m; j++){
            scanf("%d", &pattern[j]);
        }

        for(int j = 0; j < m; j++){
            for(int k = 1; k <= n; k++){
                if(k % pattern[j] == 0) rooms[k - 1] = rooms[k - 1] ^ 1;
            }
        }
        printf("Case #%d:", i + 1);
        int count = 0;
        for(int j = 0; j < n; j++){
            if(rooms[j] == 0){
                printf(" %d", j + 1);
            } else count++;
        }

        if(count == n) printf(" No room left!");
        puts("");
    }

    return 0;
}
