#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long int arr[n + 3];
    for (int i = 0; i < n; ++i) 
        scanf("%lld", &arr[i]);

    int q;
    scanf("%d", &q);

    for (int i = 1; i <= q; ++i) {
        long long int sum;
        scanf("%lld", &sum);

        long long int currSum = arr[0], start = 0, maxIndex = -1, currIndex = 1;
 
        for (int i = 1; i < n; i++) {
            if (currSum <= sum)
                maxIndex = maxIndex > currIndex ? maxIndex : currIndex;

            while (start < i && currSum + arr[i] > sum) {
                currSum -= arr[start++];
                currIndex -= 1;
            }

            currSum += arr[i];
            currIndex += 1;
        }
    
        if (currSum <= sum)
            maxIndex = currIndex > maxIndex ? currIndex : maxIndex;
        
        printf("Case #%d: %lld\n", i, maxIndex);
    }
}