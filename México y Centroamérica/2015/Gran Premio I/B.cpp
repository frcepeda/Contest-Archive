#include <cstdio>

using namespace std;

long long X;

int main(){
	while (scanf("%lld", &X), X){
		long long lo = 0, hi = 100000, mid;

		while (lo < hi){
			mid = (lo + hi) / 2;

			if (mid * (mid+1) / 2 > X)
				hi = mid;
			else
				lo = mid + 1;
		}

		printf("%lld %lld\n", hi*(hi+1)/2 - X, hi);
	}
}
