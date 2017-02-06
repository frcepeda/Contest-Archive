#include <cstdio>
#include <algorithm>

using namespace std;

typedef double ld;

const int maxn = 100010;

int n;
int t[2*maxn], c[2*maxn];
bool b[2*maxn];
ld dp[2*maxn];

int main(){
	scanf("%d", &n);

	for (int i = 0; i < 2*n; i++){
		char s;
		scanf(" %c %d", &s, &t[i]);
		b[i] = s == '+';
		c[i] = i == 0 ? 1 : c[i-1] + (b[i] ? 1 : -1);
	}

	for (int i = 2*n-1; i >= 0; i--){
		if (!b[i]) continue;

		ld p = 1;
		int j;

		for (j = i+1; j < 2*n && !b[j]; j++){
			dp[i] += (t[j] - t[i]) * p / (c[j] + 1);
			p *= c[j]/ld(c[j] + 1);
		}

		if (j < 2*n)
			dp[i] += (t[j] - t[i] + dp[j]) * p;
	}

	for (int i = 0; i < 2*n; i++)
		if (b[i])
			printf("%.10lf\n", dp[i]);
}
