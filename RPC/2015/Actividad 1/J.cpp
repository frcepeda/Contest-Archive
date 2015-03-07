/*
Not a subsequence: German Collegiate Programming Contest 2014

We do two dps, one to compute the length of the minimal
subsequence, then another one to compute how many there are.

For the first one, let dp[i] be the minimum length of a string
such that it isn't a subsequence of the string 
S_i = s[i],s[i+1],...,s[n].

We have dp[n] = 1, then.

In any other case, either S_i contains all the letters in the
alphabet, or it doesn't. If it doesn't contain all,
then dp[i] = 1 because we can choose one of the letters that
are not present and the resulting string won't be a subsequence.

Otherwise, let p[x] - 1 be the index of the first occurrence
of the letter x in S_i.

With this, dp[i] = min(1 + dp[p[x]]) over all x in the alphabet.

To reach this conclusion we need some observations. First, let
W(i) be the set of all subsequences that can be formed with
the substring S_i, using the letter s[i] first. It is evident
that for all j > i with s[i] = s[j], W[j] is a subset of W[i].

Now, note that for all distinct characters x, y we have that
W(p[x]) and W(p[y]) are disjoint. Also, the union
for all characters x of W(p[x]) equals the set of all
subsequences that can be formed with S_i.

Finally, notice that a string T = t[1],...,t[m] isn't a
subsequence of S_i if and only if t[2],t[3],...,t[m]
isn't in W(p[t[1]]). The recurrence for dp[i] follows directly
from this observation.

The second dynamic programming recurrence follows a similar
reasoning. Let dp2[i] be the number of strings of length
dp[i] such that they aren't subsequences of S_i.

Then dp2[n] = k, and if S_i doesn't have all the letters of the
alphabet, then dp2[i] = how many letters are missing. Otherwise,
dp2[i] = sum dp2[p[x]] for all x such that dp[i] = dp[p[x]] + 1.

This algorithm takes O(nk) if implemented naively like
below. It can be implemented in O(n) by noticing that only
one value of p[x] changes every step of the dp.
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1000010
#define MAXK 70
#define MOD 1000000007

int T, k, n, L;
char s[MAXN];
int dp[MAXN], dp2[MAXN], p[MAXK];
int x[256];

int main(){
	int i = 0, j;

	for (char j = 'a'; j <= 'z'; j++)
		x[j] = i++;
	for (char j = 'A'; j <= 'Z'; j++)
		x[j] = i++;
	for (char j = '0'; j <= '9'; j++)
		x[j] = i++;

	scanf("%d", &T);

	while (T--){
		scanf("%d %s", &k, &s);
		n = strlen(s);

		fill(p, p + k, -1);
		dp[n] = 1;
		dp2[n] = k;

		for (i = n-1; i >= 0; i--){
			p[x[s[i]]] = i+1;

			dp[i] = 1<<30;

			for (j = 0; j < k && p[j] >= 0; j++)
				dp[i] = min(dp[i], 1 + dp[p[j]]);

			if (j < k) dp[i] = 1;

			dp2[i] = 0;

			for (j = 0; j < k && p[j] >= 0; j++)
				if (dp[i] == dp[p[j]] + 1)
					dp2[i] = (dp2[i] + dp2[p[j]]) % MOD;

			if (j < k){
				dp2[i] = 0;
				for (j = 0; j < k; j++)
					if (p[j] < 0)
						dp2[i]++;
			}
		}

		printf("%d %d\n", dp[0], dp2[0]);
	}
}
