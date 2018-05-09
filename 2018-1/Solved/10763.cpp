#include <cstdio>
#include <map>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

void insert(map<ii, int> &mp, ii n){
	bool inv = false;
	if (n.first > n.second){
		inv = true;
		n = ii(n.second, n.first);
	}

	if (!mp.count(n))
		mp[n] = 0;
	

	int tmp;
	if (inv)
		tmp = --mp[n];
	
	else
		tmp = ++mp[n];
		
}

bool is_valid(map<ii, int> mp){
	map<ii, int>::iterator it;

	for (it = mp.begin(); it != mp.end(); ++it){
		if (it->second)
			return false;
	}
	return true;
}

int main(){
	int N, n1, n2;
	while (scanf("%d", &N) && N){
		map<ii, int> pairs;
		for (int i = 0; i < N; i++){
			scanf("%d %d", &n1, &n2);
			insert(pairs, ii(n1, n2));
		}

		if (is_valid(pairs)) printf("YES\n");
		else printf("NO\n");
	}
}