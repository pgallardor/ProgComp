#include <cstdio>

int A, B, C;

bool solve(int x, int y, int z){
	if (x*y*z == B && x*x + y*y + z*z == C && x + y + z == A)
		return true;

	return false;
}

void search(){
	for(int y = -100; y <= 100; y++){
		for (int x = -100; x <= 100; x++){
			for(int z = -100; z <= 100; z++){
				if (x != y && y != z && x != z && solve(y,x,z)){ 
					printf("%d %d %d\n", y, x, z);
					return;
				}
			}
		}
	}
	printf("No solution.\n");
}

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		scanf("%d %d %d", &A, &B, &C);
		search();
	}

	return 0;
}