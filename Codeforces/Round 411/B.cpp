#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

const int maxn = 1000100;
ll p[maxn];

int main(){
	string s;

	cin >> s;

	ll a = 0, ans = 0;

	p[0] = 1;
	for (int i = 1; i < maxn; i++)
		p[i] = (p[i-1] * 2) % mod;

	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'a') a++;
		else ans = (ans + p[a] - 1) % mod;
	}
	
	cout << ans << endl;
}
