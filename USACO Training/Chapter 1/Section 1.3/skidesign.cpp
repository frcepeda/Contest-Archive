/*
    ID: frceped1
    LANG: C++
    TASK: skidesign
 */

#include <cstdio>
#include <algorithm>
using namespace std;

#ifdef LOCAL
	#define openFiles()
#else
	#define openFiles() freopen("skidesign.in", "r", stdin); freopen("skidesign.out", "w", stdout)
#endif

// USACO upload macros

#define sq(x) ((x)*(x))

int N;
int h[1000];

int f(int x){
	int r = 0;

	for (int i = 0; i < N; i++)
		if (h[i] < x)
		       r += sq(h[i] - x);
		else if (x + 17 < h[i])
		       r += sq(h[i] - x - 17);

	return r;
}

int main(void){
	openFiles();

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &h[i]);

	int ans = 1<<30;

	for (int i = 0; i < 100; i++)
		ans = min(ans, f(i));

	printf("%d\n", ans);
}
