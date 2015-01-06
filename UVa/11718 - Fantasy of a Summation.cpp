#include <cstdio>

/*
Separate the sums by summands. Note that the K resulting sums are the same.
Now, in sum 1 there are K-1 sums where i1 is constant.
The formula follows immediately.
*/

using namespace std;

int n, K, MOD, total;

int modExp(int x, int e){
	int r = 1;
	
	for (; e; e /= 2){
		if (e % 2)
			r = (r * x) % MOD;
		x = (x * x) % MOD;
	}
	
	return r;
}

int main() {
	int i, t, T;
	
	scanf("%d", &T);
	
	for (t = 1; t <= T; t++){
		total = 0;
		scanf("%d %d %d", &n, &K, &MOD);
		
		for (i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			total = (total + x % MOD) % MOD;
		}
		
		printf("Case %d: %d\n", t, K % MOD * total % MOD * modExp(n,K-1) % MOD);
	}
}