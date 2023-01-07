#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void play(int turn, char **word, char **blanked, int *count, int *game){
    getchar();
    printf("PLAYER %d TURN\n", turn + 1);
    printf("SCORE : %d\n", count[turn]);
    printf("%s %s\n", word[turn], blanked[turn]);
    char guess;
    printf("GUESS : ");
    scanf("%c", &guess);
    for(int i = 0; i < strlen(word[turn]); i++){
        if(guess == word[turn][i] && blanked[turn][i] == '_'){
            blanked[turn][i] = guess;
            count[turn]++;
        }
    }
    
    char *end;
    end = strchr(blanked[turn], '_');
    if(end == NULL){
        printf("PLAYER %d WON!!!!\n", turn + 1);
        *game = 0;
    } 
}

int main(){
    int run = 1;
    do{
        int totalLen;
        int blank = 4;
        char *PWord[2], *PWordTemp[2];
        printf("Total of Letter : ");
        scanf("%d", &totalLen); getchar();

        srand(time(0));

        PWord[0] = malloc(totalLen*sizeof(char));
        PWord[1] = malloc(totalLen*sizeof(char));
        PWordTemp[0] = malloc(totalLen*sizeof(char));
        PWordTemp[1] = malloc(totalLen*sizeof(char));
        int *P1Pos = malloc(blank*sizeof(int));
        int *P2Pos = malloc(blank*sizeof(int));
        printf("Player 1 Word (max %d) : ", totalLen / 2);
        scanf("%s", PWord[0]);
        printf("Player 2 Word (max %d) : ", totalLen / 2);
        scanf("%s", PWord[1]);

        strcpy(PWordTemp[0], PWord[0]);
        strcpy(PWordTemp[1], PWord[1]);

        for(int i = 0; i < blank; i++){
            int p1temp = rand() % (strlen(PWord[0]));
            int p2temp = rand() % (strlen(PWord[1]));
            P1Pos[i] = p1temp;
            P2Pos[i] = p2temp;
            PWordTemp[0][p1temp] = '_';
            PWordTemp[1][p2temp] = '_';
        }

        // printf("%s %s\n", PWordTemp[0], PWordTemp[1]);
        int game = 1;
        int turn = 0;
        int count[2] = {0};
        while(game){
            play(turn, PWord, PWordTemp, count, &game);
            turn = turn ^ 1;;
        }
        puts("");
        run = 0;
    } while (run);
}