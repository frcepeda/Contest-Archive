#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10010

int SG[MAXN], v[MAXN];
int T, N;

int main(){
	for (int i = 1; i < MAXN; i++){
		for (int k = 1; k <= 3; k++)
			for (int j = 0; j+k <= i && j <= i-j-k; j++)
				v[SG[j] ^ SG[i-j-k]] = i;

		for (int k = 0;; k++)
			if (v[k] != i){
				SG[i] = k;
				break;
			}
	}

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		int x = 0, y;
		while (N--){
			scanf("%d", &y);
			x ^= SG[y];
		}

		printf("%s\n", x ? "MIRKO" : "SLAVKO");
	}
}
