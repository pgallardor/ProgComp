#include <cstdio>
using namespace std;

int bars[100];

bool search(int L, int N){
	int set_q = 1 << N;
	for (int i = 0; i < set_q; i++){
		int cnt = 0;
		for (int j = 0; j < N; j++){
			if (i & (1 << j)) cnt += bars[j];
		}

		if (cnt == L) return true;
	}
	return false;
}

int main(){
	int T, n, l;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &l, &n);
		for (int i = 0; i < n; i++){
			scanf("%d", &bars[i]);
		}

		if (search(l, n)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
