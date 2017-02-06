#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int N, M;
int A[maxn], B[maxn];
long long S[maxn];

int main(){
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &B[i]);

	sort(A, A + N);
	sort(B, B + M);

	for (int i = 0; i < N; i++)
		S[i] = A[i] + (i ? S[i-1] : 0);

	int j = 0;

	long long ans = 0;

	for (int i = 0; i < M; i++){
		for (; j < N && A[j] < B[i]; j++);

		ans += S[N-1] - 2*(j ? S[j-1] : 0) + (2*j - N)*(long long)B[i];
	}

	printf("%lld\n", ans);
}
