#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class RepeatString {
	int go(string a, string b){
		int dp[55][55];

		if (a.empty() || b.empty())
			return max(a.size(), b.size());

		for (int i = 0; i <= b.size(); i++)
			dp[a.size()][i] = b.size() - i;
		for (int i = 0; i <= a.size(); i++)
			dp[i][b.size()] = a.size() - i;

		for (int i = a.size()-1; i >= 0; i--)
			for (int j = b.size()-1; j >= 0; j--){
				dp[i][j] = a[i] == b[j] ? dp[i+1][j+1] : (1<<30);
				dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
				dp[i][j] = min(dp[i][j], 1 + dp[i][j+1]);
				dp[i][j] = min(dp[i][j], 1 + dp[i+1][j+1]);
			}

		return dp[0][0];
	}

public:
	int minimalModify(string s){
		int ans = 1<<30;

		for (int i = 0; i <= s.length(); i++){
			string a = s.substr(0, i);
			string b = s.substr(i);

			ans = min(ans, go(a, b));
		}

		return ans;
	}
};

#ifdef LOCAL
int main(){
	RepeatString r;
	printf("%d\n", r.minimalModify(string("aba")));
	printf("%d\n", r.minimalModify(string("adam")));
	printf("%d\n", r.minimalModify(string("x")));
	printf("%d\n", r.minimalModify(string("aaabbbaaaccc")));
	printf("%d\n", r.minimalModify(string("repeatstring")));
	printf("%d\n", r.minimalModify(string("aaaaaaaaaaaaaaaaaaaa")));
}
#endif
