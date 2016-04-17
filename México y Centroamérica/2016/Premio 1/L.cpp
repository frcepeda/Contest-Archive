#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MOD 1000000007
#define MAXN 510
#define LIM 5100

int N;
bool notPrime[LIM];
int dp[MAXN][LIM][2];
char tmp[MAXN];

void subone(){
	for (int i = N-1; i >= 0; i--){
		if (tmp[i] > '0'){
			tmp[i]--;
			break;
		} else tmp[i] = '9';
	}
}

int f(){
	for (int i = 0; i <= LIM; i++)
		for (int k = 0; k < 2; k++)
			dp[N][i][k] = !notPrime[i];

	for (int i = N-1; i >= 0; i--)
		for (int j = 0; j <= LIM; j++)
			for (int w = 0; w < 2; w++){
				dp[i][j][w] = 0;
				for (int k = 0; k <= (w ? 9 : tmp[i] - '0'); k++)
					dp[i][j][w] = (dp[i][j][w] + dp[i+1][j+k][w || (k < tmp[i] - '0')]) % MOD;
			}

	return dp[0][0][0];
}

int main(){
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i <= LIM; i++)
		if (!notPrime[i])
			for (int j = i*i; j <= LIM; j += i)
				notPrime[j] = true;

	while (scanf("%s", tmp) != EOF){
		N = strlen(tmp);
		subone();
		int L = f();

		scanf("%s", tmp);
		N = strlen(tmp);
		int R = f();

		printf("%d\n", (R - L + MOD) % MOD);
	}
}
