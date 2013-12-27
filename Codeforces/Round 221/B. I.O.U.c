#include <stdio.h>

#define MAXN 110

int n, m;
int in[MAXN], out[MAXN];
long long ans;

int main(void){
	int i;

	scanf("%d %d", &n, &m);

	while (m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		out[a] += c;
		in[b] += c;
	}

	for (i = 1; i <= n; i++)
		if (out[i] >= in[i])
			ans += out[i] - in[i];

	printf("%lld\n", ans);

	return 0;
}
