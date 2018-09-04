#include <cstdio>
#include <vector>
#include <cstring>
#define NO_COLOR 0
#define BLACK -1
#define WHITE 1
using namespace std;

vector<vector<int> > list;
vector<int> s_color;
bool dfs_visited[110];
int w;

void dfs(int v, vector<int> &cmp){
	if (dfs_visited[v])
		return;

	dfs_visited[v] = true;
	cmp.push_back(v);

	for (int i = 0; i < list[v].size(); i++){
		dfs(list[v][i], cmp);
	}

}

void print_list(int V){
	for (int i = 1; i <= V; i++){
		printf("%d -> ", i);
		for (int j = 0; j < list[i].size(); j++){
			printf("%d ", list[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void backtrack(vector<int> &cmp, int idx, vector<int> color, int act_wh){
	if (idx >= cmp.size()){
	 	if(act_wh < w){
			w = act_wh;
			s_color = vector<int>(color);
		}
		return;
	}

	if (act_wh > w)
		return;

	bool can_black = true;

	for (int i = 0; i < list[cmp[idx]].size(); i++){
		if (color[list[cmp[idx]][i]] == BLACK)
			can_black = false;
	}

	if (can_black){
		color[cmp[idx]] = BLACK;
		backtrack(cmp, idx + 1, color, act_wh);
	}

	color[cmp[idx]] = WHITE;
	backtrack(cmp, idx + 1, color, act_wh + 1);

}

void show_blacks(int V){
	bool space = false;
	for (int i = 1; i <= V; i++){
		if (s_color[i] == BLACK){
			if (space) printf(" ");
			else space = true; 
			printf("%d", i);
		}
	}
	printf("\n");
}

int main(){
	int T, V, E, n1, n2;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &V, &E);
		list = vector<vector<int> >(V + 1);
		for (int i = 0; i < E; i++){
			scanf("%d %d", &n1, &n2);
			list[n1].push_back(n2);
			list[n2].push_back(n1);
		}

		//print_list(V);
		memset(dfs_visited, false, 110);
		s_color = vector<int>(110, NO_COLOR);

		vector<int> config;
		int sol_w = 0;
	
		for (int i = 1; i <= V; i++){
			if (dfs_visited[i]) continue;

			w = 100;
			config = vector<int>(s_color);
			vector<int> comp;
			dfs(i, comp);
		
			backtrack(comp, 0, config, 0);
			sol_w += w;
		}

		printf("%d\n", V - sol_w);
		show_blacks(V);
	}
	return 0;
}
