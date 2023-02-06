#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5;

int n, k;
int data[MAX_N];
int counting[MAX_N];

void insert(int x) {
    data[n++] = x;
}

void alter(int x, int y) {
    for (int i = 0; i < n; i++) {
        if (data[i] == x) {
            data[i] = y;
            break;
        }
    }
}

void remove(int x) {
    for (int i = 0; i < n; i++) {
        if (data[i] == x) {
            for (int j = i; j < n - 1; j++) {
                data[j] = data[j + 1];
            }
            n--;
            break;
        }
    }
}

int query(int x) {
    for (int i = 0; i < n; i++) {
        counting[data[i]]++;
    }
    int res = 0;
    for (int i = 0; i <= x; i++) {
        res += counting[i];
    }
    return res;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(x);
    }
    while (k--) {
        char op;
        int x, y;
        cin >> op >> x;
        if (op == 'I') {
            insert(x);
        } else if (op == 'A') {
            cin >> y;
            alter(x, y);
        } else if (op == 'D') {
            remove(x);
        } else if (op == 'Q') {
            // sort(data, data + n);
            cout << query(x) << endl;
        }
    }
    return 0;
}
