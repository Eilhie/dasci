#include <stdio.h>
int main(){
  char name[100],nis[100];
  int age;
  scanf("%[^\n]",name);
  scanf("%s %d",nis,&age);
  printf("Name: %s\n",name);
  printf("NIS: %s\n",nis);
  printf("Age: %d\n",age);
  return 0;
}