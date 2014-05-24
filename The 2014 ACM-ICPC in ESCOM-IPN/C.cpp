// Accepted
#include <cstdio>
#include <algorithm>

#define MAXN 1010

using namespace std;

struct node {
	int next;
	bool isEnd;
	char c;
};

node tree[MAXN*MAXN];
short down[MAXN*MAXN];
int start[MAXN*MAXN];
int nextNode = 2;

int best = (1<<30);

int findChild(int x, char c){
	int i;
	for (i = start[x]; i && tree[i].c != c; i = tree[i].next);
	return i;
}

int addChild(int x, char c){
	int y = findChild(x,c);
	if (y) return y;
	tree[nextNode].c = c;
	tree[nextNode].next = start[x];
	start[x] = nextNode++;
	return start[x];
}

void insert(int n, char *s){
	if (*s == '\0'){
		tree[n].isEnd = true;
		return;
	}
	int next = addChild(n, *s);
	insert(next, s+1);
}

int downDist(int n){
	int m = 0;
	for (int i = start[n]; i; i = tree[i].next)
		m = max(m, downDist(i));
	return down[n] = 1 + m;
}

void dfs(int n, int toParent, bool shouldCount){
	int m = -1, sndM = -1;

	for (int i = start[n]; i; i = tree[i].next){
		if (down[i] > m){
			sndM = m;
			m = down[i];
		} else if (down[i] > sndM){
			sndM = down[i];
		}
	}

	if (max(m, toParent) < best)
		best = max(m, toParent);

	shouldCount |= sndM != -1;
	shouldCount |= tree[n].isEnd;

	if (!shouldCount) toParent = -1;

	for (int i = start[n]; i; i = tree[i].next){
		int newDist;

		if (down[i] != m)
			newDist = max(m + 1, toParent + 1);
		else
			newDist = max(sndM + 1, toParent + 1);

		dfs(i, newDist, shouldCount || tree[n].isEnd);
	}
}

int N;

int main(){
	int i;

	scanf("%d", &N);

	char tmp[1010];
	for (i = 0; i < N; i++){
		scanf("%s", tmp);
		insert(1, tmp);
	}

	downDist(1);

	dfs(1,0,false);

	printf("%d\n", best);
}
