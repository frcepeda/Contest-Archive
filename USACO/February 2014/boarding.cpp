// WA 1/10
#include <cstdio>
#include <algorithm>

using namespace std;

#define UPLOAD 0

#if UPLOAD
	#define openFiles() freopen("boarding.in", "r", stdin); freopen("boarding.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 200100

#define fst first
#define snd second
#define mp make_pair

typedef pair<int,int> pii;

int N;
int S[MAXN], T[MAXN];

int ans;
pii BIT[MAXN];

pii _max(pii a, pii b){
	if (a.snd == 0)
		return b;
	if (b.snd == 0)
		return a;
	if (a.fst > b.fst)
		return a;
	if (a.fst < b.fst)
		return b;
	return a.snd < b.snd ? a : b;
}

void update(int i, pii m){
	for (; i < MAXN; i += i&-i)
		BIT[i] = _max(BIT[i], m);
}

pii query(int i){
	pii r = mp(0, 1);
	for (; i; i -= i&-i)
		r = _max(r, BIT[i]);
	return r;
}

int main(void){
	int i;

	openFiles();

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d %d", &S[i], &T[i]);

	for (i = N-1; i >= 0; i--){
		pii b = query(S[i]);

		int toBSnd = max(b.fst + 1, b.snd - (i-(N-1)));
		int toS_i = S[i] - b.snd;

		update(S[i], mp(toBSnd + toS_i + T[i], S[i]));
	}

	printf("%d\n", query(N).fst);
}
