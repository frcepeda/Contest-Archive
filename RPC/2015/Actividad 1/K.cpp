#include <cstdio>
#include <algorithm>

using namespace std;

long long n, p;

int main(){
	scanf("%lld %lld", &n, &p);
	printf("%s\n", n/3 < p and p < n+1 - (n+1)/3 ? "YES" : "NO");
}
