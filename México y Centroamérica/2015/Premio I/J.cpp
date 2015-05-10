#include <cstdio>

#define MAXN 30

using namespace std;

int K, N;
int A[MAXN];

int main(){
	while (scanf("%d %d", &K, &N), (K || N)){
		int i, j, ans = 0;

		for (i = 0; i < N; i++)
			scanf("%d", &A[i]);

		for (i = 1; i <= K; i++){
			for (j = 0; j < N; j++)
				if (i % A[j] == 0)
					break;
			if (j < N)
				ans++;
		}

		printf("%d\n", ans);
	}
}
