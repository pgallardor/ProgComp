#include <cstdio>
#include <vector>
using namespace std;

int tracks[30], best_diff, N;
vector<int> solution;


void backtrack(int tr, int total, vector<int> seq, int idx){
	if (idx > tr || total > N)
		return;

	int diff = N - total;
	if (best_diff > diff){
		solution = vector<int>(seq);
		best_diff = diff;
	}

	for (int i = idx; i < tr; i++){
		seq.push_back(tracks[i]);
		backtrack(tr, total + tracks[i], seq, i + 1);
		seq.pop_back();
	}
}

int main(){
	int t;
	while(scanf("%d", &N) != EOF){
		scanf("%d", &t);
		for (int i = 0; i < t; i++){
			scanf("%d", &tracks[i]);
		}
		best_diff = 1 << 29;
		backtrack(t, 0, vector<int>(), 0);
	
		for (int i = 0; i < solution.size(); i++){
			printf("%d ", solution[i]);
		}
		printf("sum:%d\n", N - best_diff);
	}
}