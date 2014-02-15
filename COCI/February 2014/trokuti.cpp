// 140/140 points
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 300010
#define MOD 1000000007

#define den first
#define num second

typedef pair<int,int> slope;
int N;
slope slopes[MAXN];
int siz[MAXN], sSiz;

long long ans;
long long accOne[MAXN], accTwo[MAXN];

int main(){
	int i, j;

	scanf("%d", &N);

	if (N <= 2){
		printf("0\n");
		return 0;
	}

	for (i = 0; i < N; i++){
		scanf("%d %d %*d", &slopes[i].num, &slopes[i].den);

		if (slopes[i].den == 0){
			slopes[i].num = 0;
			continue;
		}

		slopes[i].num *= -1;

		if (slopes[i].den < 0){
			slopes[i].den *= -1;
			slopes[i].num *= -1;
		}

		int g = __gcd(slopes[i].den, slopes[i].num);
		slopes[i].den /= g;
		slopes[i].num /= g;
	}

	sort(slopes, slopes + N);

	for (i = 1, j = 0; i <= N; i++){
		if (slopes[i] != slopes[i-1] || i == N){
			siz[sSiz++] = i - j;
			j = i;
		}
	}

	for (i = N-1; i >= 0; i--)
		accOne[i] = siz[i] + accOne[i+1];

	for (i = N-1; i >= 0; i--)
		accTwo[i] = siz[i] * accOne[i+1];

	for (i = N-1; i >= 0; i--)
		accTwo[i] += accTwo[i+1];

	for (i = 0; i < N; i++)
		ans = (ans + siz[i] * accTwo[i+1]) % MOD;

	printf("%lld\n", ans);
}
