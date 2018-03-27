#include <cstdio>
#define FLOW 0
#define COST 1
#define MAX_COST 1 << 29
int watergate[25][2], min_cost;

int bit_count(int bitset, int G, int param){
	int total = 0;
	for (int i = 0; i < G; i++){
		if (bitset & (1 << i)) total += watergate[G-i-1][param];
	}

	return total;
}

bool c_search(int time, int flow, int G){
	int cmb = 1 << G;
	min_cost = bit_count(cmb - 1, G, COST);
	for (int i = cmb - 1; i > 0; i--){
		if (i == cmb - 1 && bit_count(i, G, FLOW) * time < flow)
			return false;

		int act_flow = bit_count(i, G, FLOW), act_cost = bit_count(i, G, COST);
		if (act_flow * time >= flow && min_cost > act_cost)
			min_cost = act_cost;
	}
	return true;
}

int main(){
	int w, m, f, t;
	scanf("%d", &w);
	for (int i = 0; i < w; i++){
		scanf("%d %d", &watergate[i][0], &watergate[i][1]);
	}
	scanf("%d", &m);

	for (int i = 0; i < m; i++){
		scanf("%d %d", &f, &t);

		printf("Case %d: ", i + 1);
		if (!c_search(t, f, w))
			printf("IMPOSSIBLE\n");

		else
			printf("%d\n", min_cost);
	}

	return 0;
}