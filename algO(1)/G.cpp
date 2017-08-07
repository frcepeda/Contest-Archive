#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 15100;

typedef long long ll;

ll T, M, N, H[maxn];

bool works(ll x){
	__int128 total = 0;

	for (int i = 0; i < N; i++)
		total += x / H[i];

	return total >= M;
}

int main(){
	cin >> T;

	while (T--){
		cin >> M >> N;

		for (int i = 0; i < N; i++)
			cin >> H[i];

		ll lo = 0, hi = 1000000000000000001L, mid;

		while (lo < hi){
			mid = (lo + hi) / 2;

			if (works(mid))
				hi = mid;
			else
				lo = mid + 1;
		}

		cout << hi << endl;
	}
}
