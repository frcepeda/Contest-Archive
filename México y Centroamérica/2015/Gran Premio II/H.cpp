#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 3010
#define fst first
#define snd second

typedef pair<int,int> pii;
int N;
pii P[MAXN];

int main(){
	while (scanf("%d", &N) == 1){
		int i;

		for (i = 0; i < N; i++)
			scanf("%d %d", &P[i].fst, &P[i].snd);

		sort(P, P + N);

		int ans = 0;

		for (int i = 0; i < N; i++){
			int up = 100001000, down = -100001000;

			for (int j = i+1; j < N; j++){
				if (P[j].snd > P[i].snd && P[j].snd < up){
					up = P[j].snd;
					ans++;
				} else if (P[j].snd < P[i].snd && P[j].snd > down){
					down = P[j].snd;
					ans++;
				}
			}
		}

		printf("%d\n", ans);
	}
}
