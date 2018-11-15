#include <cstdio>

int memo[6][7500];
int coins[] = {50, 25, 10, 5, 1};

void init(){
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 7500; j++) memo[i][j] = -1;
	}
}

int dp(int idx, int val){
	if (val < 0 || idx == 5) return 0;
	if (val == 0) return 1;

	if (memo[idx][val] != -1) return memo[idx][val];

	return memo[idx][val] = dp(idx + 1, val) + dp(idx, val - coins[idx]);
}

int main(){
	int N;
	init();
	while (scanf("%d", &N) != EOF){
		printf("%d\n", dp(0, N));
	}

	return 0;
}