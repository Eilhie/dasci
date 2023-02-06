#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    char name[69];
    int nomor;
};
int main(){
    data datadata[4646];
    FILE *fp = fopen("testdata.in", "r");
    int n;
    fscanf(fp,"%d", &n); 
    int i = 0;
    while(!feof(fp)){
        fscanf(fp, "%d#%[^\n]", &datadata[i].nomor, datadata[i].name);
        i++;
    }
      
    for(int k = 0; k < n-1; k++){
       for (int j = 0; j < n-k-1; j++){
               if(strcmp(datadata[j].name, datadata[j+1].name) > 0){
                   data temp = datadata[j];
                   datadata[j] = datadata[j+1];
                   datadata[j+1] = temp; 
            }
        }
    }
    
    for(int j = 0; j < n; j++){
        printf("%d %s\n", datadata[j].nomor, datadata[j].name);
    }
    return 0;
}