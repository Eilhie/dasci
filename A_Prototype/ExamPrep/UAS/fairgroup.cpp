#include <stdio.h>

int min_diff(int arr[], int n) {
    int total_sum = 0;
    for (int i = 0; i < n; i++) total_sum += arr[i];
    int half_sum = total_sum / 2;
    bool dp[n + 1][half_sum + 1];

    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int j = 1; j <= half_sum; j++) dp[0][j] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= half_sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }

    for (int j = half_sum; j >= 0; j--) {
        if (dp[n][j])
            return total_sum - 2 * j;
    }
    return -1;
}

int main() {
    int arr[] = {1, 100, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min_difference = min_diff(arr, n);
    printf("The minimum difference between the two parts is: %d\n", min_difference);
    return 0;
}
