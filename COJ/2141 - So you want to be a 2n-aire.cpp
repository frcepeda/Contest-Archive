#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 50

int n;
double t;
double E[MAXN];

int main(){
	while (scanf("%d %lf", &n, &t), (n && t != 0)){
		E[n] = 1;
		double p = 1/(1-t);

		for (int i = n-1; i >= 0; i--){
			auto a = E[i+1];
			if (t >= 1/(2*a))
				E[i] = a * p * (1 - t*t);
			else
				E[i] = p * (1/(2*a) - t + a*(1 - 1/(4*a*a)));
		}

		printf("%.2lf\n", E[0]);
	}
}
