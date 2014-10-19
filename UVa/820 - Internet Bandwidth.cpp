#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 110
#define MAXE (MAXN*MAXN*2)

int n, s, t, c;
int C[MAXN][MAXN], F[MAXN][MAXN], P[MAXN], M[MAXN];

int queue[MAXN], qs, qe;
#define queueIsNotEmpty (qs < qe)
#define push(x) queue[qe++] = x
#define pop() queue[qs++]

int main(){
	int i;

	for (int T = 1; scanf("%d %d %d %d", &n, &s, &t, &c), n; T++){
		int f = 0;

		for (i = 0; i < MAXN; i++){
			fill(C[i], C[i] + MAXN, 0);
			fill(F[i], F[i] + MAXN, 0);
		}

		while (c--){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			C[a][b] += c;
			C[b][a] += c;
		}

		while (true){
			fill(P, P + MAXN, 0);

			P[s] = -1;
			qs = qe = 0;
			push(s);

			while (queueIsNotEmpty){
				int curr = pop();

				if (curr == t) break;

				for (i = 1; i <= n; i++){
					if (P[i] || C[curr][i] - F[curr][i] <= 0) continue;
					M[i] = C[curr][i] - F[curr][i];
					P[i] = curr;
					push(i);
				}
			}

			if (P[t] == 0) break;

			int df = 1<<28;
			for (i = t; i != s; i = P[i])
				df = min(df, M[i]);

			f += df;

			for (i = t; i != s; i = P[i]){
				F[P[i]][i] += df;
				F[i][P[i]] -= df;
			}
		}

		printf("Network %d\nThe bandwidth is %d.\n\n", T, f);
	}
}
