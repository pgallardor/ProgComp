#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

map<string, int> valid;

void get_combs(char l[7][7], int C, string str){
	//cout << str << endl;

	if (C >= 5){
		valid[str] = 1;
		return;
	}

	for (int i = 0; i < 6; i++){
		str.push_back(l[i][C]);
		get_combs(l, C + 1, str);
		str.erase(str.end() - 1);
	}
}

void solve(char l[7][7], int C, string str){

	if (C >= 5){
		if (valid.count(str)){
			valid[str] += 1;
		}
		return;
	}

	for (int i = 0; i < 6; i++){
		str.push_back(l[i][C]);
		solve(l, C + 1, str);
		str.erase(str.end() - 1);
	}
}

int main(){
	int T, k;
	char lock1[7][7], lock2[7][7];
	scanf("%d", &T);
	getchar();
	while(T--){
		scanf("%d", &k);
		getchar();
		for (int i = 0; i < 6; i++){
			scanf("%s", lock1[i]);
		}
		
		for (int i = 0; i < 6; i++){
			scanf("%s", lock2[i]);
		}

		/*for (int i = 0; i < 6; i++){
			for (int j = 0; j < 5; j++){
				printf("%c", lock2[i][j]);
			}
			printf("\n");
		}
		printf("\n");	
		*/
		get_combs(lock1, 0, string());
		solve(lock2, 0, string());

		map<string, int>::iterator it;
		int cnt = 0, shown = 0;

		for (it = valid.begin(); it != valid.end(); ++it){
			if (it->second >= 2)
				cnt++;

			if (cnt == k){
				printf("%s\n", (it->first).c_str());
				shown = 1;
				break;
			}
			/*if (it->second > 2){
				printf("%s\n", (it->first).c_str());
			}*/
		}

		if (!shown) printf("NO\n");
		valid.clear();

	}
	return 0;
}