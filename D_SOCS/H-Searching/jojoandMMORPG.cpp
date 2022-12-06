#include<stdio.h>
#include<stdlib.h>
void merge(long long int arr[], long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 = r - m;

    long long int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(long long int arr[], long long int l, long long int r)
{
    if (l < r) {

       long long int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main(){
long long int n,y;
 scanf("%lld", &n); 
long long int arr[n] = {0};
 for(long long int i = 0; i < n; i++){
  scanf("%lld", &arr[i]); 
 } 
 scanf("%lld", &y); 
 mergeSort(arr,0,n-1);
 long long int sum = 0;
 long long int j = 0;
 for(long long int i = 0; i < n; i++){
	if(y-arr[i] < 0){
		break;
	}
	else{
		y -= arr[i];
		j++;
	}
 }
 printf("%lld\n", j);
 return 0;
}