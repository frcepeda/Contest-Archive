#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXD 1010

int t, T, D, P[MAXD];

int f(int y){
	int r = 0;

	for (int i = 0; i < D; i++)
		r += (P[i] + y - 1) / y - 1;

	return r;
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d", &D);

		for (int i = 0; i < D; i++)
			scanf("%d", &P[i]);

		int best = 1<<25;

		for (int i = 1; i < 1010; i++)
			best = min(best, i + f(i));

		printf("Case #%d: %d\n", t, best);
	}
}
