#include <cstdio>
#include <algorithm>

#define MAXN 110

using namespace std;

int S[MAXN];
int sets[2][MAXN*MAXN*MAXN];
int setSize[2];
int N;
long long unsigned int answer;

int main(void){
	int i, j, k, a, b;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &S[i]);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				sets[0][setSize[0]++] = S[i] * S[j] + S[k];

	for (i = 0; i < N; i++)
		if (S[i] != 0)
			for (j = 0; j < N; j++)
				for (k = 0; k < N; k++)
					sets[1][setSize[1]++] = S[i] * (S[j] + S[k]);

	sort(sets[0], sets[0] + setSize[0]);
	sort(sets[1], sets[1] + setSize[1]);

	i = j = 0;
	while (i < setSize[0] && j < setSize[1]){
		while (sets[0][i] < sets[1][j] && i < setSize[0]) i++;
		while (sets[1][j] < sets[0][i] && j < setSize[1]) j++;
		if (i >= setSize[0] || j >= setSize[1]) break;

		a = b = 0;
		k = sets[0][i];

		while (sets[0][i] == sets[1][j] && i < setSize[0]) i++, a++;
		while (sets[1][j] == k && j < setSize[1]) j++, b++;

		answer += a * b;
	}

	printf("%llu\n", answer);

	return 0;
}
