#include <stdio.h>

struct student {
    char code[101];
    char name[101];
    char gender[101];
    char fname[101];
    char mname[101];
    int siblings;
};


struct lecture {
    char code[101];
    char name[101];
    char gender[101];
    int studentnum;
};


int main(){

    int numoflec;
    scanf("%d", &numoflec); getchar();
    struct lecture dosen[numoflec];
    struct student allstudent[100][100];
    int choise;

    for(int i = 0; i < numoflec; i++){
        scanf("%[^\n]", dosen[i].code); getchar();
        scanf("%[^\n]", dosen[i].name); getchar();
        scanf("%[^\n]", dosen[i].gender); getchar();
        scanf("%d", &dosen[i].studentnum); getchar();

        for(int j = 0; j < dosen[i].studentnum; j++){
            scanf("%[^\n]", allstudent[i][j].code); getchar();
            scanf("%[^\n]", allstudent[i][j].name); getchar();
            scanf("%[^\n]", allstudent[i][j].gender); getchar();
            scanf("%[^\n]", allstudent[i][j].fname); getchar();
            scanf("%[^\n]", allstudent[i][j].mname); getchar();
            scanf("%d", &allstudent[i][j].siblings); getchar();
        }
    }
    scanf("%d", &choise);
    printf("%d\n", choise);
    choise--;
    printf("Kode Dosen: %s\n", dosen[choise].code);
    printf("Nama Dosen: %s\n", dosen[choise].name);
    printf("Gender Dosen: %s\n", dosen[choise].gender);
    printf("Jumlah Mahasiswa: %d\n", dosen[choise].studentnum);
    for(int j = 0; j < dosen[choise].studentnum; j++){
        printf("Kode Mahasiswa: %s\n", allstudent[choise][j].code);
        printf("Nama Mahasiswa: %s\n", allstudent[choise][j].name); 
        printf("Gender Mahasiswa: %s\n", allstudent[choise][j].gender); 
        printf("Nama Ayah: %s\n", allstudent[choise][j].fname); 
        printf("Nama Ibu: %s\n", allstudent[choise][j].mname); 
        printf("Jumlah Saudara Kandung: %d\n", allstudent[choise][j].siblings); 
    }
    return 0;
}
/*
2
D8903
Bibi
Perempuan 
1
B1234
Jojo
Laki-laki
MrJojo
MsJojo 
3
D3456
Bibii
Laki-laki 
2
B9876
Jojoo
Laki-laki
MrJojoo
MsJojoo 
3
B7777
Jo
Laki-laki
MrJo
MsJo 
0
2
*/
