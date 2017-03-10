#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> pii;
vector<pair<int,int>> input;
priority_queue<pii, vector<pii>, greater<pii>> q;

int T, N;

bool works(int P){
	while (!q.empty()) q.pop();
	for (auto w: input)
		q.push(w);
	while (!q.empty()){
		auto z = q.top(); q.pop();
		if (z.fst > P) return false;
		if (z.snd >= 0){
			q.push(mp(z.snd,-1));
			P++;
		} else {
			P += 2;
		}
	}
	return true;
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		input.clear();
		for (int i = 0; i < N; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			input.push_back(mp(a,b));
		}

		int lo = 0, hi = 3005, mid;
		while (lo < hi){
			mid = (lo + hi)/2;
			if (works(mid))
				hi = mid;
			else
				lo = mid + 1;
		}

		printf("%d\n", hi);
	}
}
