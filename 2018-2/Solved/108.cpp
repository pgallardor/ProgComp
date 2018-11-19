#include <cstdio>
#include <iostream>

int mat[105][105], sum[105][105];

int solve(int N){
	int sol = -127*100*100;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = i; k < N; k++){
				for (int l = j; l < N; l++){
					int tmp = sum[k][l];
					if (i > 0) tmp -= sum[i - 1][l];
					if (j > 0) tmp -= sum[k][j - 1];
					if (i > 0 && j > 0) tmp += sum[i - 1][j - 1];
					sol = std::max(sol, tmp);
				}
			}
		}
	}
	return sol;
}

int main(){
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &mat[i][j]);
			sum[i][j] = mat[i][j];
			if (i > 0) sum[i][j] += sum[i - 1][j];
			if (j > 0) sum[i][j] += sum[i][j - 1];
			if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];  
		}
	}

	printf("%d\n", solve(N));
	return 0;
}