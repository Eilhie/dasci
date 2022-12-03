#include <stdio.h>

int main(){
    int T;
    float num1,numb1,numc1,numd1;
    float num2,numb2,numc2,numd2;
    float num3,numb3,numc3,numd3;

    scanf("%d", &T);
    scanf("%f %f %f %f",&num1 ,&numb1, &numc1, &numd1);
    scanf("%f %f %f %f",&num2 ,&numb2, &numc2, &numd2);
    scanf("%f %f %f %f",&num3 ,&numb3, &numc3, &numd3);

    float sum1 =              num1/1+
                        numb1/2 + numb1/2+
                    numc1/3 + numd1/4+ numc1/3+
                    numc1/3 + numd1/4+ numc1/3+
                         numb1/2 + numb1/2+
                            num1/1;
    
    float sum2 =              num2/1+
                        numb2/2 + numb2/2+
                    numc2/3 + numd2/4+ numc2/3+
                    numc2/3 + numd2/4+ numc2/3+
                         numb2/2 + numb2/2+
                            num2/1;

    float sum3 =              num3/1+
                        numb3/2 + numb3/2+
                    numc3/3 + numd3/4+ numc3/3+
                    numc3/3 + numd3/4+ numc3/3+
                         numb3/2 + numb3/2+
                            num3/1;
    
    printf("%.2f\n", sum1);
    printf("%.2f\n", sum2);
    printf("%.2f\n", sum3);

    return 0;
}