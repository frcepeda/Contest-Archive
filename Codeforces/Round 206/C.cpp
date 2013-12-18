#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 100100

long long n, l, r, Ql, Qr;
long long w[MAXN], sum[MAXN];

long long _abs(long long x){
	return x >= 0 ? x : -x;
}

long long f(long long l, long long r){
	if (_abs(l-r) <= 1)
		return 0;
	else if (l > r)
		return (l - r - 1) * Ql;
	else
		return (r - l - 1) * Qr;
}

int main(){
	long long i, ans = LONG_MAX;

	scanf("%d %d %d %d %d", &n, &l, &r, &Ql, &Qr);

	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		sum[i] = sum[i-1] + w[i];
	}

	for (i = 0; i <= n; i++)
		ans = min(ans, sum[i] * l + (sum[n] - sum[i]) * r + f(i,n-i));

	printf("%d\n", ans);
}
