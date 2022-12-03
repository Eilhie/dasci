#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,hour1list[30],hour2list[30],minute1list[30],minute2list[30], hour1, hour2, minute1, minute2;
    char name[30];

    for(i = 0; i<5; i++){ 
        name[i] = malloc(100* sizeof(char));
        scanf("%s %d:%d-%d:%d", name[i], &hour1, &minute1, &hour2, &minute2);
        hour1list[i]=hour1;
        minute1list[i]=minute1;
        hour2list[i]=hour2;
        minute2list[i]=minute2;
    }

    for(i = 0; i<5; i++){
        printf("%s %0.2d:%0.2d-%0.2d:%0.2d\n", name[i], hour1list[i]-1, minute1list[i], hour2list[i]-1, minute2list[i]);
    }

    return 0;
}