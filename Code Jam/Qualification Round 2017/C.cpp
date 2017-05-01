#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int T, K, N;

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %d", &N, &K);

		priority_queue<int> q;

		q.push(N);

		while (K--){
			int v = q.top(); q.pop();

			q.push((v-1)/2);
			q.push(v/2);

			if (K == 0)
				printf("Case #%d: %d %d\n", t, v/2, (v-1)/2);
		}

	}
}
