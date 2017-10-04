// Accepted
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1010;
int n, t, s, a[maxn];

int main(){
	scanf("%d %d %d", &n, &t, &s);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++){
		double ans = max(s, a[i]) + (t - abs(a[i] - s))/2.0;
		printf("%.8lf\n", ans);
	}
}
