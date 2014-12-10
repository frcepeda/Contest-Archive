#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

#define MAXN 2500
#define R 11

using namespace std;

int T, n;
char S[MAXN], pat[MAXN];
int plen;
string ps[R];

bool prefix(int x){
	for (int i = plen-1; i >= 0 && x >= 0; i--, x--)
		if (pat[i] != S[x])
			return false;
	return x < 0;
}

bool suffix(int x){
	for (int i = 0; i < plen && S[x] != '\0'; i++, x++)
		if (pat[i] != S[x])
			return false;
	return S[x] == '\0';
}

int main(){
	int i, j;

	for (i = 1; i < R; i++){
		pat[plen] = 'L';
		copy(pat, pat + plen, pat + plen + 1);
		reverse(pat + plen + 1, pat + plen + 1 + plen);
		for (j = plen + 1; j < 2*plen + 1; j++)
			pat[j] = pat[j] == 'L' ? 'R' : 'L';
		plen = 2*plen + 1;
		ps[i-1] = string(pat);
	}

	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %s", &n, S);

		for (i = 0; i < min(R,n); i++)
			if (ps[i].find(S) != string::npos)
				break;

		printf("Case %d: %s\n", t, i < min(R,n) ? "Yes" : "No");
	}
}
