#include <cstdio>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

const int maxn = 100100, HH = 3;
int N, Q, L;

multiset<tuple<ll,ll,ll>> H[maxn];
ll h[HH][maxn], b[HH][maxn];
const ll B[HH] = {31, 47, 313};

void getHashes(char *s){
	for (int j = 0; j < HH; j++){
		ll acc = 0;

		for (int i = 0; i < L; i++)
			acc += (s[i] - 'a') * b[j][i];

		for (int i = 0; i < L; i++)
			h[j][i] = acc - (s[i] - 'a') * b[j][i];
	}
}

int main(){
	for (int j = 0; j < HH; j++){
		b[j][0] = 1;
		for (int i = 1; i < maxn; i++)
			b[j][i] = B[j] * b[j][i-1];
	}

	while (scanf("%d %d %d", &N, &Q, &L) != EOF){
		for (int i = 0; i < L; i++)
			H[i].clear();

		static char s[maxn];

		while (N--){
			scanf("%s", s);
			getHashes(s);

			for (int j = 0; j < L; j++)
				H[j].insert(make_tuple(h[0][j],h[1][j],h[2][j]));
		}

		while (Q--){
			scanf("%s", s);
			getHashes(s);

			int ans = 0;
			for (int j = 0; j < L; j++)
				ans += H[j].count(make_tuple(h[0][j],h[1][j],h[2][j]));

			printf("%d\n", ans);
		}
	}
}
