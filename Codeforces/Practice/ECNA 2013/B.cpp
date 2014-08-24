#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010

int T[2][MAXN];
int S[2];
int out[MAXN];
int t = 0;

void insert(int i, int x){
	if (T[i][x % S[i]] == -1){
		T[i][x % S[i]] = x;
		return;
	}

	int y = T[i][x % S[i]];
	T[i][x % S[i]] = x;
	insert(!i, y);
}

int main(){
	int m;

	while (scanf("%d %d %d", &S[0], &S[1], &m), t++, (S[0] || S[1] || m)){
		fill(T[0], T[0] + MAXN, -1);
		fill(T[1], T[1] + MAXN, -1);

		while (m--){
			int x;
			scanf("%d", &x);
			insert(0, x);
		}

		printf("Case %d:\n", t);
		for (int i = 0; i < 2; i++){
			int oc = 0;

			for (int j = 0; j < S[i]; j++)
				if (T[i][j] != -1)
					out[oc++] = T[i][j];

			if (oc){
				printf("Table %d\n", i+1);
				for (int j = 0; j < oc; j++)
					printf("%d:%d\n", out[j] % S[i], out[j]);
			}
		}
	}
}
