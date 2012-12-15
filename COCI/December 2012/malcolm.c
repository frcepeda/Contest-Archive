#include <stdio.h>
#include <string.h>

#define MAXN 300010
#define MAXK 21

int N, K;
unsigned long long int answer;
int len[MAXN];
int BIT[MAXN][MAXK];

int min(int a, int b){
	return a < b ? a : b;
}

void update(int i, int k, int d){
	int t;
	for (t = i; t < MAXN; t += t&-t)
		BIT[t][k] += d;
}

int query(int i, int k){
	int ret = 0, t;
	for (t = i; t > 0; t -= t&-t)
		ret += BIT[t][k];
	return ret;
}

int main(void){
	int i;

	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++){
		static char str[21];
		scanf("%s", str);
		len[i] = strlen(str);
		update(i, len[i], 1);
	}

	for (i = 1; i <= N; i++)
		answer += query(min(i+K, N), len[i]) - query(i, len[i]);

	printf("%llu\n", answer);

	return 0;
}
