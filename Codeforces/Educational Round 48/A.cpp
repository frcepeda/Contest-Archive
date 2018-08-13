#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int maxn = 200100;
ll n, m, a[maxn];

int main(){
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll acc = 0;
	for (int i = 0; i < n; i++){
		cout << (acc + a[i]) / m;
		acc = (acc + a[i]) % m;
		cout << (i < n-1 ? ' ' : '\n');
	}
}
