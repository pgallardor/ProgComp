#include <cstdio>
#include <iostream>
#include <vector>
#define UNDEFINED -1;
using namespace std;

vector<vector<int> > inc, clause; 

int to_int(char a){
	return (int)a - 'A' + 1;
}

int to_index(int n){
	if (n > 0)
		return n;

	return -2*n;
}

void parse_clause(string s, int idx){
	int i = 0, multiplier = 1;
	while (s[i] != ';'){
		if (s[i] == '+')
			multiplier = 1;

		else if (s[i] == '-')
			multiplier = -1;

		else{
			int cl = to_int(s[i]) * multiplier;
			clause[idx].push_back(cl);
		}

		i++;
	}
}

void show_clauses(){
	for (int i = 0; i < clause.size(); i++){
		for (int j = 0; j < clause[i].size(); j++){
			printf("%d ", clause[i][j]);
		}
		printf("\n");
	}
}

int main(){

	string input;
	while(cin >> input){
		inc = vector<vector<int> >(17*2);
		int cnt = 0;
		while(input.compare(".") != 0){
			clause.push_back(vector<int>());
			parse_clause(input, cnt);

			for (int i = 0; i < clause[cnt].size(); i++){
				int a = -clause[cnt][i];
				inc[to_index(a)].push_back(cnt);
			}

			cnt++;
			cin >> input;
		}

		show_clauses();
		inc.clear();
		clause.clear();
	}
	return 0;
}