// #include <stdio.h>
// #include <math.h>

// void fractal(int a, int b, int segment, int XL, int XR){
//     if (segment <= (b-a)+1)
//         printf("%d %d\n", XL, XR);
//     if (segment < b){ 
//         fractal(a, b, segment+1, XL, XR);
//         fractal(a, b, segment+1, XL + segment, XR + segment);
//     }
//     return;
// }

// int main(){

//     int a, b;
//     scanf("%d %d", &a, &b); getchar();
//     fractal(a,b, 1, 1, 1);

//     return 0;
// }
#include <stdio.h>
void fractal(int iter, int seg) {
  if (iter <= 0) return;
  int k = 1 << (iter - 1);
  if (seg <= k) printf("%d %d\n", seg, k + 1 - seg);
  else printf("%d %d\n", 2 * k + 1 - seg, 2 * k + 2 - seg);
  fractal(iter - 1, seg);
}

int main() {
  int A,B;
  scanf("%d %d", &A, &B);
  fractal(B, A);
  return 0;
}
