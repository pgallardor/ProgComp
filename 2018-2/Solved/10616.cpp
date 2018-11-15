#include <cstdlib>
#include <cstdio>

typedef long long lli;

int table[205][25][15], nums[205];
int N, D, M;

void init(){
	for (int i = 0; i < 205; i++){
		for (int j = 0; j < 25; j++){
			for (int k = 0; k < 15; k++) table[i][j][k] = -1;
		}
	}
}

int dp(int i, int j, int k){
	if ((i == N && k) || (!k && j)) return 0;
	if (!k && !j) return 1;

	if (table[i][j][k] != -1) return table[i][j][k];

	table[i][j][k] = dp(i + 1, (j + (nums[i])%D + D)%D, k - 1) + dp(i + 1, j, k);
	return table[i][j][k];
}

int main(){
	int Q, cas = 1;
	while(scanf("%d %d", &N, &Q) != EOF && (N || Q)){
		for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
		printf("SET %d:\n", cas++);
		for (int i = 0; i < Q; i++){
			init();
			scanf("%d %d", &D, &M);
			printf("QUERY %d: %d\n", i + 1, dp(0, 0, M));
		}	
	}
	return 0;
}

