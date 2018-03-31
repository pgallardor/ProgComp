#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

long max, min; 

long decode(int bitset, int L){
	char nmb[20];
	for (int i = 0; i < L; i++){
		if (bitset & (1 << i)) nmb[i] = '2';
		else nmb[i] = '1';
	}
	nmb[L] = '\0';
	return atol(nmb);
}

void solve(int L, int div){
	int sets = 1 << L;
	for (int i = 0; i < sets; i++){
		long nmb = decode(i, L), nd = 1 << div;
		if (nmb % nd == 0){
			if (min == -1) min = nmb;
			else max = nmb;
		}
	}
}

int main(){
	int T, l, d;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%d %d", &l, &d);
		max = -1, min = -1;
		solve(l, d);
		printf("Case %d: ", i + 1);
		if (min == -1) printf("impossible\n");
		else if (max == -1) printf("%ld\n", min);
		else printf("%ld %ld\n", min, max);
	}

	return 0;
}