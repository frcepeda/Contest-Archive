#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;

int main(){
	while (scanf("%lld", &n), n){
		long double ans = sqrt((long double)n*(n+1)/3);
		printf("%.8Lf\n", ans);
	}
}
