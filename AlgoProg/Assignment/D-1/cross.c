#include <stdio.h>

int main() {
	
	int max = 0;
	int n, dmg;
	scanf("%d %d", &n, &dmg);
	int matrix[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &matrix[i][j]);
			if(matrix[i][j] > max)
				max = matrix[i][j];
		}
	}
	puts("");
	
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == max){
				matrix[i][j] -= dmg*dmg;
				if(i - 1 >= 0 && j + 1
				 < n)
					matrix[i - 1][j + 1] -= dmg;
				if(i  - 1 >= 0 && j - 1 >= 0)
					matrix[i - 1][j - 1] -= dmg;
				if(i + 1 < n && j + 1 < n)
					matrix[i + 1][j + 1] -= dmg;
				if(i + 1 < n && j - 1 >= 0)
					matrix[i + 1][j - 1] -= dmg;
				
				
				max = -999999;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] < 0)
				matrix[i][j] = 0;
			
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}

	return 0;
} 