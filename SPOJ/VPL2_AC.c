#include <stdio.h>

#define MAXN 1000100

int T, C;
char str[MAXN];
int dist[256][256] = {
	['G'] = {['G'] = 0, ['R'] = 1, ['Y'] = 2, ['B'] = 3, ['O'] = 4},
	['R'] = {['G'] = 1, ['R'] = 0, ['Y'] = 1, ['B'] = 2, ['O'] = 3},
	['Y'] = {['G'] = 2, ['R'] = 1, ['Y'] = 0, ['B'] = 1, ['O'] = 2},
	['B'] = {['G'] = 3, ['R'] = 2, ['Y'] = 1, ['B'] = 0, ['O'] = 1},
	['O'] = {['G'] = 4, ['R'] = 3, ['Y'] = 2, ['B'] = 1, ['O'] = 0}
};

int main(void){
	int a, b, t;
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int best = 0, curr = 0;

		scanf("%d %s", &C, str);

		a = b = 0;

		while (str[a] != '\0'){
			if (curr <= C && best < b - a + 1)
				best = b - a + 1;

			if (curr <= C && str[b+1] != '\0'){
				curr += dist[str[b]][str[b+1]];
				b++;
			} else {
				curr -= dist[str[a]][str[a+1]];
				a++;
			}
		}

		printf("Scenario #%d: %d\n", t, best);
	}

	return 0;
}
