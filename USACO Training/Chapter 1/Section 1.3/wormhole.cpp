/*
    ID: frceped1
    LANG: C++
    TASK: wormhole
 */

#include <cstdio>
#include <algorithm>
using namespace std;

#ifdef LOCAL
	#define openFiles()
#else
	#define openFiles() freopen("wormhole.in", "r", stdin); freopen("wormhole.out", "w", stdout)
#endif

// USACO upload macros

#define fst first
#define snd second

typedef pair<int,int> pii;

int N;
pii p[12];
int q[12];
bool v[12];

bool infinite(int x){
	bool w[12] = {false};

	while (!w[x]){
		w[x] = true;

		int next = -1;

		for (int i = 0; i < N; i++)
			if (i != x && p[i].snd == p[x].snd &&
			    p[i].fst >= p[x].fst &&
			    (next == -1 || p[next].fst > p[i].fst))
				next = i;


		if (next == -1)
			return false;

		x = q[next];
	}

	return true;
}

bool loop(){
	for (int i = 0; i < N; i++)
		if (infinite(i))
			return true;

	return false;
}

int f(int i){
	if (i == N) return loop();
	if (v[i]) return f(i+1);
	v[i] = true;

	int r = 0;
	for (int j = i+1; j < N; j++){
		if (!v[j]){
			q[i] = j; q[j] = i;

			v[j] = true;
			r += f(i+1);
			v[j] = false;
		}
	}

	v[i] = false;
	return r;
}

int main(void){
	openFiles();

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &p[i].fst, &p[i].snd);

	printf("%d\n", f(0));
}
