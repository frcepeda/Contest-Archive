#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 1000100

int T, N, a[2*MAXN];
map<int,int> m;

int main(){
	scanf("%d", &T);

	while (T--){
		int ans = 0;
		int i;

		scanf("%d", &N);

		for (i = 1; i <= N; i++){
			scanf("%d", &a[i]);
			a[N+i] = a[i];
		}

		m.clear();
		m[0]++;

		for (i = 1; i <= 2*N; i++){
			a[i] += a[i-1];

			if (i-N - 1 >= 0) {
				m[a[i-N - 1]]--;
				if (m[a[i-N - 1]] == 0)
					m.erase(a[i-N - 1]);
			}

			ans = max(ans, a[i] - m.begin()->first);

			m[a[i]]++;
		}

		printf("%d\n", ans);
	}
}
