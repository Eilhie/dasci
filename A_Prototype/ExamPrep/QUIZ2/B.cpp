#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct person {
    char name[20];
    int rank;
};

int compare(const void *a, const void *b) {
    struct person *pa = (struct person *)a;
    struct person *pb = (struct person *)b;
    return (pb->rank - pa->rank);
}

int main() {
    int n;
    scanf("%d", &n);
    struct person data[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", data[i].name, &data[i].rank);
    }

    qsort(data, n, sizeof(struct person), compare);

    for (int i = 0; i < n; i++) {
        if (i > 0 && strcmp(data[i].name, data[i-1].name) == 0) {
            continue;
        }
        printf("%s [%d]\n", data[i].name, data[i].rank);
    }
    return 0;
}
