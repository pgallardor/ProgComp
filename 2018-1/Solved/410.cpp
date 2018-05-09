#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;

void solve(int n_set, vector<ii> v, int C, double AM){

	for (int i = v.size(); i < 2*C; i++){
		v.push_back(ii(0, i));
	}

	int S = v.size();
	sort(v.begin(), v.end());

	vector<vector<int> > ch(C);

	double imbalance = 0.0f;
	int n_ch = 0;

	for (int idx = 0; idx < S; idx++){
		for (int i = 0; i < S/2; i++){
			
			if (v[i].second == idx || v[S-i-1].second == idx){
				vector<int> act;

				if (v[i].second < v[S-i-1].second){
					act.push_back(v[i].first);
					act.push_back(v[S-i-1].first);
				}

				else{
					act.push_back(v[S-i-1].first);
					act.push_back(v[i].first);
				}

				v[i].second = v[S-i-1].second = -1;

				imbalance += fabs(v[i].first + v[S-i-1].first - AM);
				ch[n_ch++] = vector<int>(act);
			}
		}
	}

	printf("Set #%d\n", n_set);
	for (int i = 0; i < C; i++){
		printf(" %d:", i);
		for (int j = 0; j < ch[i].size(); j++){
			if (ch[i][j] > 0)
				printf(" %d", ch[i][j]);
		}
		printf("\n");
	}
	printf("IMBALANCE = %.5f\n", imbalance);
}

int main(){
	int C, S, sp, t = 1;

	while(scanf("%d %d", &C, &S) != EOF){
		vector<ii> sorted;
		double sm = 0.0f;

		for(int i = 0; i < S; i++){
			scanf("%d", &sp);
			sm += (double)sp;
			sorted.push_back(ii(sp, i));
		}

		solve(t++, sorted, C, (double)sm/C);
		printf("\n");
	}
}