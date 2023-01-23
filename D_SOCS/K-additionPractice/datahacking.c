#include <stdio.h>
#include <string.h>

struct Employee {
    char name[26];
    int salary[3];
} employees[151];

int main() {
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d %d", employees[i].name, &employees[i].salary[0], &employees[i].salary[1], &employees[i].salary[2]);
        }
        for (int i = 0; i < q; i++) {
            int type, u, v;
            scanf("%d %d %d", &type, &u, &v);
            u--; v--;
            if (type == 1) {
                // reverse
                for (int j = u; j < (u + v + 1) / 2; j++) {
                    int temp[3];
                    char temp_name[26];
                    strcpy(temp_name, employees[j].name);
                    temp[0] = employees[j].salary[0];
                    temp[1] = employees[j].salary[1];
                    temp[2] = employees[j].salary[2];
                    strcpy(employees[j].name, employees[v-(j-u)].name);
                    employees[j].salary[0] = employees[v-(j-u)].salary[0];
                    employees[j].salary[1] = employees[v-(j-u)].salary[1];
                    employees[j].salary[2] = employees[v-(j-u)].salary[2];
                    strcpy(employees[v-(j-u)].name, temp_name);
                    employees[v-(j-u)].salary[0] = temp[0];
                    employees[v-(j-u)].salary[1] = temp[1];
                    employees[v-(j-u)].salary[2] = temp[2];
                }
            } else {
                // shift
                char temp_name[26]; 
                int temp_salary[3];
                strcpy(temp_name, employees[u].name);
                temp_salary[0] = employees[u].salary[0];
                temp_salary[1] = employees[u].salary[1];
                temp_salary[2] = employees[u].salary[2];
            for (int j = u; j < v; j++) {
                strcpy(employees[j].name, employees[j+1].name);
                employees[j].salary[0] = employees[j+1].salary[0];
                employees[j].salary[1] = employees[j+1].salary[1];
                employees[j].salary[2] = employees[j+1].salary[2];
            }
                strcpy(employees[v].name, temp_name);
                employees[v].salary[0] = temp_salary[0];
                employees[v].salary[1] = temp_salary[1];
                employees[v].salary[2] = temp_salary[2];
            }
        }
        printf("Case #%d:\n", cas);
        for (int i = 0; i < n; i++) {
            printf("%s %d\n", employees[i].name, employees[i].salary[0]);
        }
    }
    return 0;
}


