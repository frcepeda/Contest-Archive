#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxk = 105;
const ll M = 1000000007LL;

struct mat {
	ll m[maxk][maxk];
};

ll k, n;
ll init[maxk];

mat F, id;

mat mmult(const mat &a, const mat &b){
	mat c;

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++){
			c.m[i][j] = 0;
			for (int w = 0; w < k; w++)
				c.m[i][j] = (c.m[i][j] + a.m[i][w] * b.m[w][j]) % M;
		}

	return c;
}

ll fib(ll e){
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			F.m[i][j] = id.m[i][j] = 0;

	for (int i = 0; i < k; i++)
		F.m[0][i] = 1;

	for (int i = 1; i < k; i++)
		F.m[i][i-1] = 1;

	for (int i = 0; i < k; i++)
		id.m[i][i] = 1;

	for (; e; e /= 2){
		if (e % 2)
			id = mmult(F, id);
		F = mmult(F, F);
	}

	ll ret = 0;

	for (int i = 0; i < k; i++)
		ret = (ret + id.m[0][i] * init[i]) % M;

	return ret;
}

int main(){
	scanf("%lld %lld", &k, &n);

	for (int i = 0; i < k; i++)
		scanf("%lld", &init[k-1-i]);

	if (n <= k)
		printf("%lld\n", init[k-1-n]);
	else
		printf("%lld\n", fib(n-k));
}
