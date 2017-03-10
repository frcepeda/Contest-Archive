#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXG 3100
#define MAXN 3000100
#define MAXA (2*('z'-'a'+1))

int g, N;
char W[MAXG], S[MAXN];
int cnt[2][MAXA], p[MAXA];
int m[256];

int main(){
	int A = 0;
	for (char c = 'a'; c <= 'z'; c++)
		m[c] = A++;
	for (char c = 'A'; c <= 'Z'; c++)
		m[c] = A++;

	scanf("%d %d", &g, &N);
	scanf("%s", W+1);
	scanf("%s", S+1);

	for (int i = 1; i <= g; i++)
		p[m[W[i]]]++;

	int ans = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 0; j < A; j++)
			cnt[1][j] = cnt[1][j] + (m[S[i]] == j);
		if (i-g >= 1)
			for (int j = 0; j < A; j++)
				cnt[0][j] = cnt[0][j] + (m[S[i-g]] == j);
		if (i-g >= 0){
			int j;
			for (j = 0; j < A; j++)
				if (p[j] != cnt[1][j] - cnt[0][j])
					break;
			ans += j == A;
		}
	}

	printf("%d\n", ans);
}
