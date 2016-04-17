#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

#define LIM 61
#define MAXK 21

ll n;
int k;

short cnt[1<<MAXK];
int idx[MAXK];

inline int nxt(int z, int c){
	int w = z + (z&-z);
	int r = c - cnt[w];
	return w + (1<<r) - 1;
}

int main(){
	for (int i = 1; i < (1<<MAXK); i++)
		cnt[i] = 1 + cnt[i^(i&-i)];

	while (scanf("%lld", &n) != EOF){
		scanf("%d", &k);

		for (int i = 0; i < k; i++)
			scanf("%d", &idx[i]);

		int ones = 0;
		for (int i = 0; i < k; i++){
			if (n & (1LL << idx[i])){
				ones++;
				n ^= 1LL << idx[i];
			}
		}

		ll best = 0;
		for (int i = (1<<ones)-1; i < (1<<k); i = nxt(i,ones)){
			if (cnt[i] != ones) continue;

			ll m = n;
			for (int j = 0; j < k; j++)
				if (i & (1<<j))
					m += 1LL << idx[j];

			if (m % 7 == 0)
				best = max(best, m);
		}

		printf("%lld\n", best);
	}
}
