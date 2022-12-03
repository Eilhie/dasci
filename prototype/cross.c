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
				matrix[i + 1][j + 1] -= dmg;
				matrix[i + 1][j - 1] -= dmg;
				matrix[i - 1][j + 1] -= dmg;
				matrix[i - 1][j - 1] -= dmg;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}

	return 0;
}
