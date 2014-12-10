#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long a, b, ans;

int main(){
	scanf("%lld %lld", &a, &b);

	long long c = (a + b * (a * (a+1) / 2 % MOD)) % MOD;

	for (long long m = 1; m < b; m++)
		ans = (ans + m * c) % MOD;

	printf("%lld\n", ans);
}
