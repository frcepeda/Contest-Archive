#include <cstdio>
#include <cctype>

#define MAXS 10100
#define MAXK 110

int T, N, K;
char str[MAXS];
char sq[MAXK][MAXK];

bool makeSquare(){
	for (K = 1; K*K < N; K++);

	if (K*K != N) return false;

	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			sq[i][j] = str[i*K + j];

	return true;
}

bool isMagic(){
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			if (sq[i][j] != sq[K-i-1][K-j-1] || sq[j][i] != sq[K-j-1][K-i-1])
				return false;
	return true;
}

int main(){
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++){
		char c;
		N = K = 0;

		printf("Case #%d:\n", t);

		while ((c = getchar()) != '\n' && c != EOF)
			if (isalpha(c))
				str[N++] = c;

		if (makeSquare() && isMagic())
			printf("%d\n", K);
		else
			printf("No magic :(\n");
	}
}
