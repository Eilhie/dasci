#include <stdio.h>

int main(){

    int m;
    scanf ("%d", &m); getchar();
    int arr[m+5];
    for (int i = 0; i < m; i++){
        scanf ("%d", &arr[i]); getchar();
    }
    int n;
    scanf ("%d", &n); getchar();
    int que[n+5];
    for (int i = 0; i < n; i++){
        scanf ("%d", &que[i]); getchar();
        for (int j = 0; j < m; j++){
            if (que[i] == arr[j]) printf ("%d\n", m-j-1);
        }
    }

    return 0;
}