#include <stdio.h>

#define MAXN 90

typedef long long int lli;

lli gcd(lli a, lli b){
	lli c;
	while (b != 0){
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int n;
lli a[MAXN];
lli p, q;

int main(void){
	int i;
	lli g;
	lli x = 0, y = 1;

	scanf("%I64d %I64d", &p, &q);
	g = gcd(p,q);
	p /= g;
	q /= g;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%I64d", &a[i]);

	for (i = n-1; i >= 0; i--){
		x += y * a[i];
		g = gcd(x,y);
		x /= g;
		y /= g;
		g = x;
		x = y;
		y = g;
	}

	printf("%s\n", p == y && q == x ? "YES" : "NO");

	return 0;
}
