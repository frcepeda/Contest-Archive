#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int n, k, a[maxn];

int main(){
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int m = a[0];

	for (int i = 1; i < n; i++){
		m = min(m, a[i]);
		if (a[i] % k != a[0] % k){
			cout << -1 << endl;
			return 0;
		}
	}

	long long ans = 0;

	for (int i = 0; i < n; i++)
		ans += (a[i] - m) / k;

	cout << ans << endl;
}
