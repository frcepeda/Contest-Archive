#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100100
#define mp make_pair
#define fst first
#define snd second

int N;
int H[MAXN];
pair<int, bool> e[MAXN];
bool U[MAXN], D[MAXN];

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &H[i]);

	N = unique(H, H + N) - H;

	for (int i = 1; i < N-1; i++)
		D[i] = (!i || H[i-1] > H[i]) && (i == N-1 || H[i] < H[i+1]);
	for (int i = 0; i < N; i++)
		U[i] = (!i || H[i-1] < H[i]) && (i == N-1 || H[i] > H[i+1]);

	int ei = 0;
	for (int i = 0; i < N; i++){
		if (D[i]) e[ei++] = mp(H[i], true);
		if (U[i]) e[ei++] = mp(H[i], false);
	}

	sort(e, e + ei);

	int c = 1, ans = 1;
	for (int i = 0; i < ei; i++){
		c += (e[i].snd ? 1 : -1);
		if (i == ei-1 || e[i].fst != e[i+1].fst)
			ans = max(ans, c);
	}

	printf("%d\n", ans);
}
