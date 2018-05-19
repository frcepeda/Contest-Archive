#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int N, K, P = 1, D;
map<int,int> d;

const int maxd = 7;//1400;
ll dp[maxd][maxd];
int dd[maxd];

int main(){
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++){
		int x;
		scanf("%d", &x);
		P *= x;
	}

	for (int i = 1; i*i <= P; i++)
		if (P % i == 0){
			d[i] = 0;
			d[P/i] = 0;
		}

	int x = 0;
	for (map<int,int>::iterator it = d.begin(); it != d.end(); it++){
		dd[x] = it->first;
		it->second = x++;
	}

	D = d.size();

	for (int i = 0; i < D; i++)
		dp[0][i] = 1;

	for (int k = 1; k <= K; k++)
		for (int i = D-1; i >= 0; i--)
			for (int j = 0; j < D; j++)
				dp[i][j] = (j ? dp[i][j-1] : 0) + (dd[i] % dd[j] ? 0 : dp[d[dd[i]/dd[j]]][j]);

	printf("%lld\n", dp[D-1][0]);
}
