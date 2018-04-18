#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int T, numbers[50];
bool found;
map<vector<int>, bool> all_seqs;

void backtrack(int total, vector<int> seq, int nn, int idx){
	if (total > T || idx > nn)
		return;

	if (total == T){
		if (all_seqs[seq]) return;
		bool first = true;
		printf("%d", seq[0]);
		for(int i = 1; i < seq.size(); i++){
			printf("+%d", seq[i]);
		}
		printf("\n");
		found = true;
		all_seqs[seq] = true;
	}

	for (int i = idx; i < nn; i++){
		seq.push_back(numbers[i]);
		backtrack(total + numbers[i], seq, nn, i + 1);
		seq.pop_back();
	}

}

int main(){
	int n;
	while(scanf("%d %d", &T, &n) != EOF && n){
		for (int i = 0; i < n; i++){
			scanf("%d", &numbers[i]);
		}
		found = false;
		printf("Sums of %d:\n", T);
		backtrack(0, vector<int>(), n, 0);
		if (!found) printf("NONE\n");
		all_seqs.clear();
	}
	return 0;
}