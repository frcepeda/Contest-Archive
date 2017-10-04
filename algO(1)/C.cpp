#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1010;

int T, N;
ll ans[maxn];

int main(){
	cin >> T;

	ans[1] = 1;
	ans[2] = 2;

	for (int i = 3; i < maxn; i++)
		ans[i] = i + ans[i-2];

	while (T--){
		cin >> N;
		cout << ans[N] << endl;
	}
}
