#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool found;

bool isValid(int num, bool t[]){
	if (num < 10000 || num > 99999) return false;
	int res = num;
	bool lt[11] = {false};
	while(res > 0){
		int mod = res%10;
		if (t[mod] || lt[mod]) return false;
		lt[mod] = true;
		res /= 10;
	}
	return true;
}

void solve(int N, char den[], bool t[], int p){
	if (p == 5){
		int num = N * atoi(den);
		if (isValid(num, t)){
			found = true;
			printf("%d / %s = %d\n", num, den, N);
		}
		return;
	}

	for (int i = 0; i < 10; i++){
		if (t[i]) continue;
		t[i] = true;
		den[p] = '0' + i;
		solve(N, den, t, p + 1);
		t[i] = false;
	}
}

int main(){
	bool used[15], first = true;
	char den[10];
	den[5] = '\0';
	int n;

	while(scanf("%d", &n) && n){
		if (!first) printf("\n");
		else first = false;

		for (int i = 0; i < 10; i++) used[i] = false;
		found = false;
		solve(n, den, used, 0);

		if (!found) printf("There are no solutions for %d.\n", n);
	}

	return 0;
}