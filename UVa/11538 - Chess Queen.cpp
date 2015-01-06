#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long n, m, a;
	
	while (scanf("%lld %lld", &n, &m), (n || m)){
		a = min(n-1, m-1);
		printf("%lld\n", (m+n-2)*m*n + 4*(a*(a+1)/2*(n+m-1) - a*(a+1)*(2*a+1)/3));
	}
}