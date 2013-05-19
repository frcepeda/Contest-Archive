#include <stdio.h>

#define MAXN 100100

int songStart[MAXN];
int n, m;

int main(void){
	int i;

	scanf("%d %d", &n, &m);

	songStart[0] = 1;
	for (i = 0; i < n; i++){
		int c, t;
		scanf("%d %d", &c, &t);
		songStart[i+1] = songStart[i] + c * t;
	}

	for (i = 0; i < m; i++){
		int x, lo = 0, hi = n, mid;
		scanf("%d", &x);

		while (lo < hi){
			mid = (lo + hi)/2;
			if (songStart[mid] <= x)
				lo = mid + 1;
			else
				hi = mid;
		}

		printf("%d\n", lo);
	}

	return 0;
}
