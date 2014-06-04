#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int T, N, M;
char str[10][15];
string s[10];
int where[10];

int count(){
	int i, j, k, c = N;

	for (i = 0; i < N; i++){
		int t = 0;
		for (j = 0; j < M; j++)
			if (where[j] == i)
				s[t++] = string(str[j]);

		if (t == 0) return 0;
		sort(s, s + t);

		for (j = 0; j < t; j++){
			c += s[j].length();
			if (j){
				for (k = 0; k < s[j].length() && k < s[j-1].length() && s[j][k] == s[j-1][k]; k++);
				c -= k;
			}
		}
	}

	return c;
}

int main(){
	int t;
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int i, j, ans = 0, ans2 = 0;

		scanf("%d %d", &M, &N);

		for (i = 0; i < M; i++)
			scanf("%s", str[i]);

		int lim = 1;
		for (i = 0; i < M; i++)
			lim *= N;

		for (i = 0; i < lim; i++){
			int x = i;
			for (j = 0; j < 10; x /= N, j++)
				where[j] = x % N;
			x = count();
			if (x > ans){
				ans = x;
				ans2 = 1;
			} else if (x == ans) ans2++;
		}

		fprintf(stderr, "Case #%d: %d %d\n", t, ans, ans2);
		fflush(stderr);
		printf("Case #%d: %d %d\n", t, ans, ans2);
	}
}
