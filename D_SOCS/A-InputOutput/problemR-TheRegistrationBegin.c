#include <stdio.h>

int main(){

    char ID[10], nama[100], kelas[2];
    int nomor;

    scanf ("%s\n", ID);
    scanf ("%[^\n]", nama);
    scanf ("%s %d", kelas ,&nomor);

    printf ("Id    : %s\n", ID);
    printf ("Name  : %s\n", nama);
    printf ("Class : %s\n", kelas);
    printf ("Num   : %d\n", nomor);

    return 0;
}
// #include <stdio.h>
// int main(){
//   char name[100],cls[2],id[10];
//   int num;
//   scanf("%s\n",id); 
//   scanf("%[^\n]",name);
//   scanf("%s %d",cls,&num);
//   printf("Id    : %s\n",id);
//   printf("Name  : %s\n",name);
//   printf("Class : %s\n",cls);
//   printf("Num   : %d\n",num);
//   return 0;
// }
