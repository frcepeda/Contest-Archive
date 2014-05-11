#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cassert>

#define MOD 1000000007

using namespace std;

int T, N;
string s[110];

int dp[1<<15][100];

int check(int bits, int c, int add){
	int i, j;

	for (j = 0; j < s[add].length() && s[add][j] == c; j++);
	for (; j < s[add].length() && s[add][j] != c; j++);

	if (j != s[add].length()) return false;

	for (j = 0; j < s[add].length() && s[add][j] == c; j++);

	for (; j < s[add].length(); j++)
		for (i = 0; i < N; i++)
			if ((bits & (1<<i)) && s[i].find(s[add][j]) != string::npos)
				return false;

	for (i = 0; i < s[add].length(); i++){
		for (j = 0; j < s[add].length() && s[add][j] != s[add][i]; j++);
		for (; j < s[add].length() && s[add][j] == s[add][i]; j++);
		for (; j < s[add].length() && s[add][j] != s[add][i]; j++);

		if (j != s[add].length()) return false;
	}

	return true;
}

int main(){
	int t, i, j, k;

	cin >> T;

	for (t = 1; t <= T; t++){
		cin >> N;

		for (i = 0; i < N; i++){
			cin >> s[i];
			assert(s[i][s[i].length()-1] != '\n');
		}

		for (i = 0; i < (1<<N); i++)
			for (j = 'a'; j <= 'z'; j++)
				dp[i][j] = 0;

		for (i = 0; i < N; i++)
			if (check(0,s[i][0],i))
				dp[1<<i][s[i][s[i].length()-1]] = 1;

		for (i = 0; i < (1<<N); i++)
			for (j = 'a'; j <= 'z'; j++)
				for (k = 0; k < N; k++)
					if (!(i & (1<<k)) && check(i,j,k)){
						dp[i | (1<<k)][s[k][s[k].length()-1]] += dp[i][j];
						dp[i | (1<<k)][s[k][s[k].length()-1]] %= MOD;
					}

		int ans = 0;
		for (j = 'a'; j <= 'z'; j++)
			ans = (ans + dp[(1<<N)-1][j]) % MOD;

		printf("Case #%d: %d\n", t, ans);
		fprintf(stderr, "Case #%d: %d\n", t, ans);
		fflush(stderr);
	}
}
