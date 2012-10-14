#include <stdio.h>

#define MAXN 400010

int min[MAXN*2];
int mins, mine;

int max[MAXN*2];
int maxs, maxe;

int N, W;
int heights[MAXN];

#define check() (max[maxs] - min[mins] + 1) == W;

#define pop(x, n) if (x[x##s] == n) x##s++

#define push(x, n, CMP) while (x##s < x##e && n CMP x[x##e-1]) \
					x##e--; \
				x[x##e++] = n

#define popmax(n) pop(max, n)
#define popmin(n) pop(min, n)

#define pushmax(n) push(max, n, >)
#define pushmin(n) push(min, n, <)

int main(void){
	int i, answer = 0;

	scanf("%d %d", &N, &W);

	for (i = 0; i < N; i++)
		scanf("%d", &heights[i]);

	for (i = 0; i < W; i++){
		pushmax(heights[i]);
		pushmin(heights[i]);
	}
	answer += check();

	for (; i < N; i++){
		popmax(heights[i-W]);
		popmin(heights[i-W]);
		pushmax(heights[i]);
		pushmin(heights[i]);
		answer += check();
	}

	printf("%d\n", answer);

	return 0;
}

