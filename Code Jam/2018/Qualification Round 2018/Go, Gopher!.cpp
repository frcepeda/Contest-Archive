#include <cstdio>
#include <algorithm>
#include <set>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

const int maxn = 1010;
int T, A;
int cnt[maxn][maxn];

typedef pair<int,int> pii;

int main(){
	scanf("%d", &T);

	set<pair<int,pii>> q;

	while (T--){
		q.clear();

		scanf("%d", &A);
		//fprintf(stderr, "A = %d\n", A);
		//fflush(stderr);

		int N = A == 20 ? 5 : 3;
		int M = A == 20 ? 4 : 67;

		for (int i = 2; i < N; i++)
			for (int j = 2; j < M; j++)
				q.insert(mp(cnt[i][j] = 0, mp(i,j)));

		while (!q.empty()){
			auto it = q.begin();
			auto x = *it;
			q.erase(it);

			printf("%d %d\n", x.snd.fst, x.snd.snd);
			fflush(stdout);
			//fprintf(stderr, "chose: %d %d\n", x.snd.fst, x.snd.snd);
			//fflush(stderr);

			int r, c;
			scanf("%d %d", &r, &c);
			if (r == 0 && c == 0)
				break;
			if (r == -1 && c == -1)
				return 0;
			//fprintf(stderr, "got: %d %d\n", r, c);
			//fflush(stderr);

			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++){
					int nr = r + i;
					int nc = c + j;

					if (2 <= nr && nr < N && 2 <= nc && nc < M){
						q.erase(mp(cnt[nr][nc], mp(nr, nc)));
						cnt[nr][nc]++;
						if (cnt[nr][nc])
							q.insert(mp(cnt[nr][nc], mp(nr, nc)));
					}
				}
		}
	}
}
