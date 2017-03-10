#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 300030
#define mp make_pair
#define fst first
#define snd second

int N;
bool D[MAXN];
int X[MAXN], R[MAXN], C[MAXN], s[MAXN], se;
typedef int ll;
pair<pair<ll,ll>,pair<ll,ll>> e[MAXN*2];

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d %d", &X[i], &R[i]);
		e[2*i] = mp(mp(((ll)X[i]) - R[i], +1), mp(-R[i], i));
		e[2*i+1] = mp(mp(((ll)X[i]) + R[i], -1), mp(-R[i], i));
	}

	int inf = 2000000002;
	e[2*N] = mp(mp(-inf, +1), mp(-1000000001, N));
	e[2*N+1] = mp(mp(inf, -1), mp(-1000000001, N));
	N++;

	sort(e, e + 2*N);

	int ans = 0;
	for (int i = 0; i < 2*N; i++){
		if (i && se && e[i-1].snd.snd != e[i].snd.snd && e[i-1].fst.fst != e[i].fst.fst)
			D[s[se-1]] = true;
		if (e[i].fst.snd == -1){
			if (C[s[se-1]] == 0 || D[s[se-1]])
				ans++;
			else
				ans += 2;
			se--;
		} else {
			if (se)
				C[s[se-1]]++;
			s[se++] = e[i].snd.snd;
		}
	}

	printf("%d\n", ans);
}
