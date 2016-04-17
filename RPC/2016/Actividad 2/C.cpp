#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1001000

int N;
bool notPrime[MAXN];
int d[MAXN];

int main(){
	int i, j;

	notPrime[0] = notPrime[1] = true;
	d[1] = 1;
	d[2] = 2;

	for (i = 4; i < MAXN; i += 2){
		notPrime[i] = true;
		d[i] = 2;
	}

	for (i = 3; i < MAXN; i += 2){
		if (!notPrime[i]){
			d[i] = i;
			for (j = 2*i; j < MAXN; j += i){
				notPrime[j] = true;
				d[j] = i;
			}
		}
	}

	while (scanf("%d", &N) == 1){
		int ans = 0;

		while (N){
			N -= d[N];
			ans++;
		}

		printf("%d\n", ans);
	}
}
