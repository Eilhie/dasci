#include<stdio.h>

int binary_search(int arr[],int n,int k)
{
    int ind=-2; 
    int l=0,r=n-1,m;

    while(l<=r)
    {
        m=(l+r)/2;
        if(arr[m]<k)
            l=m+1; 
        else
        {
            if(arr[m]==k)
                ind=m; 
            r=m-1; 
        }
    }
    return ind+1; 
}

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int A[x],B[y];
    for(int i=0;i<x;i++)
        scanf("%d",&A[i]);

    for(int i=0;i<y;i++)
        scanf("%d",&B[i]);

    for(int i=0;i<y;i++)
    {
        int f = binary_search(A,x,B[i]);
        printf("%d\n",f); 
    }

}