#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll n, k, ans;

	cin >> n >> k;

	ll top = min(k-1, n);
	ll mid = k/2;

	cout << max(0LL, top - mid) << endl;
}
