#include <stdio.h>

struct employee {
    char name[30];
    int sal1;
    int sal2; 
    int sal3;
};

void swapverti(employee *a, employee *b){
    int temp = a->sal1;
    a->sal1 = b->sal1;
    b->sal1 = temp;
    
    temp = a->sal2;
    a->sal2 = b->sal2;
    b->sal2 = temp;

    temp = a->sal3;
    a->sal3 = b->sal3;
    b->sal3 = temp;
}

void swaphori(employee *a){
    int temp = a->sal1;
    a->sal1 = a->sal2;
    a->sal2 = a->sal3;
    a->sal3 = temp;
}

void hackfix(int order, int start, int end, employee emp[]){
    if(order == 1) {
        for(int i = start, j = end; i < j; i++, j--){
            swapverti(&emp[i], &emp[j]);
        }
            
    } else if(order == 2){
        for(int i = start; i <= end; i++){
            swaphori(&emp[i]);
            
        }
    }
}

int main(){

    int tc;
    scanf("%d", &tc);getchar();
    for(int i = 1; i <= tc; i++){
        int amountofdatas, amountofchanges;
        scanf("%d %d", &amountofdatas, &amountofchanges);
        employee emp[amountofdatas];
        for(int j = 0; j < amountofdatas; j++){
            scanf("%s %d %d %d", emp[j].name, &emp[j].sal1, &emp[j].sal2, &emp[j].sal3); getchar();
        }
        for(int k = 0; k < amountofchanges; k++){
            int order, start, end;
            scanf("%d %d %d", &order, &start, &end); getchar();
            hackfix(order, start - 1, end - 1, emp);
            // for(int k = 0; k < amountofdatas; k++){
            //     printf("%s %d %d %d\n", emp[k].name, emp[k].sal1 , emp[k].sal2 ,emp[k].sal3);
            // }
            // puts("");
        }
        printf("Case #%d:\n", i);
        for(int k = 0; k < amountofdatas; k++){
            printf("%s %d\n", emp[k].name, emp[k].sal3);
        }
    }

    return 0;
}

