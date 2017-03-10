#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define MAXN 2010
#define B 29
typedef unsigned long long ll;

int N;
char s[2][MAXN];
ll h[2][MAXN][MAXN];
int m[256];
set<ll> u;

void __hash(int x){
	for (int i = 0; i < N; i++){
		int l = 1;

		fill(m + 'a', m + 'z' + 1, 0);

		h[x][i][i] = 1;
		m[s[x][i]] = l++;

		for (int j = i+1; j < N; j++){
			if (m[s[x][j]] == 0)
				m[s[x][j]] = l++;
			h[x][i][j] = ll(h[x][i][j-1]) * B + m[s[x][j]];
		}
	}
}

bool works(int i){
	u.clear();

	for (int k = 0; k+i <= N; k++)
		u.insert(h[0][k][k+i-1]);

	for (int k = 0; k+i <= N; k++)
		if (u.find(h[1][k][k+i-1]) != u.end())
			return true;

	return false;
}

int main(){
	scanf("%d", &N);
	scanf("%s", s[0]);
	scanf("%s", s[1]);

	copy(s[0], s[0] + N, s[0] + N);
	copy(s[1], s[1] + N, s[1] + N);
	N *= 2;

	__hash(0);
	__hash(1);

	int lo = 1, hi = N/2, mid;
	while (lo <= hi){
		mid = (lo + hi)/2;
		if (works(mid))
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	printf("%d\n", lo - 1);
}
