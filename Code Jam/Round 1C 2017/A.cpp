#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>

#define fst first
#define snd second

using namespace std;

typedef long long ll;

const int maxn = 1010;
int T, N, K;
pair<ll,ll> P[maxn];

int main(){
	cin >> T;
	cout << setprecision(10) << fixed;

	const long double pi = acos(-1);

	for (int t = 1; t <= T; t++){
		cin >> N >> K;

		for (int i = 0; i < N; i++)
			cin >> P[i].fst >> P[i].snd;

		sort(P, P + N);

		priority_queue<ll, vector<ll>, greater<ll>> pq;

		long long sum = 0;
		long double ans = 0;

		for (int i = 0; i < K-1; i++){
			sum += P[i].fst * P[i].snd;
			pq.push(P[i].fst * P[i].snd);
		}

		for (int i = K-1; i < N; i++){
			sum += P[i].fst * P[i].snd;
			pq.push(P[i].fst * P[i].snd);

			ans = max(ans,
				pi * P[i].fst * P[i].fst +
				2 * pi * sum 
			);

			sum -= pq.top();
			pq.pop();
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
}
