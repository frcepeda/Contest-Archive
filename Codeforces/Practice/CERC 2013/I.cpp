// Accepted
#include <cstdio>
#include <algorithm>

#define mp make_pair

using namespace std;
typedef pair<int,int> pii;

int T, N;
int cnt;
int a[10100];
pii moves[500000];

void crane(int x, int y){
	int m = (x + y + 1) / 2;
	for (int i = 0; x+i < m; i++)
		swap(a[x+i], a[m+i]);
}

void solve(int i){
	int c;
	for (c = i; a[c] != i; c++);

	while (c != i){
		int b = i + (c - i + 1) % 2;
		moves[cnt++] = mp(b, c);
		crane(b, c);
		for (c = i; a[c] != i; c++);
	}
}

int main(){
	scanf("%d", &T);

	while (T--){
		int i;

		cnt = 0;

		scanf("%d", &N);

		for (i = 1; i <= N; i++)
			scanf("%d", &a[i]);

		for (i = 1; i <= N; i++)
			solve(i);
		
		printf("%d\n", cnt);
		for (i = 0; i < cnt; i++)
			printf("%d %d\n", moves[i].first, moves[i].second);
	}
}
