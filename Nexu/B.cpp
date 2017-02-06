#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n;

	ll prev = 0, curr;
	ll ans = LLONG_MIN;

	scanf("%d", &n);

	while (n--){
		scanf("%lld", &curr);
		curr += max(0LL, prev);
		ans = max(ans, curr);
		prev = curr;
	}

	printf("%lld\n", ans);
}
