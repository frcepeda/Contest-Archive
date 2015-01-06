#include <cstdio>
#include <cmath>

using namespace std;

double d, v, u;

int main() {
	int T, t;
	
	scanf("%d", &T);
	
	for (t = 1; t <= T; t++){
		printf("Case %d: ", t);
		
		scanf("%lf %lf %lf", &d, &v, &u);
		
		if (v == 0 || u <= v)
			printf("can't determine\n");
		else
			printf("%.3lf\n", d/sqrt(u*u - v*v)- d/u);
	}
}