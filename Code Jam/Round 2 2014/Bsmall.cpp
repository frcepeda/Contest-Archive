#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010

int T;
int N, A[MAXN];
int tmp[MAXN], _ans[MAXN];

bool isUpDown(){
	int i;
	for (i = 0; i < N-1 && tmp[i] < tmp[i+1]; i++);
	for (; i < N-1 && tmp[i] > tmp[i+1]; i++);
	return i == N-1;
}

int cost(){
	int i, j, c = 0;
	int tmp2[MAXN];
	for (i = 0; i < N; i++)
		tmp2[i] = A[i];
	for (i = 0; i < N; i++){
		for (j = i; tmp2[j] != tmp[i]; j++);
		for (j--; j >= i; j--, c++)
			swap(tmp2[j], tmp2[j+1]);
	}
	return c;
}

int main(){
	int t;
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int ans = 1<<30, i;

		scanf("%d", &N);

		for (i = 0; i < N; i++){
			scanf("%d", &A[i]);
			tmp[i] = A[i];
		}

		sort(tmp, tmp + N);

		do {
			if (isUpDown()){
				int x = cost();
				ans = min(ans, x);
				if (x == 6){
					for (i = 0; i < N; i++)
						printf("%d ", tmp[i]);
					printf("\n");
				}
			}
		} while (next_permutation(tmp, tmp + N));

		printf("Case #%d: %d\n", t, ans);
	}
}
