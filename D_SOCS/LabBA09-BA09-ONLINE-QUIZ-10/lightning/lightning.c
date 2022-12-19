// #include<stdio.h>

// int main(){    
//     FILE *fp;
//     fp = fopen("testdata.in","r");
//     int datacount;
//     fscanf(fp,"%d\n",&datacount);
//     for(int i = 0; i < datacount; i++){
//         int total, min, max, count = 0;
//         fscanf(fp, "%d %d %d\n", &total, &min, &max);
//         char biner[total + 10];
//         fscanf(fp, "%s\n", biner);
//         if(min >= max) count = 0;
//         else {
//             for(int j = 0; j < total; j++){
//                 if(biner[j] == '1' && min - 1 < j && j < max - 1) {
//                     count++;
//                 }
//             }
//         }
        
//         printf("Case #%d: %d\n", i + 1, count);
//     }
    
//     fclose(fp);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    // Open the input file
    FILE* f = fopen("testdata.in", "r");
    if (f == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Parse the input file
    int T;
    fscanf(f, "%d", &T);
    for (int i = 0; i < T; i++) {
        // Extract the values of N, A, and B for the current test case
        int N, A, B;
        fscanf(f, "%d %d %d", &N, &A, &B);
        // Read the binary string for the current test case
        char s[N+1];
        fscanf(f, "%s", s);
        // Initialize the count of lightning occurrences
        int lightning_count = 0;
        // Iterate through the binary string
        for (int j = 0; j < N; j++) {
            if (s[j] == '1') {
                // Check if the following series of 0s has a length between A and B (inclusive)
                int count = 0;
                while (j < N && s[j] == '0') {
                    count++;
                    j++;
                }
                if (A <= count && count <= B) {
                    // Increment the count of lightning occurrences
                    lightning_count++;
                }
            }
        }
        // Output the result for the current test case
        printf("Case #%d: %d\n", i+1, lightning_count);
    }

    // Close the input file
    fclose(f);
    return 0;
}
