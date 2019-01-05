#include <cstdio>
#include <cstring>
#include <algorithm>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
const int maxn = 1000100;
const int maxlg = 22;
int N, fail[maxn];
char s[maxn];

struct entry {
	pii nr;
	int p;
} L[maxn];
int P[maxlg][maxn], stp, cnt;
int saI[maxn];

bool operator < (const entry &a, const entry &b) {
	return a.nr < b.nr;
}

void rsort(){
	static int acc[30];
	static entry tmp[maxn];

	for (int i = 0; i < 30; i++)
		acc[i] = 0;

	for (int i = 0; i < N; i++)
		acc[L[i].nr.snd]++;

	int sum = 0;
	for (int i = 0; i < 30; i++){
		int tt = acc[i];
		acc[i] = sum;
		sum += tt;
	}

	for (int i = 0; i < N; i++)
		tmp[acc[L[i].nr.snd]++] = L[i];

	for (int i = 0; i < 30; i++)
		acc[i] = 0;

	for (int i = 0; i < N; i++)
		acc[tmp[i].nr.fst]++;

	sum = 0;
	for (int i = 0; i < 30; i++){
		int tt = acc[i];
		acc[i] = sum;
		sum += tt;
	}

	for (int i = 0; i < N; i++)
		L[acc[tmp[i].nr.fst]++] = tmp[i];
}

void sa(){
	for (int i = 0; i < N; i++)
		P[0][i] = s[i] - 'a' + 1;

	for (stp = 1, cnt = 1; cnt>>1 < N; stp++, cnt <<= 1){
		for (int i = 0; i < N; i++){
			L[i].nr = mp(P[stp - 1][i],
			             i + cnt < N ? P[stp - 1][i + cnt] : 0);
			L[i].p = i;
		}

		rsort();

		for (int i = 0; i < N; i++)
			P[stp][L[i].p] = i > 0 && L[i].nr == L[i-1].nr ?
				P[stp][L[i-1].p] : i;
	}
}

int lcp(int x, int y){
	int ret = 0;
	if (x == y) return N - x;

	for (int k = stp-1; k >= 0 && x < N && y < N; k--)
		if (P[k][x] == P[k][y])
			x += 1<<k, y += 1<<k, ret += 1<<k;

	return ret;
}

int main(){
	scanf("%s", s);
	N = strlen(s);

	fail[0] = fail[1] = 0;

	for (int i = 2; i <= N; i++){
		fail[i] = fail[i-1];
		while (fail[i] && s[fail[i]] != s[i-1])
			fail[i] = fail[fail[i]];
		if (s[fail[i]] == s[i-1])
			fail[i]++;
	}

	sa();

	for (int i = 0; i < N; i++)
		saI[P[stp-1][i]] = i;

	for (int i = fail[N]; i; i = fail[i]){
		if (i >= N-1) continue;

		int Ni = N - i;
		int me = P[stp-1][Ni];

		for (int dir = -1; dir <= 1; dir += 2){
			int dd = me + dir;

			while (dd >= 0 && dd < N && !saI[dd])
				dd += dir;

			if (dd >= 0 && dd < N && lcp(Ni, saI[dd]) == i){
				printf("%s\n", s + Ni);
				return 0;
			}
		}
	}

	printf("Leyenda\n");
}
