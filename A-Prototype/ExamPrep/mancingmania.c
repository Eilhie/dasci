
// #include <stdio.h>

// int main(){

//     int testCases;
//     scanf("%d", &testCases);
//     for(int i = 0; i < testCases; i++){
//         int type, weight, distance, fishv, fspd, dur;
//         int turn = 0; // 0 itu pemancing 1 itu ikan
//         int sec = 0;
//         scanf("%d %d %d %d %d %d", &type, &weight ,&distance, &fishv, &fspd, &dur);
//         if((type == 1 && weight <= 450) || (type == 2 && weight <= 900) || (type == 3 && weight <= 1320) || (type == 4 && weight <= 3200) || (type == 5 && weight <= 4500)){
//             //printf("TALI AMAN\n");

//             while(fspd > 0){
//                 sec++;
//                 if(sec % dur == 0 && turn == 0) turn = 1;
//                 else turn = 0;
                
//                 if(distance < 0) {
//                     //printf("%d\n", distance);
//                     printf("%d\n", sec);
//                     break;
//                 }
//                 if(turn == 1){
//                     distance = distance + fspd;
//                     printf("turn %d %d sec %d\n", turn ,distance, sec);
//                 }else {
//                     distance = distance - 5;
//                     printf("turn %d %d sec %d\n", turn ,distance, sec);
//                 }
//             }
//         } else printf("Case #%d: Line broke up\n", i + 1);

        
//     }

//     return 0;

// } 

#include<stdio.h>
#include<stdlib.h>

int compareint(const void *pa,const void *pb){
    const int *s1 = pa;
    const int *s2 = pb;
    return *s2-*s1;
}

int main(){
	int i;
    int nums[] = {9,-20,1,0,18,200};
    int n = sizeof(nums)/sizeof(int);
    qsort(nums,n,sizeof(int),compareint);
    for(i=0;i<n;i++){
        printf("%d ",nums[i]);
    }
    puts("");
}
