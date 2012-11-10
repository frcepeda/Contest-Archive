#include <stdio.h>
#include <stdbool.h>

#define MAXN 100010

typedef struct {
	int time, start, diff;
} comp;

comp comps[MAXN];
int N, M;

long long int max(int a, int b){
	return a > b ? a : b;
}

void stroll(int T, int A, int B){
	bool something = false;
	long long int best = -(1<<30);

	for (; A <= B; A++){
		if (comps[A].time){
			something = true;
			best = max(best, comps[A].start + (T - comps[A].time) * comps[A].diff);
		}
	}

	if (something)
		printf("%lld\n", best);
	else
		printf("nema\n");
}

int main(void){
	int i;

	scanf("%d %d", &N, &M);

	while (M--){
		int T, K, Z, S, A, B;
		scanf("%d", &i);

		if (i == 1){
			scanf("%d %d %d %d", &T, &K, &Z, &S);
			comps[K].start = S;
			comps[K].time = T;
			comps[K].diff = Z;
		} else {
			scanf("%d %d %d", &T, &A, &B);
			if (A > B){
				K = A;
				A = B;
				B = K;
			}
			stroll(T,A,B);
		}
	}

	return 0;
}
