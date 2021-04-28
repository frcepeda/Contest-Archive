#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int t, T;
char s[20];
int v[20][20][2];
bool dp[20][20][2];

bool works(int i, int l, bool b){
	if (s[i] == '\0') return true;

	if (v[i][l][b] == t) return dp[i][l][b];
	v[i][l][b] = t;

	dp[i][l][b] = false;

	for (int d = b ? 9 : s[i]-'0'; d >= l; d--){
		bool nb = b || d < s[i]-'0';
		if (works(i+1, d, nb)){
			dp[i][l][b] = true;
			break;
		}
	}

	return dp[i][l][b];
}

ll solve(int i, int l, bool b, ll acc){
	if (s[i] == '\0') return acc;

	for (int d = b ? 9 : s[i]-'0'; d >= l; d--){
		bool nb = b || d < s[i]-'0';
		if (works(i+1, d, nb))
			return solve(i+1, d, nb, 10*acc + d);
	}

	return 0; // shut up
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%s", s);
		printf("Case #%d: %lld\n", t, solve(0, 0, false, 0));
	}
}
