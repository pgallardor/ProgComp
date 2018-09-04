#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int books[10005];

void solve(int N, int M){
	int x = -1, y = -1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i == j) continue;
			if ((x == -1 || (y - x) > abs(books[i] - books[j])) && books[i] + books[j] == M){
				x = min(books[i], books[j]);
				y = max(books[i], books[j]);
			}
		}
	}
	printf("Peter should buy books whose prices are %d and %d.\n\n", x, y);
}

int main(){
	int n, m;
	while(scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++){
			scanf("%d", &books[i]);
		}
		scanf("%d", &m);
		solve(n, m);
	}
	return 0;
}