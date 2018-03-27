#include <cstdio>
#include <cstring>
#define ROW 0
#define COLUMN 1
using namespace std;

int grid[10][10], sol;

void search(bool used[2][10], int total, int n, int rounds){
	if (rounds == n){
		if (sol > total)
			max = total;
		return;
	}

	for (int i = 0; i < n; i++){
		if (used[ROW][i]) 
			continue;

		int min, idx = 0;
		bool valid = false;
		for (int j = 0; j < n; j++){
			if (used[COLUMN][j])
				continue;

			if (!valid || (valid && min > grid[i][j])){
				min = grid[i][j];
				idx = j;
				if (!valid) valid = true;
			}
		}
		used[ROW][i] = used[COLUMN][idx] = true;
		search(used, total + min, n, rounds + 1);
		used[ROW][i] = used[COLUMN][idx] = false;
	}
}

int main(){
	int T, n;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				scanf("%d", &grid[i][j]);
			}
		}
		bool used[2][10];
		memset(used, false, sizeof(bool)*2*10);

		max = 9999999;
		search(used, 0, n, 0);
		printf("%d\n", sol);
	}
	return 0;
}