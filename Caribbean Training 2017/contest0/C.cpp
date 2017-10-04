#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
int n, m;
char s[maxn], t[maxn];
int dp[maxn][maxn];

int main(){
	scanf("%s %s", s, t);
	
	n = strlen(s);
	m = strlen(t);

	for (int i = n-1; i >= 0; i--)
		for (int j = m-1; j >= 0; j--)
			dp[i][j] = max(max(dp[i+1][j], dp[i][j+1]),
			               s[i] == t[j] ? dp[i+1][j+1] + 1 : 0);

	printf("%d\n", dp[0][0]);

	vector<int> l, r;
	int i = 0, j = 0;
	while (i < n && j < m){
		if (s[i] == t[j]){
			l.push_back(i+1);
			r.push_back(j+1);
			i++; j++;
		} else if (dp[i+1][j] > dp[i][j+1]){
			i++;
		} else {
			j++;
		}
	}

	for (int i = 0; i < l.size(); i++)
		printf("%d%c", l[i], i+1 < l.size() ? ' ' : '\n');
	for (int i = 0; i < r.size(); i++)
		printf("%d%c", r[i], i+1 < r.size() ? ' ' : '\n');
}
