#include <cstdio>
#include <cstdlib>
using namespace std;

int arr[50];

void show(int n){
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			for (int k = j + 1; k < n; k++){
				for (int l = k + 1; l < n; l++){
					for (int x = l + 1; x < n; x++){
						for (int y = x + 1; y < n; y++){
							printf("%d %d %d %d %d %d\n", arr[i], arr[j], arr[k], arr[l], arr[x], arr[y]);
						}
					}
				}
			}
		}
	}
}

int main(){
	int N;
	bool first = true;
	while(scanf("%d", &N) && N){
		if (first) first = false;
		else printf("\n");
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		show(N);
	}
	return 0;
}