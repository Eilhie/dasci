#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);

    double celcius[testCases];

    for(int i = 0; i < testCases; i++){
        scanf("%lf", &celcius[i]);
    }

    double reamur[testCases], fahrenheit[testCases], kelvin[testCases];

    for(int i = 0; i < testCases; i++){

        reamur[i] = 4 * celcius[i] / 5;
        fahrenheit[i] = 9 * celcius[i] / 5;
        kelvin[i] = celcius[i] + 273;

        printf("%.2f %.2f %.2f\n", reamur[i], fahrenheit[i] +32, kelvin[i]);
    }

    return 0;
}