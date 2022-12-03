#include <stdio.h>
#include <string.h>
int main()
{
    int N;
    char S[1005];
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", S);
        printf("Case #%d : ", i);
        char *p = S;
        for (int j = strlen(S) - 1; j >= 0; j--)
        {
            printf("%c", *(p + j));
        }
        
        printf("\n");
    }
    return 0;
}

