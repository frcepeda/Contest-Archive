// Accepted
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 100100;
const int maxk = 350;
int N;

bool dp[maxn][maxk], v[maxn][maxk];

bool f(int i, int j){
	if (i == 0) return false;
	if (j > i) return false;
	if (j == i) return true;

	if (v[i][j])
		return dp[i][j];
	v[i][j] = true;

	return dp[i][j] = !(f(i-j,j) && f(i-(j+1),j+1));
}

int main(){
	for (int i = 1; scanf("%d", &N), N; i++)
		printf("Case #%d: %s player wins.\n",
		       i, f(N-1,1) ? "Second" : "First");
}
