#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class BracketSequenceDiv1 {
public:
	long long count(string s){
		long long dp[50][50] = {0};

		int N = s.length();

		for (int i = 0; i <= N; i++)
			dp[i][i] = dp[i+1][i] = 1;

		for (int k = 1; k < N; k++)
			for (int i = 0; i+k < N; i++){
				dp[i][i+k] = dp[i+1][i+k];
				for (int j = i+1; j <= i+k; j++)
					if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
					    dp[i][i+k] += dp[i+1][j-1] * dp[j+1][i+k];
			}

		return dp[0][N-1] - 1;
	}
};

int main(){
	BracketSequenceDiv1 x;
	printf("%lld\n", x.count(string("())")));
	printf("%lld\n", x.count(string("()()")));
	printf("%lld\n", x.count(string("([)]")));
}
