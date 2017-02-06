#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n;

bool isprime(ll x){
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (ll i = 3; i*i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

ll go(ll x){
	for (x -= 2; !isprime(x); x--);
	return x;
}

ll f(ll x){
	int ans = 0;
	for (; !isprime(x); ans++)
		x -= go(x);
	return ans + 1;
}

const int maxdp = 1000000;
int dp[maxdp];

int main(){
	cin >> n;

	if (isprime(n))
		cout << 1 << endl;
	else if (n % 2 == 0 || isprime(n-2))
		cout << 2 << endl;
	else
		cout << 3 << endl;
}
