#include <cstdio>

using namespace std;

int N, A, B, C;

bool solve(){
	int i, j, k;
	
	for (i = -100; i <= 100; i++){
		for (j = i+1; j <= 100; j++){
			k = A - i - j;
			if (i == k || j == k || k < j) continue;
			if (i * j * k != B) continue;
			if (i*i + j*j + k*k != C) continue;
			printf("%d %d %d\n", i, j, k);
			return true;
		}
	}
	
	return false;
}

int main() {
	scanf("%d", &N);
	
	while (N--){
		scanf("%d %d %d", &A, &B, &C);
		if (!solve()) printf("No solution.\n");
	}
}