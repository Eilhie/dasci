#include <stdio.h>
#include <string.h>

typedef struct dataMahasiswa{
    char nama[101];
    char nim[101];
    int umur;
} dm;

typedef union datasiswa{
    char nama[101];
    int umur;
} ds;

void passStruct(dm s[], int size){
    for(int i = 0; i < size; i++){
        printf("%s %s %d\n", s[i].nama, s[i].nim, s[i].umur);
    }
}

int main(){
    
    dm data[3] = {{"budi", "!@121", 17}, {"arya", "asdad", 10}, {"ferdi", "asdasda", 20}};
    passStruct(data, 3);
    // dm data;
    // strcpy(data.nama,"day");
    // strcpy(data.nim,"2602064565");
    // data.umur = 18;
    // printf("%s %s %d\n", data.nama, data.nim, data.umur);


    ds lili = {"lili"};
    printf("%s %d\n", lili.nama, lili.umur);
    ds jojo = {"jojo"};
    printf("%s %d\n", jojo.nama, jojo.umur);
    printf("%s %d\n", lili.nama, lili.umur);

    return 0;
}   

/*
STRUCT VS UNION
secara cara deklarasi dan initialisasi sama
perbedaan terletak di memory yang digunakan
setiap struct memiliki memory tersendiri
sedangkan union memili memory yang sama
untuk setiap variablenya, maka memberi 
value pada 1 variable akan mengakibatkan
variable lain memiliki value yang sama.
*/