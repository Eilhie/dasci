#include <stdio.h>
#include <string.h>

int main(){

    char original[100];
    int index, repeat;

    scanf("%[^\n]", original);
    scanf("%d %d", &index, &repeat);

    char new[index][100];
    for(int j = 0; j < index; j++){
        for(int i = 0; i < strlen(original); i++){
            if(original[i] != ' '){
                new[j][i] = original[i];
            } else if(original[i] == ' '){
                break;
            }
            printf("%s ", new[0]);
        }
    }
    

    

    return 0;
}