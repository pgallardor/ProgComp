#include <cstdio>
#include <cmath>
#define PIZZA 36000 

unsigned gcd(unsigned x, unsigned y){
	while(y != 0){
		unsigned r = x % y;
		x = y;
		y = r;
	}

	return x;
}

int main(){
	double angle, sol;
	scanf("%lf", &angle);

	unsigned i_angle = ceil(angle * 100);

	unsigned response = gcd(PIZZA, i_angle);
	sol = (double)PIZZA / response;

	printf("%d\n", (int)ceil(sol));

	return 0;
}