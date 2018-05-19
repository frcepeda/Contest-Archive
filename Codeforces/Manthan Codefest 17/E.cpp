#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
string n;

int dp[100][1<<10][2][2];
int B, t;

ll f(ll x){
	if (x == 0) return 0;
	for (n = ""; x; x /= B)
		n.push_back((x % B) + '0');
	reverse(n.begin(), n.end());
	//fprintf(stderr, "%s\n", n.c_str());
	t++;
	for (int i = n.size(); i >= 0; i--){
	for (int b = 0; b < 2; b++){
	for (int e = 0; e < 2; e++){
	for (int l = 0; l < 2; l++){
		if (i == n.size()) return b == 0 && !l;

		for (int x = 0; x <= (e ? n[i] - '0' : B-1); x++)
			t += dp[i+1][b ^ (l && x == 0 ? 0 : (1<<x))][e && x == n[i] - '0'][l && x == 0];
	}
	}}}
	//fprintf(stderr, "%lld\n", r);
	return dp[0][0][1][1];
}

int main(){
	int q;
	scanf("%d", &q);

	while (q--){
		ll l, r;
		scanf("%d %lld %lld", &B, &l, &r);
		printf("%lld\n", f(r) - f(l-1));
	}
}
