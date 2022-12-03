// #include <stdio.h>

// int main(){

//     double numa1,numb1,numc1,numd1;
//     double numa2,numb2,numc2,numd2;
//     double numa3,numb3,numc3,numd3;

//     scanf("%lf %lf %lf %lf",&numa1 ,&numb1, &numc1, &numd1);
//     scanf("%lf %lf %lf %lf",&numa2 ,&numb2, &numc2, &numd2);
//     scanf("%lf %lf %lf %lf",&numa3 ,&numb3, &numc3, &numd3);
    
//     double result1 = (numa1/1 *2) + (numb1/2 * 4) + (numc1/3 * 6) + (numd1/4 *4);
//     double result2 = (numa2/1 *2) + (numb2/2 * 4) + (numc2/3 * 6) + (numd2/4 *4);
//     double result3 = (numa3/1 *2) + (numb3/2 * 4) + (numc3/3 * 6) + (numd3/4 *4);
//     printf("%.2f\n%.2f\n%.2f\n", result1,result2,result3);
//     return 0;
// }

#include <stdio.h>

int main(){
	double a,b,c,d;
	double a1,b1,c1,d1;
	double a2,b2,c2,d2;
	double line1,line2,line3;
	
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	scanf("%lf %lf %lf %lf",&a1,&b1,&c1,&d1);
	scanf("%lf %lf %lf %lf",&a2,&b2,&c2,&d2);
	
	line1=(a/1*2)+(b/2*4)+(c/3*6)+(d/4*4);
	line2=(a1/1*2)+(b1/2*4)+(c1/3*6)+(d1/4*4);
	line3=(a2/1*2)+(b2/2*4)+(c2/3*6)+(d2/4*4);
	
	printf("%.2f\n",line1);
	printf("%.2f\n",line2);
	printf("%.2f\n",line3);
	
	return 0;
}