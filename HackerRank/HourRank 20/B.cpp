#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 500100;
ll mod = 1000000007;
int n, q;
char s[maxn];

ll modexp(ll b, ll e){
	ll x = 1;

	for (; e; e /= 2){
		if (e % 2)
			x = (x * b) % mod;
		b = (b * b) % mod;
	}

	return x;
}

ll go(char x, char y){
	ll ans = 1, X = 0, Y = 0;

	int i;
	for (i = 1; s[i] != '\0'; i++){
		if (s[i] == x){
			X++;
		} else if (s[i] == y){
			Y++;
		}
	}

	return ans;
}

int main(){
	scanf("%d", &q);
	
	while (q--){
		scanf("%s", s+1);
		n = strlen(s+1);

		ll ab = go('a', 'b');
		ll cd = go('c', 'd');

		printf("%lld\n", (ab * cd - 1) % mod);
	}
}
