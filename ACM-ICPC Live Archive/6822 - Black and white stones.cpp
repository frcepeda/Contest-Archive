#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int A, B, N, k;
char S[5010];
long long ans = 1LL<<50;

int main(){
	int c, i, j;
	scanf("%d %d", &A, &B);
	scanf("%s", S);
	N = strlen(S);

	for (i = 0; i < N; i++)
		if (S[i] == 'B')
			k++;

	for (c = 0; c <= k; c++){
		long long m = (long long)A * c;
		j = k - c;
		int p = c;
		for (i = 0; i < N && j; i++)
			if (S[i] == 'B'){
				if (i > p)
					m += (A - B) * (i - p);
				p++;
				j--;
			}
		ans = min(ans, m);
	}

	printf("%lld\n", ans);
}
