#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    scanf("%d %d",&n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < q; i++) {
        int b;
        scanf("%d", &b);
        vector<int>::iterator lower = lower_bound(a.begin(), a.end(), b);
        vector<int>::iterator upper = upper_bound(a.begin(), a.end(), b);
        if (lower != a.end() && *lower == b) {
            printf("%ld\n", upper - lower);
        }
        else {
            puts("0");
        }
    }
    return 0;
}
