#include <cstdio>

int nums[20005];

void solve(int N, int r){
	int tmp_i = 1, si, sj = -1, sum = 0, sol = 0;

	for (int i = 0; i < N; i++){
		sum += nums[i];
		if (sum > sol || (sum == sol && (i + 1 - tmp_i + 1) > (sj - si))){
			si = tmp_i;
			sj = i + 2;
			sol = sum;
		}

		if (sum < 0){
			tmp_i = i + 2;
			sum = 0;
		}
	}

	if (sj == -1) {printf("Route %d has no nice parts\n", r); return;}
	printf("The nicest part of route %d is between stops %d and %d\n", r, si, sj);
}

int main(){
	int T, N;
	scanf("%d", &T);
	for (int r = 0; r < T; r++){
		scanf("%d", &N);
		N--;
		for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
		solve(N, r + 1);	
	}

	return 0;
}