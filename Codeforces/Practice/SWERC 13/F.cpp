#include <cstdio>
#include <algorithm>

typedef long long ll;

#define MAXT 32

ll fives[MAXT] = {1};
ll cache[MAXT] = {1};

bool g(ll x){
	ll r = 0;
	for (int i = 1; i < MAXT; i++)
		r += x / fives[i];
	return r % 2 == 0;
}

ll f(ll x){
	if (x == 0) return 1;

	ll r;
	int l, i;
	for (l = 0; fives[l] <= x; l++);
	l--;

	ll fl = cache[l];
	int c = 0;

	for (i = 1; i * fives[l] <= x; i++)
		c += g((i-1) * fives[l]);

	ll gp = (x / fives[l]) * fives[l];

	if (g(gp))
		r = f(x - gp);
	else
		r = x - gp + 1 - f(x - gp);

	return r + c * fl + (x / fives[l] - c) * (fives[l] - fl);
}

int main(){
	int i;
	ll N;

	for (i = 1; i < MAXT; i++)
		fives[i] = fives[i-1] * 5;

	for (i = 0; i < MAXT; i++)
		cache[i] = f(fives[i]-1);

	while (scanf("%I64d", &N), N != -1)
		printf("%I64d\n", f(N));
}
