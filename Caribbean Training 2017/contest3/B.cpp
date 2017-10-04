#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int n, x[maxn], y[maxn];
long long c[4];

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
		c[(x[i]%2+2)%2 + ((y[i]%2+2)%2)*2]++;
	}

	long long ans = 0;
	for (int z0 = 0; z0 < 4; z0++)
	for (int z1 = z0; z1 < 4; z1++)
	for (int z2 = z1; z2 < 4; z2++){
		int x0 = z0 % 2, y0 = z0 / 2;
		int x1 = z1 % 2, y1 = z1 / 2;
		int x2 = z2 % 2, y2 = z2 / 2;

		int s = x0 * y1 + x1 * y2 + x2 * y0 -
		        y0 * x1 + y1 * x2 + y2 * x0;

		if (s % 2 == 0){
			long long tmp = c[z0] * (c[z1] - (z0 == z1)) *
			       (c[z2] - (z0 == z2) - (z1 == z2));

			if (z0 == z1 && z1 == z2) tmp /= 6;
			else if (z0 == z1 || z1 == z2 || z0 == z2)
				tmp /= 2;

			ans += tmp;
		}
	}

	printf("%lld\n", ans);
}
