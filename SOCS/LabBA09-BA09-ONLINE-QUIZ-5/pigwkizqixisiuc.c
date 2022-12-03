// #include <stdio.h>

// int main(){

//     int test;
//     scanf("%d", &test);

//     for(int i = 0; i < test; i++){
//         int N; long long int K;
//         char string[100];
//         scanf("%d %lld", &N, &K); getchar();
//         scanf("%s", string);
//         for(int j = 0; j < N; j++){
//             string[j] = string[j] - 97 + (K%26);
//             string[j] %= 26;
//             string[j] += 97;
//         }
//         printf("Case #%d: %s\n", i + 1, string);
//     }

//     return 0;
// }


#include<stdio.h>

int main(){

    int p;
    scanf("%d", &p);getchar();

    int i,j,k;
    int a;
    long long int b;
    int asc = 0;

    for(i=0 ; i<p ;  i++){
        scanf("%d %lld", &a, &b);getchar();
        char x[a];
        scanf("%[^\n]", &x);getchar();

        printf("Case #%d: ", i+1);
        for(j=0 ; j<a ; j++){
            asc = x[j]-97;
            asc += b;
            for(k=0 ; k<asc ; k++){
                if(asc>25)
                    asc-=26;
                else if (asc<=25)
                    break;
            }
            asc+=97;
            printf("%c", asc);

        }
        printf("\n");
    }

    return 0;
}