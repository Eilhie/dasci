#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void swapNum(long int *num1,long int *num2)
{
    long long int tmpNum= *num1;
    *num1= *num2;
    *num2= tmpNum;
}

void swap(char **str,char **mystr){
    char *temp = *str;
    *str = *mystr;
    *mystr = temp;

}


int main()
{    
    FILE *fp;
    fp = fopen("testdata.in","r");
    int testcase;
    fscanf(fp,"%d\n",&testcase);
//    scanf("%d",&testcase);
    long int angka[1010];
    char *plants[1010];
    char temp[1010];
    int i;
    for(i=0;i<testcase;i++){
        fscanf(fp,"%ld#%[^\n]\n",&angka[i],temp);
//        scanf("%ld#%[^\n]",&angka[i],temp);
//        getchar();        
        plants[i] = malloc(strlen(temp)*sizeof(char*));
        strcpy(plants[i],temp);
    }
    fclose(fp);
    int j;
    int count = testcase;
    for(i=0;i<count-1;i++){
        for(j=0;j<count-i-1;j++){
                if(strcmp(plants[j],plants[j+1])>0){
                    swap(plants+j,plants+j+1);
                    swapNum(&angka[j],&angka[j+1]);
            }
        }
    }
    
    for(i=0;i<testcase;i++){
        printf("%ld %s\n",angka[i],plants[i]);
    }
    
    return 0;
}