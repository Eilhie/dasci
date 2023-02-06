#include<stdio.h>
int main()
{
	FILE *data;
	data = fopen("testdata.in","r");
    int Case;
    int area, time;
    fscanf(data,"%d",&Case);
    for(int i=1;i<=Case;i++)
    {
        fscanf(data,"%d %d",&area,&time);
        fscanf(data,"\n");
        char grass;
        int x,y;
        for(int j=0;j<area;j++)
        {
            for(int k=0;k<area;k++)
            {
                fscanf(data,"%c",&grass);
                if(grass=='F')
                {
                    x = k; 
                    y = j; 
                }
            }
            fscanf(data,"\n");
        }
        printf("Case #%d:\n",i);
        for(int j=0;j<area;j++)
        {
            for(int k=0;k<area;k++)
            {
                if(k<x+time && k>x-time && j<y+time && j>y-time)
                {
                    printf("F");
                }

                else printf("#");

            }
            printf("\n");
        }
        printf("\n");
    }
    
    fclose(data);
    return 0;
}