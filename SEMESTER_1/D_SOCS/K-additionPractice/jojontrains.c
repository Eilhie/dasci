#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

struct Train {
    char id[21];
    char departure[6];
    char origin[MAX_LEN + 1];
    char destination[MAX_LEN + 1];
} trains[1001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", trains[i].id, trains[i].departure);
    }
    for (int i = 0; i < n; i++) {
        char id[21];
        char origin[MAX_LEN + 1];
        char destination[MAX_LEN + 1];
        scanf("%s %s %s", id, origin, destination);
        for (int j = 0; j < n; j++) {
            if (strcmp(id, trains[j].id) == 0) {
                strcpy(trains[j].origin, origin);
                strcpy(trains[j].destination, destination);
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s %s %s %s\n", trains[i].id, trains[i].departure, trains[i].origin, trains[i].destination);
    }
    return 0;
}
