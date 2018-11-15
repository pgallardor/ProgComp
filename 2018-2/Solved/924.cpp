#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adj;

int db, maxb;

void BFS(int N, int s){
	int cnt = 0, day = 1;
	vector<int> visited(N, -1);
	queue<int> q;
	visited[s] = 1;
	q.push(s);

	while (!q.empty()){
		int v = q.front(); q.pop();
		
		if (visited[v] > day){
			if (cnt > 0 && cnt > maxb){
				maxb = cnt;
				db = day;
			}
			day++;
			cnt = 0;
		}

		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if (visited[u] == -1){
				visited[u] = visited[v] + 1;
				cnt++;
				q.push(u);
			}
		}
	}
}

int main(){
	int E, src, n, fi;
	scanf("%d", &E);
	adj = vector<vector<int> >(E + 1);
	for (int i = 0; i < E; i++){
		scanf("%d", &n);
		for (int j = 0; j < n; j++){
			scanf("%d", &fi);
			adj[i].push_back(fi);
			//adj[fi].push_back(i);
		}
	}
	scanf("%d", &n);
	for (int j = 0; j < n; j++){
		scanf("%d", &src);
		db = maxb = -1;
		BFS(E, src);
		if (maxb == -1) printf("0\n");
		else printf("%d %d\n", maxb, db);		
	}
	return 0;
}