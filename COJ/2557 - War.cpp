#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int N, Q[100100];
multiset<int> R;

int main(){
	int ans = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &Q[i]);

	for (int i = 0; i < N; i++){
		int z;
		scanf("%d", &z);
		R.insert(z);
	}

	for (int i = 0; i < N; i++){
		multiset<int>::iterator z = R.lower_bound(Q[i]+1);
		if (z != R.end()){
			ans++;
			R.erase(z);
		} else R.erase(R.begin());
	}

	printf("%d\n", ans);
}
