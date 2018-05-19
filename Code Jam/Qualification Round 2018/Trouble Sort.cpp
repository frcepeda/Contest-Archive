#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 100100;
int T, N, V[maxn];

int main(){
	scanf("%d", &T);

	vector<int> V, W[2];

	for (int t = 1; t <= T; t++){
		scanf("%d", &N);

		V.clear();
		W[0].clear();
		W[1].clear();

		for (int i = 0; i < N; i++){
			int x;
			scanf("%d", &x);
			W[i%2].push_back(x);
		}

		sort(W[0].begin(), W[0].end());
		sort(W[1].begin(), W[1].end());

		auto l = W[0].begin();
		auto r = W[1].begin();

		while (l != W[0].end() || r != W[1].end()){
			if (l != W[0].end())
				V.push_back(*l++);
			if (r != W[1].end())
				V.push_back(*r++);
		}

		int idx = is_sorted_until(V.begin(), V.end()) - V.begin();

		printf("Case #%d: ", t);

		if (idx == N)
			printf("OK\n");
		else
			printf("%d\n", idx-1);
	}
}
