#include <cstdio>
#include <cassert>
#include <bitset>
#include <algorithm>

using namespace std;

int T;
long long N;

long long solve(long long x){
	bitset<10> b;
	long long y;

	if (!x) return x;

	for (y = x; !b.all(); y += x)
		for (auto z = y; z; z /= 10)
			b[z % 10] = true;

	return y - x;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%lld", &N);

		auto z = solve(N);
		printf("Case #%d: ", t);

		if (z)
			printf("%lld\n", solve(N));
		else
			printf("INSOMNIA\n");
	}
}
