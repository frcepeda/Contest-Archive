#include <stdio.h>
#include <limits.h>
#include <queue>
#include <bitset>

#define MAXR 4010
#define MAXC 210

using namespace std;

struct pii{
	int first, second;
};

int R, C, D, A, B;

int map[MAXR][MAXC];
int bestWay[MAXR][MAXR];
int accFromLeft[MAXR][MAXC];
int accFromRight[MAXR][MAXC];
int innerSpace[MAXR];

bitset<MAXR> visited;

bool operator < (const pii &a, const pii &b){
	return a.second > b.second;
}

priority_queue<pii> q;

long long int answer;

void search(int start){
	int i;
	pii curr, next;
	visited.reset();

	curr.first = start;
	curr.second = 0;
	q.push(curr);

	while (!q.empty()){
		int realRow;

		curr = q.top();
		q.pop();

		if (visited[curr.first]) continue;
		visited[curr.first] = true;

		bestWay[start][curr.first] = curr.second;

		realRow = ((curr.first - 1) % R) + 1;

		next.first = curr.first + (curr.first <= R ? R : -R);
		next.second = curr.second + innerSpace[realRow] + map[realRow][curr.first <= R ? C : 1];

		if (!visited[next.first])
			q.push(next);

		if (realRow < R){
			next.first = curr.first + 1;
			next.second = curr.second + map[realRow+1][curr.first <= R ? 1 : C];

			if (!visited[next.first])
				q.push(next);
		}

		if (realRow > 1){
			next.first = curr.first - 1;
			next.second = curr.second + map[realRow-1][curr.first <= R ? 1 : C];

			if (!visited[next.first])
				q.push(next);
		}
	}
}

int main(void){
	int i, j;

	scanf("%d %d", &R, &C);

if (R > 250){
return 0;
}

	for (i = 1; i <= R; i++)
		for (j = 1; j <= C; j++)
			scanf("%d", &map[i][j]);

	for (i = 1; i <= R; i++)
		for (j = 2; j <= C; j++)
			accFromLeft[i][j] = accFromLeft[i][j-1] + map[i][j];

	for (i = 1; i <= R; i++)
		for (j = C-1; j > 0; j--)
			accFromRight[i][j] = accFromRight[i][j+1] + map[i][j];

	for (i = 1; i <= R; i++)
		innerSpace[i] = accFromRight[i][1] - map[i][1];

	for (i = 1; i <= R*2; i++)
		search(i);

	/*
	for (i = 1; i <= R*2; i++)
		for (j = 1; j <= R*2; j++)
			printf("%d -> %d: %d\n", i, j, bestWay[i][j]);
			*/

	scanf("%d", &D);

	int lastA = 1, lastB = 1;
	while (D--){
		int best = INT_MAX;

		scanf("%d %d", &A, &B);

		if (lastA == A){
			if (A < B)
				best = min(best, accFromLeft[A][B] - accFromLeft[A][lastB]);
			else
				best = min(best, accFromRight[A][B] - accFromRight[A][lastB]);
		}

			best = min(best, bestWay[lastA][A] + accFromLeft[A][B] + accFromLeft[lastA][lastB-1] + (lastB > 1 ? map[lastA][1] : 0));

		best = min(best, bestWay[lastA][A+R] + accFromRight[A][B] + accFromLeft[lastA][lastB-1] + (lastB > 1 ? map[lastA][1] : 0));
		best = min(best, bestWay[lastA+R][A] + accFromLeft[A][B] + accFromRight[lastA][lastB+1] + (lastB < C ? map[lastA][C] : 0));

			best = min(best, bestWay[lastA+R][A+R] + accFromRight[A][B] + accFromRight[lastA][lastB+1] + (lastB < C ? map[lastA][C] : 0));

		answer += best;
		lastA = A;
		lastB = B;
	}

	printf("%lld\n", answer + map[1][1]);

	return 0;
}
