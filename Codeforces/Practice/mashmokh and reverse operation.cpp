#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 21

int n, m;
int a[1<<MAXN];
int c[1<<MAXN];
long long b[2][MAXN];
int curr[MAXN];

void merge(int *arr, int n, int k, long long *out){
	static int tmp[1<<MAXN];
	int mid = n/2;

	if (n <= 1) return;

	merge(arr, mid, k-1, out);
	merge(arr + mid, n - mid, k-1, out);
	int a = 0, b = mid, cnt = 0;

	while (a < mid || b < n){
		if (b >= n || (a < mid && arr[a] <= arr[b])){
			tmp[cnt++] = arr[a++];
		} else {
			out[k] += mid - a;
			tmp[cnt++] = arr[b++];
		}
	}

	copy(tmp, tmp + n, arr);
}

int main(void){
	int i, j, k, q;

	scanf("%d", &n);

	for (i = 0; i < (1<<n); i++)
		scanf("%d", &a[i]);

	copy(a, a + (1<<n), c);
	merge(c, (1<<n), n, b[0]);

	copy(a, a + (1<<n), c);
	reverse(c, c + (1<<n));
	merge(c, (1<<n), n, b[1]);

	scanf("%d", &m);

	while (m--){
		long long ans = 0;

		scanf("%d", &q);

		for (i = q; i >= 0; i--)
			curr[i] ^= 1;

		for (i = 0; i <= n; i++)
			ans += b[curr[i]][i];

		printf("%lld\n", ans);
	}

	return 0;
}
