#include <stdio.h>
#include <math.h>

int issquare(int a){
    int iVar;
    float fVar = sqrt(a);
    iVar = fVar;
    if(iVar==fVar)
        return 1;
    else
        return 0;
}

int iscube(int N)
{
    int cube_root;
    cube_root = (int)round(pow(N, 1.0 / 3.0));
  
    if (cube_root * cube_root * cube_root == N) {
        return 1;
    }
    else    
        return 0;
}

int isprime(int n){
    int flag = 0;
    if (n == 0 || n == 1)
        flag = 1;

    for (int i = 2; i <= n / 2; ++i) {

        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

  if (flag == 0)
    return 1;
    else    
        return 0;

}

int main(){

    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        long int nums;
        scanf("%ld", &nums);
        printf("Case #%d :", i + 1);
        if(issquare(nums) == 0 && iscube(nums) == 0 && isprime(nums) == 0)
            printf(" none");

        if(issquare(nums))
            printf(" square");
        
        if(iscube(nums))
            printf(" cubic");
    
        if(isprime(nums))
            printf(" prime");
        
        
        printf("\n");
    }

    return 0;
}