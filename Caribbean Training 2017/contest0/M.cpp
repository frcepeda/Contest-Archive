#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

int n;

int main(){
	scanf("%d", &n);

	__int128 k = 1;

	for (int i = 1; i <= n; i++){
		k = i * k / __gcd((__int128)i, k);
		assert(k < __int128(1ULL<<63));
	}

	printf("%lld\n", (long long)k);
}
