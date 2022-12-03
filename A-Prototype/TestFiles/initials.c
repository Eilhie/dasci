#include <stdio.h>
#include <string.h>

// int main(){

//     int testCases;
//     scanf("%d", &testCases);
//     getchar();

//     char string[1000];

//     for(int i = 1; i <= testCases; i++){
//         gets(string);
//         printf("Case #%d: ", i);
//         for(int j = 0; j < strlen(string); j++){
//             if((j == 0) && (string[j] != ' ') && (string[j] >= 'A' && string[j] <= 'Z')){
//                 printf("%c", string[j]);
//             } 
//             if(string[j] == ' '){
//                 if((string[j + 1] != ' ') && (string[j + 1] >= 'A' && string[j + 1] <= 'Z')){
//                     printf("%c", string[j + 1]);
//                 }
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }

int main(){
    int tc;
    scanf("%d", &tc); getchar();
    for(int i = 0; i < tc; i++){
        char name[1000] = {0};
        scanf("%[^\n]", name); getchar();
        printf("Case #%d: ", i + 1);

        if(name[0] >= 'A' && name[0] <= 'Z'){
            printf("%c", name[0]);
        } else {
            printf("%c", name[0] - ('a' - 'A'));
        }
        for(int j = 1; name[j] != '\0'; j++){
            if(name[j - 1] = ' '){
                if(name[j] >= 'A' && name[j] <= 'Z'){
                    printf("%c", name[j]);
                } else {
                    printf("%c", name[j]- ('a'-'A'));
                }
            }
        }
        printf("\n");
    }
}