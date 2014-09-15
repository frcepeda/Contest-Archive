#include <cstdio>
#include <algorithm>
#include <cctype>

#define MAXN 105
#define INF (1<<25)

using namespace std;

struct state {
	int r, c, d;
};

int N;
char map[MAXN][MAXN];
bool v[MAXN][MAXN];
state queue[MAXN*MAXN];
int qs, qe;
int best = INF;

#define push(x) queue[qe++] = x
#define pop() (queue[qs++])
#define queueNotEmpty (qe != qs)
#define reset() qs = qe = 0

int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int u;

int dig(char x){
	if (islower(x)) return x - 'a';
	else return tolower(x) - 'a';
}

void bfs(){
	state curr, next;
	curr.r = curr.c = curr.d = 0;

	reset();
	push(curr);

	if (!!(u & (1<<dig(map[0][0]))) != !!islower(map[0][0])) return;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			v[i][j] = false;

	while (queueNotEmpty){
		curr = pop();

		if (curr.r == N-1 && curr.c == N-1){
			best = min(best, curr.d + 1);
			return;
		}

		if (curr.d >= best) continue;
		next.d = curr.d + 1;

		for (int i = 0; i < 4; i++){
			next.r = curr.r + dr[i];
			next.c = curr.c + dc[i];
			if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= N) continue;
			if (v[next.r][next.c]) continue;
			if (!!(u & (1<<dig(map[next.r][next.c]))) != !!islower(map[next.r][next.c])) continue;
			v[next.r][next.c] = true;
			push(next);
		}
	}
}

int main() {
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%s", map[i]);

	for (u = 0; u < (1<<('j'-'a'+1)); u++)
		bfs();

	printf("%d\n", best == INF ? -1 : best);
}
