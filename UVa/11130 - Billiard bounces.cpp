#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int a, b, v, A, s;

int solve(double l, double v){
	return max((v*s + l)/l/2, 0.0);
}

int main() {
	while (scanf("%d %d %d %d %d", &a, &b, &v, &A, &s), (a || b || v || A || s)){
		double theta = M_PI / 180 * A;
		printf("%d %d\n", solve(a, v * cos(theta)), solve(b, v * sin(theta)));
	}
}