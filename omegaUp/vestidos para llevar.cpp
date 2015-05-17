#include "vestidos.h"
#include <algorithm>

using namespace std;

// Main
//	int fiesta(int m, int invitados[])
//	void respuesta(int vestidos[])

#define MAXN 155

int N, C;
int v[MAXN];
int f[MAXN];

int count(int a, int b){
	for (int i = 0; i < b - a; i++)
		f[i] = v[a+i];
	sort(f, f + (b-a));
	return unique(f, f + (b-a)) - f;
}

int check(int a, int b, int x){
	f[0] = x;
	for (int i = 0; i < b - a; i++)
		f[i+1] = a+i;
	return fiesta(b - a + 1, f);
}

int color(int x){
	if (check(1, x, x) != C)
		return ++C;
	
	int lo = 1, hi = x, mid;

	while (lo+1 < hi){
		mid = (lo + hi) / 2;
		if (check(lo, mid, x) == count(lo, mid))
			hi = mid;
		else
			lo = mid;
	}

	return v[lo];
}

void determinaVestidos(int N_) {
	N = N_;
	C = 1;

	v[1] = C;

	for (int i = 2; i <= N; i++)
		v[i] = color(i);
	
	respuesta(v);
}
