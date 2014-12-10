#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[110], T[110];
int len, C;

int main(){
	int c, i;

	scanf("%d", &C);

	for (c = 1; c <= C; c++){
		int ans = 0;

		int s0 = 0, s1 = 0, sq = 0, t0 = 0, t1 = 0;
		int x0 = 0, x1 = 0, xq = 0;
		scanf("%s %s", S, T);
		len = strlen(S);

		for (i = 0; i < len; i++){
			if (S[i] == '0')
				s0++;
			else if (S[i] == '1')
				s1++;
			else
				sq++;

			if (T[i] == '0')
				t0++;
			else
				t1++;
		}

		if (s1 > t1){
			ans = -1;
			goto ded;
		}

		if (t1 < s1)
			for (i = 0; i < len && s1 < t1; i++)
				if (S[i] == '?' && T[i] == '1')
					ans++;

		for (i = 0; i < len; i++){
			if (S[i] == '0' && T[i] != S[i])
				x0++;
			else if (S[i] == '1' && T[i] != S[i])
				x1++;
			else if (T[i] != S[i])
				xq++;
		}

		ans += x0 + x1 + xq - min(x0, x1);

ded:
		printf("Case %d: %d\n", c, ans);
	}
}
