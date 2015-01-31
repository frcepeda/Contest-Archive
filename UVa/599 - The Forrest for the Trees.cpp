// Accepted
// Use union-find to count trees only once. A node is an acorn if no edge is adjacent to it.
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 30

int N, T;
bool adj[MAXN];
int p[MAXN];

int id(int x){
	if (x == p[x]) return x;
	return p[x] = id(p[x]);
}

void join(int a, int b){
	p[id(a)] = id(b);
}

int main() {
	scanf("%d", &T);
	getchar();
	
	while (T--){
		int t = 0, a = 0;
		char c, A, B;
		
		fill(adj, adj + MAXN, false);
		for (int i = 0; i < MAXN; i++)
			p[i] = i;
		
		while (getchar() == '('){
			A = getchar();
			getchar();
			B = getchar();
			getchar(); getchar();
			join(A - 'A', B - 'A');
			adj[A - 'A'] = true;
			adj[B - 'A'] = true;
		}
		
		while ((c = getchar()) == '*');
		
		do {
			A = getchar();
			if (adj[A - 'A']) t += id(A - 'A') == A - 'A';
			else a++;
		} while (getchar() == ',');
		
		printf("There are %d tree(s) and %d acorn(s).\n", t, a);
	}
}