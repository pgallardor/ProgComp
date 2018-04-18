#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > solutions;

bool can_capture(int conf[8]){
	for (int i = 0; i < 7; i++){
		for (int j = i + 1; j < 8; j++){
			if (conf[i] == conf[j] || conf[j] == conf[i] + (j - i) || conf[j] == conf[i] - (j - i))
				return true;
		}
	}
	return false;
}

void generate(){
	int gen[8] = {1,2,3,4,5,6,7,8};

	do{
		if (!can_capture(gen)){
			vector<int> sol(gen, gen + 8);
			solutions.push_back(sol);
		} 
	}while(next_permutation(gen, gen + 8));
}

int look_solution(int conf[8]){
	int best = 8, cnt;

	for (int i = 0; i < solutions.size(); i++){
		cnt = 0;
		for (int j = 0; j < 8; j++){
			if (conf[j] != solutions[i][j]) cnt++;
		}

		if (best > cnt)
			best = cnt;
	}

	return best;
}

int main(){
	int cas[8], cnt = 1;
	generate();
	while(scanf("%d", &cas[0]) != EOF){
		for (int i = 1; i < 8; i++)
			scanf("%d", &cas[i]);
		
		printf("Case %d: %d\n", cnt++, look_solution(cas));
	}
	return 0;
}