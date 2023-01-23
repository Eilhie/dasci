#include <stdio.h>
#include <math.h>


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int base, power, powerofe;
        scanf("%d %d %d", &base, &power, &powerofe);
        printf("Case #%d: ", i + 1);
        if(pow(base,power) < pow(M_E, powerofe)) printf("<\n");
        if(pow(base,power) > pow(M_E, powerofe)) printf(">\n");

    }

    return 0;
}