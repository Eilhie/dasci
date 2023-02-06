#include <stdio.h>
int solve(int m, int n)
{
  int temp;
  if (n < m){
      temp = n;
      n = m;
      m = temp;
  }
  return m * (m + 1) * (2 * m + 1) / 6 + (n - m) * m *(m + 1)/ 2;
}
int main()
{
    int m,n,tc;
    scanf("%d", &tc);
    for(int i=0;i<tc;i++){
        scanf("%d %d", &m,&n);
        printf("Case #%d: %d\n", i+1,solve(m,n) );
    }
    return 0;
}