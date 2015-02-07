#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int t, n;
int B[5];
long long bd;
int M[25];

#define di(r, c, x) (abs(r - x/5) + abs(c - x%5))

void check(int a, int b, int c, int d, int e){
	long long q = 0;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			q += min(min(min(min(di(i,j,a),di(i,j,b)),di(i,j,c)),di(i,j,d)),di(i,j,e)) * M[i*5+j];

	if (q < bd){
		B[0] = a; B[1] = b; B[2] = c; B[3] = d; B[4] = e;
		bd = q;
	}
}

int main(){
	scanf("%d", &t);

	while (t--){
		int i, j, k, l, m;

		bd = 1L<<50;
		fill(M, M + 25, 0);

		scanf("%d", &n);

		while (n--){
			scanf("%d %d %d", &i, &j, &k);
			M[i*5 + j] = k;
		}

		for (i = 0; i < 25; i++)
		for (j = i+1; j < 25; j++)
		for (k = j+1; k < 25; k++)
		for (l = k+1; l < 25; l++)
		for (m = l+1; m < 25; m++)
		check(i,j,k,l,m);

		printf("%d %d %d %d %d\n", B[0], B[1], B[2], B[3], B[4], B[5]);
	}
}
