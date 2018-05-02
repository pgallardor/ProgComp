#include <cstdio>
#include <vector>
#include <cstring>
#define NO_COLOR 0
#define BLACK -1
#define WHITE 1
using namespace std;

vector<vector<int> > graph;
vector<int> vsol;
int w;

void coloring(int V, int idx, int color[110], int wh){
	if (idx > V){
		if (wh <= w){
			w = wh;
			vsol.clear();
			vsol = vector<int>(color, color + V + 1);
		}
		return;
	}

	if (wh > w)
		return;

	bool can_black = true;

	for (int i = 0; i < graph[idx].size(); i++){
		if (color[graph[idx][i]] == BLACK){
			can_black = false;
			break;
		}
	}

	if (can_black){
		color[idx] = BLACK;
		coloring(V, idx + 1, color, wh);
	}

	color[idx] = WHITE;
	coloring(V, idx + 1, color, wh + 1);
}

void show_blacks(int V){
	bool first = true;
	for (int i = 1; i <= V; i++){
		if (vsol[i] == BLACK){
			if (!first) printf(" ");
			else first = false; 
			printf("%d", i);
		}
	}
	printf("\n"); 
} 

int main(){
	int T, v, e, n1, n2;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &v, &e);
		graph = vector<vector<int> >(v + 1);
		for (int i = 0; i < e; i++){
			scanf("%d %d", &n1, &n2);
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}

		int color[110];
		memset(color, NO_COLOR, sizeof(int)*110);
		w = 100;
		coloring(v, 1, color, 0);

		printf("%d\n", v - w);
		show_blacks(v);
	}

	return 0;
}