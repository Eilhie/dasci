#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 11
#define MAX_GROUP_NUMBER 21
#define MAX_STUDENTS 201

// Structure to store a student's information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int group;
} student_t;

int main(int argc, char **argv) {
    int t, n, i, j;
    student_t students[MAX_STUDENTS];

    // Read in the number of test cases
    scanf("%d", &t);

    for (int testCase = 1; testCase <= t; testCase++) {
        // Read in the number of students
        scanf("%d", &n);

        // Read in the students' information
        for (i = 0; i < n; i++) {
            scanf("%s %d", students[i].name, &students[i].group);
        }

        // Print out the groups
        printf("Case #%d:\n", testCase);
        for (i = 1; i <= MAX_GROUP_NUMBER; i++) {
            // Count how many students are in the current group
            int count = 0;
            for (j = 0; j < n; j++) {
                if (students[j].group == i) {
                    count++;
                }
            }

            // If there are any students in the current group, print them out
            if (count > 0) {
                printf("Group %d(%d):\n", i, count);
                for (j = 0; j < n; j++) {
                    if (students[j].group == i) {
                        printf("%s\n", students[j].name);
                    }
                }
            }
        }
    }

    return 0;
}
