#include <cstdio>
#include <algorithm>
#include <functional>

#define eps 1e-7
#define N 12

using namespace std;

int W, D, K, A;
int coef[4][16];
double maxValue;
double R[N + 1][N + 1];

// a, b: limits of integration
// F: function pointer to function to be integrated.
double romberg(double a, double b, double (*F)(double)){
	int i, j, k;
	double sum, h = (b - a);

	R[0][0] = ((*F)(a) + (*F)(b)) * h / 2;

	for (i = 1; i <= N; i++){
		h = h / 2;

		sum = 0;
		for (k = 1; k < (1<<i); k += 2)
			sum += (*F)(a + k * h);

		R[i][0] = R[i-1][0] / 2 + sum * h;
		for (j = 1; j <= i; j++)
			R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / ((1<<(2*j)) - 1);
	}

	return R[N][N];
}

double poly(int idx, double x){
	double ret = 0;
	for (int i = K; i >= 0; i--)
		ret = ret * x + coef[idx][i];
	return ret;
}

double G(int idx, double x){
	return max(maxValue, poly(idx*2,x)/poly(idx*2+1,x));
}

double F(double x){
	return G(0,x) - G(1,x);
}

double solve(){
	double lo = -D, hi = 0;
	int rem = 24;

	while (rem--){
		maxValue = (lo + hi)/2;

		if (romberg(0, W, F) >= A)
			lo = maxValue;
		else
			hi = maxValue;
	}

	return -lo;
}

int main(){
	while (scanf("%d %d %d %d", &W, &D, &A, &K) != EOF){
		for (int f = 0; f < 4; f++)
			for (int i = 0; i <= K; i++)
				scanf("%d", &coef[f][i]);

		printf("%.5lf\n", solve());
	}
}
