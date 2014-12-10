#include <cstdio>
#include <cstring>

int digsum(int x){
	int r = 0;
	for (; x; x /= 10) r += x % 10;
	return r;
}

int f(int x){
	return x < 10 ? x : f(digsum(x));
}

int main(void){
	int T, A;

	scanf("%d", &T);

	while (T--){
		char tmp[1010];
		scanf("%s", tmp);
		A = 0;
		for (int i = strlen(tmp)-1; i >= 0; i--) A += tmp[i] - '0';
		printf("%d\n", f(A));
	}
}
