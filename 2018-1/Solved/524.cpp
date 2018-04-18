#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

map<vector<int>, bool> solutions;
//vector<vector<int> > solutions;
vector<int> primes;

void prime_init(){
	int arr[] = {2,3,5,7,11,13,17,19,23,29,31};
	primes = vector<int>(arr, arr + 11);
}

bool is_prime(int n){
	for (int i = 0; i < primes.size(); i++){
		if (primes[i] == n) return true;
	}
	return false;
}

void init(int *v, int N){
	memset(v + 2, -1, sizeof(int)*(N));
}

void backtrack(int *numbs, int idx, int last, int N){
	if (idx >= N && is_prime(last + 1)){
		vector<int> ins(N);
		for (int i = 1; i <= N; i++){
			ins[numbs[i]] = i;
		}
		solutions[ins] = true;
		//solutions.push_back(ins);
		return;
	}

	//for (int i = 1; i <= N; i++) printf("%d ", numbs[i]);
	//printf("\n");	

	for (int i = 2; i <= N; i++){
		if (numbs[i] == -1 && is_prime(i + last)){
			numbs[i] = idx;
			backtrack(numbs, idx + 1, i, N);
			numbs[i] = -1;
		}
	}
}

void show_vector(vector<int> v){
	printf("%d", v[0]);
	for (int i = 1; i < v.size(); i++){
		printf(" %d", v[i]);
	}
	printf("\n");
}

int main(){
	int n, cnt = 1, first = 1;
	prime_init();
	while(scanf("%d", &n) != EOF){
		int sol[20];
		sol[1] = 0;
		init(sol, n - 1);

		if (!first) printf("\n");

		backtrack(sol, 1, 1, n);
		printf("Case %d:\n", cnt++);
		map<vector<int>, bool>::iterator it;
		for(it = solutions.begin(); it != solutions.end(); ++it){
			vector<int> s = it->first;
			show_vector(s);
		}
		/*for (int i = 0; i < solutions.size(); i++){
			show_vector(solutions[i]);
		}*/
		solutions.clear();
		first = 0;
	}
	return 0;
}