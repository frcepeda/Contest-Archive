#include <stdio.h>

#define MAXN 100010

long long int max(long long int a, long long int b){
	return a > b ? a : b;
}

typedef struct {
	int idx, h;
} pair;

pair makePair(int idx, int h){
	pair p = {.idx = idx, .h = h};
	return p;
}

pair stack[MAXN];
int sti;

#define push(a) stack[sti++] = (a)
#define pop() (stack[--sti])
#define peek() (stack[sti-1])
#define stackIsNotEmpty (sti)

int N;
int heights[MAXN];
int left[MAXN], right[MAXN];

long long int ans;

int main(void){
	int i;

	while (scanf("%d", &N), N){
		pair curr;

		ans = sti = 0;

		for (i = 0; i < N; i++)
			scanf("%d", &heights[i]);

		push(makePair(-1,-1));

		for (i = 0; i < N; i++){
			while (peek().h >= heights[i])
				pop();
			left[i] = peek().idx;

			push(makePair(i, heights[i]));
		}

		sti = 0;
		push(makePair(N, -1));

		for (i = N-1; i >= 0; i--){
			while (peek().h >= heights[i])
				pop();
			right[i] = peek().idx;

			push(makePair(i, heights[i]));
		}

		for (i = 0; i < N; i++)
			ans = max(ans, (long long int)heights[i] * (right[i] - left[i] - 1));

		printf("%lld\n", ans);
	}

	return 0;
}
