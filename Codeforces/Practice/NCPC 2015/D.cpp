#include <cstdio>

using namespace std;

#define MAXN 100100

int n, k, t[MAXN];

bool f(int q){
	int r = q*k, i, j;

	for (i = j = 0; i < n; i++, r--){
		for (; t[j] <= t[i] - 1000; j++, r++);
		if (!r) return false;
	}

	return true;
}

int main(){
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	
	int lo = 0, mid, hi = n;

	while (lo < hi){
		mid = (lo + hi)/2;
		if (f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%d\n", hi);
}
