#include <stdio.h>
#include <stdlib.h>

int swapper(const void * p, const void * q) {
  return ( * (int * ) p - * (int * ) q);
}

void modus(int arr[], int n, int * max_count, int * res) {
  qsort((void * ) arr, n, sizeof(arr[0]), swapper);
  int curr_count = 1;* max_count = 1;* res = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1]) curr_count++;
    else {
      if (curr_count > * max_count) {
        * max_count = curr_count;* res = arr[i - 1];
      }
      curr_count = 1;
    }
  }
  if (curr_count > * max_count) {
    * max_count = curr_count;* res = arr[n - 1];
  }
}
int main() {
  int t,index=0;
  scanf("%d", & t);
  while (t-- != 0) {
    int n;
    scanf("%d", & n);
    int arr[n];

    for (int i = 0; i < n; i++) {
      scanf("%d", & arr[i]);
    }

    int max_count, elem;
    modus(arr, n, & max_count, & elem);
    printf("Case #%d: %d\n%d\n",index+1, max_count, elem);
    index++;
  }
  
  return 0;
}