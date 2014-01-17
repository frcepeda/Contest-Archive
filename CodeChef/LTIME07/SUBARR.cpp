#include <cstdio>
#include <set>

using namespace std;

#define MAXN 150010

int N, K, ans;
long long A[MAXN];

int main(){
	int i, j;

	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++){
		scanf("%lld", &A[i]);
		A[i] += A[i-1];
	}

	if (K){
		for (i = 1; i <= N; i++)
			for (j = i; j <= N; j++)
				if ((A[j] - A[i-1])/(j-i+1) >= K)
					ans++;
	} else {
		for (i = 1; i <= N; i++){
			int k = A[i];
			for (j = i; j > 1 && A[j-1] > k; j--)
				A[j] = A[j-1];
			A[j] = k;
			ans += j;
		}
	}

	printf("%d\n", ans);
}
