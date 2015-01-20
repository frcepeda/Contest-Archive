#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10000100

int primacity[MAXN];
int T, A, B, K;

int main(){
	int i, j;

	for (i = 2; i < MAXN; i += 2)
		primacity[i]++;

	for (i = 3; i < MAXN; i += 2)
		if (!primacity[i])
			for (j = i; j < MAXN; j += i)
				primacity[j]++;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %d %d", &A, &B, &K);
		int ans = 0;
		for (int i = A; i <= B; i++)
			if (primacity[i] == K)
				ans++;
		printf("Case #%d: %d\n", t, ans);
	}
}
