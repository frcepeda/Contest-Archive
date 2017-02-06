#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int q;
ll n;

const int lim = 1000000;
bool dp[lim];

int main(){
	cin >> q;

	dp[0] = true;
	for (int i = 1; i < lim; i++)
		dp[i] = (i-4 >= 0 && dp[i-4]) || (i-7 >= 0 && dp[i-7]);

	while (q--){
		cin >> n;
		cout << (n >= lim || dp[n] ? "Yes" : "No") << endl;
	}
}
