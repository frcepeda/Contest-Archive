#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int T, L, R, N, a[maxn], v[maxn];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--){
		cin >> L >> R >> N;

		bool dir = true;
		int loc = R;

		for (int i = 1; i <= N; i++)
			cin >> a[i];

		a[++N] = L;

		for (int i = 1; i <= N; i++){
			v[i] = v[i-1] + (a[i] - a[i-1]) * (dir ? 1 : -1);

			dir = !dir;

			if (a[i] <= R)
				loc = v[i] + (R - a[i]) * (dir ? 1 : -1);
		}

		int ans = 0;

		for (int i = 0; i <= N; i++)
			ans = max(ans, abs(loc - v[i]));

		cout << ans << endl;
	}
}
