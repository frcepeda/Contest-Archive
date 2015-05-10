#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 1000100
#define MOD 1000000007L
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

int N;
int A[MAXN], p[MAXN];
bool v[MAXN];
vector<pair<int,int>> n, m, t;

typedef unsigned long long ull;

unsigned long long lcm(unsigned long long x, unsigned long long y){
	return x/__gcd(x,y)*y;
}

ull modpow(ull x, int e){
	ull r = 1;

	for (; e; e /= 2){
		if (e % 2)
			r = (r * x) % MOD;
		x = (x * x) % MOD;
	}

	return r;
}

int cycle(int x){
	int c = 0;
	for (; !v[x]; c++){
		v[x] = true;
		x = A[x];
	}
	return c;
}

int factorize(int x){
	m.clear();

	while (x != 1){
		int c, d = p[x];
		for (c = 0; p[x] == d; x /= d)
			c++;
		m.pb(mp(d,c));
	}
}

void lcm(){
	t.clear();

	int i = 0, j = 0;
	while (i < n.size() || j < m.size()){
		if (i < n.size() && j < m.size() && n[i].fst == m[j].fst){
			t.pb(mp(n[i].fst, max(n[i].snd, m[j].snd)));
			i++, j++;
		} else if (i < n.size() && (j >= m.size() || n[i].fst < m[j].fst))
			t.pb(n[i++]);
		else
			t.pb(m[j++]);
	}

	n.clear();
	n.insert(n.begin(), t.begin(), t.end());
}

int main(){
	int i, j;
	p[0] = p[1] = -1;
	for (i = 2; i < MAXN; i += 2)
		p[i] = 2;
	for (i = 3; i < MAXN; i += 2)
		if (!p[i]){
			p[i] = i;
			if (i <= MAXN/i)
				for (j = i*i; j < MAXN; j += i)
					if (!p[j])
						p[j] = i;
		}

	while (scanf("%d", &N) != EOF){
		n.clear();

		fill(v+1, v+1+N, false);

		for (i = 1; i <= N; i++)
			scanf("%d", &A[i]);

		for (i = 1; i <= N; i++)
			if (!v[i]){
				factorize(cycle(i));
				lcm();
			}

		unsigned long long ans = 1;
		for (int i = 0; i < n.size(); i++)
			ans = (ans * modpow(n[i].fst, n[i].snd)) % MOD;

		printf("%llu\n", ans);
	}
}
