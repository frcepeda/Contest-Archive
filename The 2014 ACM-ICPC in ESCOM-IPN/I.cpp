// Accepted
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define MAXN 310000

#define UNVISITED (-1)
#define MULTIPLE (-2)
#define UNKNOWN (-3)

int N, Q;
map<int,int> nums;
int tree[MAXN*4];
int queries[100100];
int lo[100100], hi[100100];
char names[100100][22];

void buildSegTree(int n, int l, int r){
	tree[n] = UNVISITED;

	if (l != r){
		buildSegTree(2*n+1, l, (l+r)/2);
		buildSegTree(2*n+2, (l+r)/2+1, r);
	}
}

void insert(int n, int l, int r, int cl, int cr, int ci){
	if (cr < l || cl > r || cl > cr) return;
	if (tree[n] == MULTIPLE) return;

	if (tree[n] != UNKNOWN && cl <= l && r <= cr){
		if (tree[n] == UNVISITED)
			tree[n] = ci;
		else
			tree[n] = MULTIPLE;
	} else {
		if (tree[n] != UNKNOWN && tree[2*n+1] == UNVISITED)
			tree[2*n+1] = tree[n];
		if (tree[n] != UNKNOWN && tree[2*n+2] == UNVISITED)
			tree[2*n+2] = tree[n];

		insert(2*n+1, l, (l+r)/2, cl, cr, ci);
		insert(2*n+2, (l+r)/2+1, r, cl, cr, ci);

		tree[n] = UNKNOWN;
	}
}

int query(int n, int l, int r, int q){
	if (tree[n] != UNKNOWN) return tree[n];

	if (q <= (l+r)/2)
		return query(2*n+1, l, (l+r)/2, q);
	else
		return query(2*n+2, (l+r)/2+1, r, q);
}

int main(){
	int i, m;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%s %d %d", names[i], &lo[i], &hi[i]);
		nums[lo[i]] = 0;
		nums[hi[i]] = 0;
	}

	scanf("%d", &Q);

	for (i = 0; i < Q; i++){
		scanf("%d", &queries[i]);
		nums[queries[i]] = 0;
	}

	m = 1;
	for (map<int,int>::iterator it = nums.begin(); it != nums.end(); it++)
		it->second = m++;
	m--;

	buildSegTree(0, 1, m);

	for (i = 0; i < N; i++)
		insert(0, 1, m, nums[lo[i]], nums[hi[i]], i);

	for (i = 0; i < Q; i++){
		int ans = query(0, 1, m, nums[queries[i]]);
		if (ans == UNVISITED)
			printf("NONE\n");
		else if (ans == MULTIPLE)
			printf("MULTIPLE\n");
		else
			printf("%s\n", names[ans]);
	}
}
