#include <cstdio>
#include <cmath>

using namespace std;

typedef long double ld;

int T;

ld f(ld x){
	return sin(x) + cos(x);
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		ld lo = 0, hi = atan(1), mid;

		ld target;
		scanf("%Lf", &target);

		for (int i = 0; i < 200; i++){
			mid = (lo + hi)/2;

			if (f(mid) <= target)
				lo = mid;
			else
				hi = mid;
		}

		ld theta = (lo + hi) / 2;
		ld c = cos(theta) / 2;
		ld s = sin(theta) / 2;

		printf("Case #%d:\n", t);
		fprintf(stderr, "theta = %.10Lf\n", theta);
		printf(".5 0 0\n");
		printf("0 %.15Lf %.15Lf\n", c, s);
		printf("0 %.15Lf %.15Lf\n", -s, c);
	}
}
