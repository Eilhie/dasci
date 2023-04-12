#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define size 100
# define segsize 2

// HASH TABLE
// type of hashing :
// mid square, squared sum of ascii value of each character ( string key ), then take the middle part
// division, sum of ascii value ( string key ), then modulo by usually size
// folding, given the key then, devide it into some part, sum the all the part then modulo by size.
// digit extraction, extract the digit then combine to become hash
// rotation hash, flip the hash

int midSquareHash(int key){
    int squared = key * key;
    int middle = squared / 100 % 1000; // take the middle three digits
    return middle;
}

int divisionHash(int key){
    return key % size;
}

int foldingHash(int key)
{
    char str[20]; // allocate a buffer for the string representation of the key
    sprintf(str, "%d", key); // convert the key to a string
    
    int sum = 0;
    int len = strlen(str);
    char segment[20];
    // Process each segment of fixed size
    for (int i = 0; i < len; i += segsize) {
        int segment_sum = 0;
        
        for (int j = 0; j < segsize; j++) {
            if (i + j < len) {
                segment_sum += str[i + j];
                segment[j] = str[i + j];
            }
        }
        sum += atoi(segment);
        for(int j = 0; segment[j] != '\0'; j++){
            segment[j] = '\0';
        }
    }
    return sum % size;
}

int digitExtractionHash(int key){
    char str[20]; // allocate a buffer for the string representation of the key
    sprintf(str, "%d", key); // convert the key to a string
    char extract[20];
    int j = 0;
    for(int i = 0; i < strlen(str); i += segsize){
        if(i % 2 == 0) {
            extract[j] = str[i];
            j++;
        }
    }
    return atoi(extract);
}

int rotatingHash(int key) {
    int reversed = 0;
    int num = midSquareHash(key);
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return reversed;
}

int main(){

    printf("midsquare 3121 : %d\n", midSquareHash(3121));
    printf("folding 5678  : %d\n", foldingHash(5678));
    printf("division 5678  : %d\n", divisionHash(5678));
    printf("digit-extraction 14568  : %d\n", digitExtractionHash(14568));
    printf("rotation 3121  : %d\n", rotatingHash(3121));
}