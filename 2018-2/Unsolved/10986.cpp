#include <queue>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

vector<vector<ii> > adj;

int dijkstra(int N, int s, int t){
	priority_queue<ii> pq;

	vector<int> dist(N, -1);
	pq.push(ii(0, s));
	dist[s] = 0;

	while(!pq.empty()){
		ii act = pq.top(); pq.pop();
		int d = -act.first, v = act.second;

		if (v == t) return dist[t];

		for (int i = 0; i < adj[v].size(); i++){
			int dis = adj[v][i].second, u = adj[v][i].first;
			if (dist[u] == -1 || dist[u] > dis + d){
				dist[u] = dis + d;
				pq.push(ii(-dist[u], u));
			}
		}
	}

	return -1;
}

int main(){
	int T, N, M, s, t;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%d %d %d %d", &N, &M, &s, &t);
		adj = vector<vector<ii> >(N);
		for (int j = 0; j < M; j++){
			int u, v, d;
			scanf("%d %d %d", &u, &v, &d);
			adj[u].push_back(ii(v, d));
			adj[v].push_back(ii(u, d));
		}

		int dist = dijkstra(N, s, t);
		printf("Case #%d: ", i+1);
		if (dist == -1) printf("unreachable\n");
		else printf("%d\n", dist);
	}
	return 0;
}