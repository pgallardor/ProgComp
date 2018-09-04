#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

char field[105];

int recursive_positioning(int N, int pos){
	if (N <= pos)
		return 0;

	while (field[pos] == '#' && N > pos) pos++;

	if (N <= pos)
		return 0;

	if (pos + 1 < N){
		if (field[pos + 1] == '.')
			return 1 + recursive_positioning(N, pos + 3);

		else return 1 + min(recursive_positioning(N, pos + 2), recursive_positioning(N, pos + 3));
	}

	return 1;		
}

int main(){
	int T, n;
	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		scanf("%d", &n);
		scanf("%s", field);
		int res = recursive_positioning(n, 0);

		printf("Case %d: %d\n", i + 1, res);
	}

	return 0;
}