#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool found;
char den[6];
bool t[11];

bool isValid(int num){
	while(num > 0){
		int mod = num % 10;
		if (t[mod]) return false;
		t[mod] = true;
		num /= 10;
	}
	return true;
}

void check_taken(){
	for (int i = 0; i < 10; i++){
		printf("%d: %d - ",i ,t[i]);
	}
	printf("\n");
}

void divisions(int N, int p){
	if (p == 5){
		printf("den = %s\n", den);
		int numerator = N * atoi(den);
		if (isValid(numerator)){
			printf("%d / %s = %d\n", numerator, den, N);
			found = true;
		}
		return;
	}

	for (int i = 0; i < 10; i++){
		printf("depth = %d, i = %d\n", p, i);
		//check_taken();
		if (t[i]) continue;
		t[i] = true;
		den[p] = '0' + i;
		divisions(N, p + 1);
		t[i] = false;
	}
}

void init(){
	for (int i = 0; i < 11; i++)
		t[i] = false;
}

int main(){
	int n;
	den[5] = '\0';
	while(scanf("%d", &n) && n){
		memset(den, '#', 5);
		init();
		found = false;
		divisions(n, 0);
		if (!found) printf("There are no solutions of %d.\n", n);
		printf("\n");
	}
	return 0;
}