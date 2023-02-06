#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    int arr[t][t];
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int count = 0;
    for(int k=0;k<t;k++){
    for(int i=0;i<t-1;i++){
        for(int j=i+1;j<t;j++){
            if(arr[k][i] == arr[k][j]){
                count++;
                break;
            }
        }
    }
    }
    if(count == 0){
    for(int k=0;k<t;k++){
    for(int i=0;i<t-1;i++){
        for(int j=i+1;j<t;j++){
            if(arr[i][k] == arr[j][k]){
                count++;
                break;
            }
            else if(arr[i][k]>t || arr[j][k]>t){
                count++;
                break;
                }
            }
        }
    }
    }
    if(count>0)
        printf("Nay\n");
    else{
        printf("Yay\n");
    }
}
