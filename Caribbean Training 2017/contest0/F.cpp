#include <cstdio>

const int maxn = 45;
long long f[maxn][2];
long long n, k;

int main(){
	scanf("%lld %lld", &n, &k);

	f[1][0] = f[1][1] = 1;
	for (int i = 2; i < maxn; i++){
		f[i][0] = f[i-1][0] + f[i-1][1];
		f[i][1] = f[i-1][0];
	}

	for (int i = n, l = 0; i > 0; i--){
		if (f[i][0] >= k){
			putchar('0');
		} else {
			putchar('1');
			k -= f[i][0];
		}
	}

	putchar('\n');
}
