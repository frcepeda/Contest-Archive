#include <cstdio>

#define MAXN 22

using namespace std;

int n, m, b;
int a[MAXN], c[MAXN][2];

int popcount(int x){
	int r = 0;
	for (; x; x ^= x&-x) r++;
	return r;
}

int main() {
	int t = 1;
	
	while (scanf("%d %d", &n, &b), (n || b)){
		int i, j, x;
		
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
			
		scanf("%d", &m);
		
		for (i = 0; i < m; i++){
			scanf("%d", &j);
			c[i][0] = 0;
			while (j--){
				scanf("%d", &x);
				c[i][0] |= 1 << (x-1);
			}
			scanf("%d", &c[i][1]);
		}
		
		int best, bestServed = 0;
		for (i = 0; i < (1<<n); i++){
			int served = 0;
			
			if (popcount(i) != b) continue;
			
			for (j = 0; j < n; j++)
				if (i & (1<<j))
					served += a[j];
			
			for (j = 0; j < m; j++){
				int cnt = popcount(i & c[j][0]);
				if (cnt >= 2)
					served -= c[j][1] * (cnt - 1);
			}
			
			if (served > bestServed){
				bestServed = served;
				best = i;
			}
		}
		
		printf("Case Number  %d\n", t++);
		printf("Number of Customers: %d\n", bestServed);
		printf("Locations recommended:");
		
		for (j = 0; j < n; j++)
				if (best & (1<<j))
					printf(" %d", j+1);
		
		printf("\n\n");
	}
}