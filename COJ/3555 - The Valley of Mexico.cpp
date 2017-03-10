#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 1010

int c, n;
bool v[MAXN][MAXN][2], dp[MAXN][MAXN][2], bst[MAXN][MAXN][2], adj[MAXN][MAXN];

#define nrm(z) ((z) <= 0 ? c : (z) > c ? 1 : (z))

bool f(int a, int b, int d){
	bool z = d == 1;

	a = nrm(a);
	b = nrm(b);

	if (nrm(a + d) == b) return true;

	if (v[a][b][z]) return dp[a][b][z];
	v[a][b][z] = true;

	bool l = adj[a][nrm(a+d)] && f(a + d, b, d);
	bool r = adj[a][nrm(b-d)] && f(b - d, a, -d);

	bst[a][b][z] = l ? 0 : 1;

	return dp[a][b][z] = l || r;
}

void reconstruct(int a, int b, int d){
	a = nrm(a);
	b = nrm(b);

	printf("%d\n", a);

	bool z = d == 1;

	if (nrm(a + d) != b){
		if (bst[a][b][z])
			reconstruct(b - d, a, -d);
		else
			reconstruct(a + d, b, d);
	}
}

int main(){
	scanf("%d %d", &c, &n);

	while (n--){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = adj[b][a] = true;
	}

	int i;

	for (i = 1; i <= c; i++){
		if (adj[i][nrm(i+1)]){
			if (f(i+1, i, 1)){
				printf("%d\n", i);
				reconstruct(i+1, i, 1);
				break;
			}
			if (f(i, i+1, -1)){
				printf("%d\n", nrm(i+1));
				reconstruct(i, i+1, -1);
				break;
			}
		}
	}

	if (i > c) printf("-1\n");
}
