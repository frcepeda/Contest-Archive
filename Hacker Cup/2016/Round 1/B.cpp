#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef unsigned long long ull;
typedef pair<ull,int> pii;

int T, L, N, M, D;

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		priority_queue<pii, vector<pii>, greater<pii>> q;
		priority_queue<pii, vector<pii>, greater<pii>> r;

		cin >> L >> N >> M >> D;

		for (int i = 0; i < N; i++){
			int z;
			cin >> z;
			q.push(mp(z,z));
		}

		for (int i = 0; i < L; i++){
			auto z = q.top(); q.pop();
			r.push(mp(z.fst, 1));
			q.push(mp(z.fst + z.snd, z.snd));
		}

		ull ans = 0;

		int acc = 0, avail = M, done = 0;
		while (done < L){
			auto z = r.top(); r.pop();

			if (z.snd == 0){
				if (acc){
					ans = max(ans, z.fst + D);
					r.push(mp(z.fst + D, 0));
					acc--; done++;
				} else avail++;
			} else {
				if (avail){
					ans = max(ans, z.fst + D);
					r.push(mp(z.fst + D, 0));
					avail--; done++;
				} else acc++;
			}
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
}
