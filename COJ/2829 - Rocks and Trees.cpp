#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10010

int N, T, L, X;
int P[MAXN], R[MAXN], D[MAXN];

int main(){
	scanf("%d %d %d", &N, &T, &L);
	
	for (int i = 2; i <= N; i++){
		scanf("%d %d", &P[i], &R[i]);
		D[i] = D[P[i]] + 1;
		if (D[i] % 2)
			X ^= R[i] % (L+1);
	}

	while (T--){
		int a, b;
		scanf("%d %d", &a, &b);

		if (D[a] % 2){
			X ^= R[a] % (L+1);
			R[a] = b;
			X ^= R[a] % (L+1);
		}
		
		printf("%s\n", X ? "Yes" : "No");
	}
}
