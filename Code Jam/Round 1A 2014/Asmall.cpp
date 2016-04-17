#include <cstdio>
#include <algorithm>

using namespace std;

int N, L, T;

typedef unsigned long long ull;

ull out[200], in[200];
ull tmp[200];

int main(){
	ull t, i, j;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int best = 10000;

		scanf("%d %d", &N, &L);

		for (i = 0; i < N; i++){
			out[i] = 0;
			for (j = 0; j < L; j++){
				char c;
				while (!isdigit(c = getchar()));
				out[i] |= ((ull)(c - '0')) << j;
			}
		}

		for (i = 0; i < N; i++){
			in[i] = 0;
			for (j = 0; j < L; j++){
				char c;
				while (!isdigit(c = getchar()));
				in[i] |= ((ull)(c - '0')) << j;
			}
		}

		sort(in, in + N);

		for (i = 0; i < (1<<L); i++){
			for (j = 0; j < N; j++)
				tmp[j] = out[j] ^ i;
			sort(tmp, tmp + N);
			if (equal(tmp, tmp + N, in))
				best = min(best, __builtin_popcount(i));
		}

		if (best < 10000)
			printf("Case #%lld: %d\n", t, best);
		else
			printf("Case #%lld: NOT POSSIBLE\n", t);
	}
}
