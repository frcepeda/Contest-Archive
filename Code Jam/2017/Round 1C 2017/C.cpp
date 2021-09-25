#include <iostream>
#include <iomanip>
#include <algorithm>

#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 55;
int T, N, K;
ld U, P[maxn];

bool works(ld x){
	ld acc = 0;

	for (int i = 0; i < N; i++)
		acc += max(ld(0), x - P[i]);

	return acc <= U;
}

int main(){
	cin >> T;
	cout << setprecision(10) << fixed;

	for (int t = 1; t <= T; t++){
		cin >> N >> K;
		cin >> U;

		for (int i = 0; i < N; i++)
			cin >> P[i];
		
		ld lo = 0, hi = 1, mid;

		for (int i = 0; i < 50; i++){
			mid = (lo + hi) / 2;

			if (works(mid))
				lo = mid;
			else
				hi = mid;
		}

		ld ans = 1;

		for (int i = 0; i < N; i++)
			ans *= max(P[i], hi);

		cout << "Case #" << t << ": " << ans << endl;
	}
}
