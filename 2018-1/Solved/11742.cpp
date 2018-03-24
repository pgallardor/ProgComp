#include <algorithm>
#include <cstdio>
using namespace std;

int constr[25][3], pple[10];

void init(){
	for (int i = 0; i < 8; i++)
		pple[i] = i;
}

bool satisfy(int N, int C){
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			for (int k = 0; k < C; k++){
				if (pple[i] == constr[k][0] && pple[j] == constr[k][1] || pple[i] == constr[k][1] && pple[j] == constr[k][0]){
					if (constr[k][2] < 0 && j - i < -constr[k][2] || constr[k][2] > 0 && j - i > constr[k][2]) return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) && (n || m)){
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &constr[i][0], &constr[i][1], &constr[i][2]);
		}

		init();
		int cnt = 0;
		do{
			cnt += (int)satisfy(n, m);
		}while(next_permutation(pple, pple + n));

		printf("%d\n", cnt);
	}
	return 0;
}