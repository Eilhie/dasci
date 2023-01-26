#include <stdio.h>

const char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int zeller(int day, int month, int year) {
    if (month == 1) {
        month = 13;
        year--;
    }
    if (month == 2) {
        month = 14;
        year--;
    }
    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    // Calculate h = (k + (13*m-1)/5 + y + y/4 - j/4 + 5*j) mod 7
    return h;
}


int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int day, month, year;
        char slash;
        scanf("%d%c%d%c%d", &day, &slash, &month, &slash, &year);
        // to check for leap year
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            if (month == 2 && day == 29) {
                printf("Case #%d: leap year\n", i);
                continue;
            }
        }
        printf("Case #%d: %s\n", i, days[zeller(day,month,year)]);
    }
    return 0;
}
