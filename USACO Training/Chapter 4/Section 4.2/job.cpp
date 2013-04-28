/*
    ID: frceped1
    LANG: C++
    TASK: job
 */

#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("job.in", "r", stdin); freopen("job.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 1010

typedef pair<int,int> pii;

int endTimes[2][MAXN];
int N, M1, M2;
int lastA, lastB;

priority_queue<pii, vector<pii>, greater<pii> > machines;

int main(void){
	int i, j;

	openFiles();

	scanf("%d %d %d", &N, &M1, &M2);

	for (i = 0; i < M1; i++){
		scanf("%d", &j);
		machines.push(make_pair(j,j));
	}

	for (i = 0; i < N; i++){
		pii best = machines.top();
		machines.pop();

		endTimes[0][i] = best.first;

		lastA = max(lastA, best.first);

		best.first += best.second;

		machines.push(best);
	}

	while (!machines.empty())
		machines.pop();

	for (i = 0; i < M2; i++){
		scanf("%d", &j);
		machines.push(make_pair(j,j));
	}

	for (i = 0; i < N; i++){
		pii best = machines.top();
		machines.pop();

		endTimes[1][i] = best.first;

		best.first += best.second;

		machines.push(best);
	}

	sort(endTimes[0], endTimes[0] + N);
	sort(endTimes[1], endTimes[1] + N, greater<int>());

	for (i = 0; i < N; i++)
		lastB = max(lastB, endTimes[0][i] + endTimes[1][i]);

	printf("%d %d\n", lastA, lastB);

	return 0;
}
