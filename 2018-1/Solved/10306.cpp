#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

#define INF 1 << 29
#define UNSET -1

typedef pair<int, int> ii;

int dyn[305][305], C;
ii coins[45];

double value(int x, int y){
	double v = x*x + y*y;
	return sqrt(v);
}

vector<ii> getPairs(int v){
	vector<ii> rs;
	for (int i = 0; i <= v; i++){
		for (int j = 0; j <= v; j++){
			if (value(i, j) == v){
				rs.push_back(ii(i, j));
			}
		}
	}
	return rs;
}

void init(){
	for (int i = 0; i < 305; i++){
		for (int j = 0; j < 305; j++){
			dyn[i][j] = UNSET;
		}
	}
}

int change(int p1, int p2){
	//printf("entering change(%d, %d)\n", p1, p2);

	if (!p1 && !p2)
		return 0;

	if (p1 < 0 || p2 < 0)
		return INF;

	if (dyn[p1][p2] != UNSET)
		return dyn[p1][p2];

	//printf("well...\n");
	int tmp = INF;
	for (int i = 0; i < C; i++){
		tmp = min(tmp, 1 + change(p1 - coins[i].first, p2 - coins[i].second));
	}

	dyn[p1][p2] = tmp;
	return dyn[p1][p2];
}

int main(){
	int V, t, v1, v2;
	scanf("%d", &t);
	while(t--){
		init();
		scanf("%d %d", &C, &V);
		int res = INF;
		for (int i = 0; i < C; i++){
			scanf("%d %d", &v1, &v2);
			coins[i] = ii(v1, v2);
		}

		vector<ii> values = getPairs(V);
		for (int i = 0; i < values.size(); i++){
			res = min(res, change(values[i].first, values[i].second));
		}

		if (res < INF)
			printf("%d\n", res);
		else printf("not possible\n");
	}
	return 0;
}