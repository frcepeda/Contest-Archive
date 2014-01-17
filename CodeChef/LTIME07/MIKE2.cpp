#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000010

long long X;
int N, A[MAXN];
int fail, succ;

int main(){
	int i;

	scanf("%d %lld", &N, &X);
	fail = N;

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	sort(A, A+N);

	for (i = 0; i < N && (A[i]+1)/2 <= X; i++, fail--){
		X -= (A[i]+1)/2;
		A[i] -= (A[i]+1)/2;
	}

	for (i = 0; i < N && A[i] <= X; i++, succ++)
		X -= A[i];

	printf("%d %d\n", fail, succ);
}
