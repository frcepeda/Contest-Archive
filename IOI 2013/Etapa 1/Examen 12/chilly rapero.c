#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 310
#define MAXL 110
#define INFINITY (1<<30)

unsigned int dist[MAXN][MAXN];

char dict[MAXN][MAXL];

int N, R;
unsigned int answer;

unsigned int min(unsigned int a, unsigned int b){
	return a < b ? a : b;
}

int strDiff(char *a, char *b){
	int ans = 0;

	for (; *a; a++, b++)
		if (*a != *b)
			ans++;

	return ans;
}

bool isPrefix(char *a, char *b){
	for (; *a && *b; a++, b++)
		if (*a != *b)
			return false;
	return *b == '\0';
}

bool isSuffix(char *a, char *b){
	int la = strlen(a) - 1;
	int lb = strlen(b) - 1;

	if (lb > la) return false;

	for (; la >= 0 && lb >= 0; la--, lb--)
		if (a[la] != b[lb])
			return false;

	return lb < 0;
}

int main(void){
	int i, j, k;

	scanf("%d %d", &N, &R);

	for (i = 1; i <= N; i++)
		scanf("%s", dict[i]);

	for (i = 1; i <= N; i++){
		for (j = i+1; j <= N; j++){
			dist[j][i] = dist[i][j] = INFINITY;

			if (strlen(dict[i]) == strlen(dict[j]) && strDiff(dict[i], dict[j]) == 1)
				dist[j][i] = dist[i][j] = 1;
			if (isPrefix(dict[i], dict[j]) || isSuffix(dict[i], dict[j]) || isPrefix(dict[j], dict[i]) || isSuffix(dict[j], dict[i]))
				dist[j][i] = dist[i][j] = 1;
		}
	}

	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int last, next;
	scanf("%d", &last);

	for (i = 1; i < R; i++){
		scanf("%d", &next);
		answer += dist[last][next];
		last = next;
	}

	printf("%.1f\n", .2 * answer);

	return 0;
}
