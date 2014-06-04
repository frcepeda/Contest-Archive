#include <stdio.h>

int N, M;

int main(void){
	while (scanf("%d %d", &N, &M) == 2 && (N != 0 || M != 0)){
		int fst[10] = {0};
		int snd[10] = {0};
		int i, j, a;

		for (i = 0; i < N; i++){
			scanf("%d", &a);
			for (j = 2; j <= a; j++)
				fst[j]++;
		}

		for (i = 0; i < M; i++){
			scanf("%d", &a);
			for (j = 2; j <= a; j++)
				snd[j]++;
		}

		fst[2] += 2*fst[4] + fst[6] + 3*fst[8];
		fst[3] += 2*fst[9] + fst[6];
		fst[4] = fst[6] = fst[8] = fst[9] = 0;

		snd[2] += 2*snd[4] + snd[6] + 3*snd[8];
		snd[3] += 2*snd[9] + snd[6];
		snd[4] = snd[6] = snd[8] = snd[9] = 0;

		j = 1;
		for (i = 0; i < 10; i++)
			j &= fst[i] == snd[i];

		printf("%s\n", j ? "YES" : "NO");
	}

	return 0;
}
