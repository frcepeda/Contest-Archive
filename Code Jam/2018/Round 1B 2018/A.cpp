#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int T, N, L;

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %d", &N, &L);

		priority_queue<int, vector<int>, greater<int>> q;

		int S = 0, ans = 0;
		for (int i = 0; i < L; i++){
			int x, y;
			scanf("%d", &x);
			S += x;
			x *= 100;
			y = x - x / N * N;
			ans += x / N;
			if (2*y >= N){
				ans += 1;
				y -= N;
			}
			q.push(N - 2*y);
		}

		for (; S < N; S++){
			int t = q.top(); q.pop();
			if (t > N) t = N;
			ans += 100 / N;
			int y = t - 100 % N * 2;
			if (y <= 0) {
				ans += 1;
				q.push(2*N + y);
			} else q.push(y);
		}

		printf("Case #%d: %d\n", t, ans);
	}
}
