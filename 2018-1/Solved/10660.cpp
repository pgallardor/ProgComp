#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int grid[10][10], config[7];

void calc_index(int i, int &x, int &y){
	x = i / 5;
	y = i % 5;
}

int calc_dist(int i, int j, int ofn){
	int x, y;
	calc_index(ofn, x, y);
	return (abs(i - x) + abs(j - y)) * grid[i][j];
}

void save_config(int x1, int x2, int x3, int x4, int x5){
	config[0] = x1; config[1] = x2; config[2] = x3; config[3] = x4; 
	config[4] = x5;
}

int main(){
	int T, n;
	scanf("%d", &T);
	while(T--){
		int x, y, z;
		memset(grid, 0, sizeof(int)*10*10);
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d %d %d", &x, &y, &z);
			grid[x][y] = z;
		}

		int min_sum = 1 << 28;
		for (int o1 = 0; o1 < 21; o1++){
			for (int o2 = o1 + 1; o2 < 22; o2++){
				for (int o3 = o2 + 1; o3 < 23; o3++){
					for (int o4 = o3 + 1; o4 < 24; o4++){
						for (int o5 = o4 + 1; o5 < 25; o5++){
							int dist = 0;
							for (int i = 0; i < 5; i++){
								for (int j = 0; j < 5; j++){
									int m = 1 << 28;
									m = min(m, calc_dist(i, j, o1));
									m = min(m, calc_dist(i, j, o2));
									m = min(m, calc_dist(i, j, o3));
									m = min(m, calc_dist(i, j, o4));
									m = min(m, calc_dist(i, j, o5));

									dist += m;
								}
							}
							//printf("Total dist: %d in config %d %d %d %d %d\n", dist, o1, o2, o3, o4 ,o5);
							if (dist < min_sum){ 
								save_config(o1, o2, o3, o4, o5);
								min_sum = dist;
							}
						}
					}			
				}
			}
		}

		printf("%d", config[0]);
		for(int i = 1; i < 5; i++) printf(" %d", config[i]);
		printf("\n");	
	}
} 