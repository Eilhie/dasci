#include <stdio.h>

int main(){

    int arr[] = {751, 577, 251, 429, 711, 335, 728, 333, 810, 837, 948, 881, 608, 154, 709, 201, 222, 767, 603, 627, 117, 307, 4, 891, 904, 851, 668, 48, 931, 914, 841, 425, 929, 920, 742, 493, 458, 821, 998, 665, 26, 561, 591, 567, 72, 515, 919, 496, 734, 884, 118, 811, 293, 428, 361, 184, 284, 426, 174, 208, 237, 893, 933, 215, 622, 770, 19, 196, 108, 852, 67, 972, 831, 416, 649, 818, 323, 133, 220, 486, 412, 494, 229, 861, 415, 373, 432, 197, 298, 905, 901, 525, 396, 403, 95, 140, 819, 172, 873, 688};
    int x;
    scanf("%d", &x);
    int flag = 0;
    for(int j = 0; j < sizeof(arr)/sizeof(int); j++){

        if(arr[j] == x){ printf("ketemu, %d\n", j + 1); flag = 1; break;}

    }
    if(flag == 0) printf("ga ketemu\n");


    return 0;
}

