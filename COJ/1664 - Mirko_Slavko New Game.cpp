#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int N, A[110], B[110];

int f(){
	int l = 1, r = 99;
	int a[110], b[110];

	for (int i = 0; i <= 100; i++){
		a[i] = A[i];
		b[i] = B[i];
	}

	int w = 0;
	for (; l <= 100; l++)
		while (a[l]){
			int m = min(a[l], b[r]);
			if (m > 0){
				a[l] -= m;
				b[r] -= m;
				w = max(w, l + r);
			}
			if (b[r] == 0) r--;
		}

	return w;
}

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		A[a]++; B[b]++;
		printf("%d\n", f());
	}
}
