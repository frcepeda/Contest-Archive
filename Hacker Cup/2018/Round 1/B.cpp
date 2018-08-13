#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2010;
int T, K, N, A[maxn], B[maxn];
int pre[maxn], post[maxn], label[maxn];
int npre, npost;

int p[maxn];

int id(int x){
	if (p[x] == x) return x;
	return p[x] = id(p[x]);
}

int join(int a, int b){
	p[id(a)] = id(b);
}

void preorder(int node){
	pre[npre++] = node;

	if (A[node]) preorder(A[node]);
	if (B[node]) preorder(B[node]);
}

void postorder(int node){
	if (A[node]) postorder(A[node]);
	if (B[node]) postorder(B[node]);

	post[npost++] = node;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		printf("Case #%d:", t);

		scanf("%d %d", &N, &K);

		for (int i = 1; i <= N; i++)
			scanf("%d %d", &A[i], &B[i]);

		npre = 0;
		preorder(1);
		npost = 0;
		postorder(1);

		for (int i = 1; i <= N; i++){
			label[i] = 0;
			p[i] = i;
		}

		for (int i = 0; i < N; i++)
			join(pre[i], post[i]);

		int nextl = 1;
		bool ok = false;
		for (int i = 1; i <= N; i++){
			if (label[id(i)]) continue;

			label[id(i)] = nextl;

			nextl++;
			if (nextl > K){
				ok = true;
				nextl = 1;
			}
		}

		if (!ok) printf(" Impossible");
		else for (int i = 1; i <= N; i++)
			printf(" %d", label[id(i)]);
		putchar('\n');

		if (ok)
			for (int i = 0; i < N; i++)
				assert(label[id(pre[i])] == label[id(post[i])]);
	}
}
