#include <stdio.h>

#define MAXN 500100
#define MAXLG 20

int N, M;
int _gcd[MAXN][MAXLG];

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int gcd(int a, int b){
	int c;
	while (b && a >= M){
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int lg(int a){
	int r = -1;
	for (; a; r++, a /= 2);
	return r;
}

int gcdOfRange(int a, int b){
	if (b < a)
		return 0;
	int l = lg(b - a + 1);
	return gcd(_gcd[a][l],
	           _gcd[b - (1<<l) + 1][l]);
}

int main(void){
	int i, j, best = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%d", &_gcd[i][0]);

	for (j = 1; j < MAXLG; j++)
		for (i = 0; i < N; i++)
			_gcd[i][j] = gcd(_gcd[i][j-1],
			                 _gcd[min(i + (1<<(j-1)), N-1)][j-1]);

	for (i = 0; i < N; i++){
		int lo = i, hi = N, mid;

		while (lo < hi){
			mid = (lo + hi) / 2;

			if(gcdOfRange(i, mid) >= M)
				lo = mid + 1;
			else if (mid - i > best)
				hi = mid;
			else break;
		}

		if (gcdOfRange(i, lo-1) >= M)
			best = max(best, lo - i);
	}

	printf("%d\n", best);

	return 0;
}
