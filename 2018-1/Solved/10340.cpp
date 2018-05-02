#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

bool is_subsequence(string s1, string s2){
	if (s2.size() < s1.size()) return false;

	int idx = 0, sidx = 0;
	
	while (sidx < s2.size()){
		if (idx >= s1.size()) break;

		if (s2[sidx] == s1[idx])
			idx++;
		sidx++;
	}

	return idx >= s1.size();
}

int main(){
	string s, t;
	while (cin >> s >> t){
		if (is_subsequence(s, t)) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}