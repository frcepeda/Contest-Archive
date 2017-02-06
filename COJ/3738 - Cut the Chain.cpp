#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int T;
ll N;

vector<ll> cut;

void go(ll x){
	if (x <= cut.size() + 1) return;

	ll k = max(x/2 - (long long)((cut.size() + (x+1)%2)/2), 1LL);

	cut.push_back(k);
	go(k-1);
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%lld", &N);

		cut.clear();

		go(N);

		sort(cut.begin(), cut.end());

		printf("%lu", cut.size());
		for (int i = 0; i < cut.size(); i++)
			printf(" %lld", cut[i]);
		putchar('\n');
	}
}
