#include <cstdio>
#include <set>
#include <algorithm>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

const int maxn = 1010;
int T, N;
typedef long double ld;
typedef pair<ld,ld> pdd;
ld D;
pdd X[maxn], v[maxn];

bool works(ld x){
	for (int i = 0; i < N; i++)
		if (x * v[i].snd > v[i].fst)
			return false;

	return true;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%Lf %d", &D, &N);

		for (int i = 0; i < N; i++)
			scanf("%Lf %Lf", &X[i].fst, &X[i].snd);

		sort(X, X + N);

		for (int i = 0; i < N; i++){
			ld Ki = X[i].fst, Si = X[i].snd;

			ld tt = (D - Ki) / Si;

			for (int j = i+1; j < N; j++){
				ld Kj = X[j].fst, Sj = X[j].snd;
				if (Si > Sj){
					ld tx = (Kj - Ki) / (Si - Sj);
					if (tx > v[j].snd)
						tt = min(tt, tx);
				}
			}

			v[i] = mp(Ki + Si*tt, tt);
		}

		ld lo = 0, hi = 1e20, mid;

		for (int i = 0; i < 500; i++){
			mid = (lo + hi)/2;
			if (works(mid))
				lo = mid;
			else
				hi = mid;
		}

		printf("Case #%d: %.8Lf\n", t, hi);
	}
}
