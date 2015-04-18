#include <cstdio>

using namespace std;

#define MAXL 10010
#define I 2
#define J 3
#define K 4

// 1, 2, 3, 4
// 1, i, j, k

int p_[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, I, J, K},
	{0, I, -1, K, -J},
	{0, J, -K, -1, I},
	{0, K, J, -I, -1}
};

int p(int a, int b){
	if (a < 0)
		return -p(-a, b);
	else if (b < 0)
		return -p(a, -b);
	return p_[a][b];
}

int t, T, L, X;
long long LX;
signed char s[MAXL];

int power(int b, int e){
	int r = 1;

	for (; e; e /= 2){
		if (e % 2)
			r = p(r, b);
		b = p(b,b);
	}

	return r;
}

bool solve(){
	long long l, r;
	int total, acc;
	bool vl[MAXL][10] = {false}, vr[MAXL][10] = {false};

	if (LX < 3) return false;

	acc = 1;

	for (l = 0; l < LX; l++){
		if (vl[l%L][(acc+10)%10]) return false;
		vl[l%L][(acc+10)%10] = true;
		acc = p(acc, s[l%L]);
		if (acc == I) break;
	}

	acc = 1;

	for (r = LX-1; r >= 0; r--){
		if (vr[r%L][(acc+10)%10]) return false;
		vr[r%L][(acc+10)%10] = true;
		acc = p(s[r%L], acc);
		if (acc == K) break;
	}

	if (l >= r) return false;

	total = 1;
	for (int i = 0; i < L; i++)
		total = p(total, s[i]);

	total = power(total, X);

	return p(p(-I, total), -K) == J;
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d %s", &L, &X, s);

		LX = ((long long)L) * X;

		for (int i = 0; i < L; i++)
			s[i] = s[i] - 'i' + 2;

		printf("Case #%d: %s\n", t, solve() ? "YES" : "NO");
	}
}
