// 80/160 points
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 300100
#define fst first
#define snd second

typedef pair<int,int> pii;

int N, L;
pii drawers[MAXN];
bool visited[MAXN];

bool tryMoving(int x){
	if (visited[x])
		return false;

	if (drawers[x].fst == 0)
		return true;

	visited[x] = true;

	int dest = drawers[x].fst == x ? drawers[x].snd : drawers[x].fst;

	if (tryMoving(dest)){
		visited[x] = false;
		drawers[dest] = drawers[x];
		return true;
	}

	visited[x] = false;
	return false;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &L);

	while (N--){
		pii curr;
		scanf("%d %d", &curr.fst, &curr.snd);

		if (drawers[curr.fst].fst == 0)
			drawers[curr.fst] = curr;
		else if (drawers[curr.snd].fst == 0)
			drawers[curr.snd] = curr;
		else if (tryMoving(curr.fst))
			drawers[curr.fst] = curr;
		else if (tryMoving(curr.snd))
			drawers[curr.snd] = curr;
		else {
			printf("SMECE\n");
			continue;
		}

		printf("LADICA\n");
	}
}
