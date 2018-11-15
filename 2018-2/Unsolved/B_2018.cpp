#include <cstdio>

typedef long long lli;

lli nums[10005], tree[10005];

void build_tree(int N){
	tree[0] = nums[0];
	for (int i = 1; i < N; i++) tree[i] = tree[i - 1] + nums[i];
}

lli check_interval(int i, int j){
	if (i == j) return nums[i];
	if (i == 0) return tree[j];

	return tree[j] - tree[i - 1]; 
}

int binary(int N, int min, int max){
	while(min <= max){
		int mid = (min + max)/2;
		lli li = check_interval(0, mid), ri = check_interval(mid + 1, N - 1); 
		//printf("mid = %d, li = %lld, ri = %lld\n", mid, li, ri);
		if (li == ri) return mid;
		if (li < ri) min = mid - 1;
		else max = mid + 1;
	}

	return -1;
}

bool hasSolution(int idx, int N){
	int li = 0, ri = idx + 1;
	while(li < idx && ri < N - 1){
		lli lv = check_interval(0, li), rv = check_interval(idx + 1, ri);
		//printf("lv = %lld, rv = %lld\n", lv, rv);
		if (lv == rv) return true;
		else if (check_interval(li + 1, idx) == check_interval(ri + 1, N - 1)) return true;
		if (lv < rv) li++;
		else ri++;
	}

	return false;
}

int main(){
 	int N;
 	scanf("%d", &N);

 	for (int i = 0; i < N; i++) scanf("%lld", &nums[i]);
 	build_tree(N);
 	
 	int idx = binary(N, 0, N); 
 	if (idx == -1) {
 		printf("N\n");
 		return 0;
 	}

 	//printf("idx = %d\n", idx);
 	
 	if (hasSolution(idx, N)) printf("Y\n");
 	else printf("N\n");
 		
 	return 0;
 }