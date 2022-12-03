#include <stdio.h>

int main(){

    long int x,y,a,b,x1,y1,a1,b1,x2,y2,a2,b2;
    scanf("(%ld+%ld)x(%ld-%ld)\n",&x,&y,&a,&b);
    scanf("(%ld+%ld)x(%ld-%ld)\n",&x1,&y1,&a1,&b1);
    scanf("(%ld+%ld)x(%ld-%ld)",&x2,&y2,&a2,&b2);

    long int res1 = ((x+y)*(a-b));
    long int res2 = ((x1+y1)*(a1-b1));
    long int res3 = ((x2+y2)*(a2-b2));

    printf("%ld %ld %ld\n", res1, res2,res3);



    // (1+2)x(3-4)
    


    return 0;
}
