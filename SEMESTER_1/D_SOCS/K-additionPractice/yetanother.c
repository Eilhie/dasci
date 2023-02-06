// #include <stdio.h>
// #include <math.h>


// int main(){
//     int n;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++){
//         int base, power, powerofe;
//         scanf("%d %d %d", &base, &power, &powerofe);
//         printf("Case #%d: ", i + 1);
//         if(pow(base,power) < pow(M_E, powerofe)) printf("<\n");
//         if(pow(base,power) > pow(M_E, powerofe)) printf(">\n");

//     }

//     return 0;
// }
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (pow(a, b) < exp(c)) {
            cout << "Case #" << i << ": <" << endl;
        } else {
            cout << "Case #" << i << ": >" << endl;
        }
    }

    return 0;
}
