#include <stdio.h>

int  main(){
     
    long a,b,c,d;

    scanf("%ld %ld %ld %ld",&a,&b,&c,&d);

    if((a*b) > (c+d)){
        printf("True\n");
    }else{
        printf("False\n");
    }

    return 0;
}