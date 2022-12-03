#include <stdio.h>
#include <stdlib.h>

int dp[8][8] = { 0 };

int min(int a, int b){
    if(a<=b){	
        return a;
    } 	
    return b; 
}  
int getsteps(int x, int y, int tx, int ty){
	if (x == tx && y == ty)
		return dp[0][0];
	else {
		if (dp[abs(x - tx)][abs(y - ty)] != 0)
			return dp[abs(x - tx)][abs(y - ty)];
			
		else {

			int x1, y1, x2, y2;

			if (x <= tx) {
				if (y <= ty) {
					x1 = x + 2;
					y1 = y + 1;
					x2 = x + 1;
					y2 = y + 2;
				} else {
					x1 = x + 2;
					y1 = y - 1;
					x2 = x + 1;
					y2 = y - 2;
				}
			} else {
				if (y <= ty) {
					x1 = x - 2;
					y1 = y + 1;
					x2 = x - 1;
					y2 = y + 2;
				} else {
					x1 = x - 2;
					y1 = y - 1;
					x2 = x - 1;
					y2 = y - 2;
				}
			}
			dp[abs(x - tx)][abs(y - ty)] = min(getsteps(x1, y1, tx, ty),getsteps(x2, y2, tx, ty)) + 1;

			dp[abs(y - ty)][abs(x - tx)] = dp[abs(x - tx)][abs(y - ty)];
			return dp[abs(x - tx)][abs(y - ty)];
		}
	}
}

int main()
{
	int i, n, x, y, tx, ty, ans;

	n = 8;

	int T;
	scanf(" %d", &T);
	for(int j=0; j<T; j++){
		char cx, cx1;
        int maxcount;
        scanf("%d", &maxcount); getchar();
        scanf(" %c%d %c%d", &cx, &y, &cx1, &ty);
        x = cx - 64; 
		tx = cx1 - 64; 	

		if ((x == 1 && y == 1 && tx == 2 && ty == 2) || (x == 2 && y == 2 && tx == 1 && ty == 1))
				ans = 4;
		else if ((x == 1 && y == n && tx == 2 && ty == n - 1) || (x == 2 && y == n - 1 && tx == 1 && ty == n))
					ans = 4;
		else if ((x == n && y == 1 && tx == n - 1 && ty == 2) || (x == n - 1 && y == 2 && tx == n && ty == 1))
					ans = 4;
		else if ((x == n && y == n && tx == n - 1 && ty == n - 1) || (x == n - 1 && y == n - 1 && tx == n && ty == n))
					ans = 4;
		else {
			dp[1][0] = 3;
			dp[0][1] = 3;
			dp[1][1] = 2;
			dp[2][0] = 2;
			dp[0][2] = 2;
			dp[2][1] = 1;
			dp[1][2] = 1;

			ans = getsteps(x, y, tx, ty);
		}
		if((ans/2) > maxcount)
		    printf("Case #%d: NO\n",j+1); 
        else
            printf("Case #%d: YES\n",j+1); 
	}   

	return 0;
}