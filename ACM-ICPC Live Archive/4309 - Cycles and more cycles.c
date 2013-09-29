// Accepted
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

#define MOD 98765431
#define MAXN 15

int T, n, k;

int special[MAXN];
int mem[1<<MAXN][MAXN];
bool visited[1<<MAXN][MAXN];

int specialCount[1<<MAXN];
unsigned int adjacent[MAXN];
unsigned int notSpecial;

int dp(int remaining, int curr){
	int m;
	int soFar = specialCount[((1<<n)-1) ^ remaining];

	if (remaining == 0 && (adjacent[curr] & (1<<special[0])))
		return 1;
	else if (visited[remaining][curr])
		return mem[remaining][curr];

	visited[remaining][curr] = true;
	mem[remaining][curr] = 0;

	if (remaining & adjacent[curr] & (1<<special[soFar]))
		mem[remaining][curr] = dp(remaining ^ (1<<special[soFar]), special[soFar]);

	for (m = 0; m < n; m++)
		if (remaining & adjacent[curr] & notSpecial & (1<<m))
			mem[remaining][curr] = (mem[remaining][curr] + dp(remaining ^ (1<<m), m)) % MOD;

	return mem[remaining][curr];
}

int main(void){
	int i, j, k;

	scanf("%d", &T);

	while (T--){
		scanf("%d", &n);

		for (i = 0; i < n; i++){
			adjacent[i] = 0;
			for (j = 0; j < n; j++){
				int t;
				scanf("%d", &t);
				adjacent[i] |= t<<j;
			}
		}

		scanf("%d", &k);

		for (i = 0; i < n; i++)
			specialCount[1<<i] = 0;

		notSpecial = (1<<n) - 1;
		for (i = 0; i < k; i++){
			scanf("%d", &special[i]);
			specialCount[1<<special[i]] = 1;
			notSpecial ^= 1<<special[i];
		}
		special[k] = special[0];

		for (i = 0; i < 1<<n; i++){
			j = i & -i;
			specialCount[i] = specialCount[j] + specialCount[i ^ j];
		}

		memset(visited, false, sizeof(visited));

		printf("%d\n", dp(((1<<n)-1) ^ (1<<special[0]), special[0]));
	}

	return 0;
}
