#include <stdio.h>

int main(){
	int line, totalnum, num[101], binary[51][2] = {0}, x, y;
	scanf("%d", &line);
	for(int i=0; i<line; i++){
		scanf("%d", &totalnum);
		for(int j=0; j<totalnum; j++){
			scanf("%d", &num[j]);
		}	
		for(int k=0; k<totalnum-1; k++){
			for(int l=k+1; l<totalnum; l++){
				y=num[k] ^ num[l];
				x=0;
				while(y != 0){
					x += y & 1;
					y >>= 1;
				}
				if(x >= 3){
					binary[i][1]++;
				}
				else{
					binary[i][0]++;
				}
			}
		}
	}
	for(int i=0; i<line; i++){
		printf("Case #%d: %d %d\n", i+1, binary[i][1], binary[i][0]);
	}
	return 0;
}
