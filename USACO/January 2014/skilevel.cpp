// 100/100 points
#include <cstdio>
#include <algorithm>

using namespace std;

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("skilevel.in", "r", stdin); freopen("skilevel.out", "w", stdout)
#else
	#define openFiles()
#endif

int _abs(int a){
	return a >= 0 ? a : -a;
}

#define MAXN 505
#define fst first
#define snd second
#define mp make_pair

typedef pair<int,int> pii;

long long ans;
int N, M, T, C;
int grid[MAXN][MAXN];
int _id[MAXN*MAXN], size[MAXN*MAXN], toCount[MAXN*MAXN];
pair<int,pii> jumps[MAXN*MAXN*2];

int id(int x){
	if (_id[x] == x)
		return x;
	else return _id[x] = id(_id[x]);
}

int join(int a, int b){
	a = id(a);
	b = id(b);

	if (a != b){
		size[a] += size[b];
		toCount[a] += toCount[b];
		_id[b] = a;
	}

	return a;
}

int main(){
	int i, j;

	openFiles();

	scanf("%d %d %d", &N, &M, &T);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &grid[i][j]);

	j = N*M;
	for (i = 0; i < j; i++){
		_id[i] = i;
		size[i] = 1;
		scanf("%d", &toCount[i]);
	}

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			if (i < N-1)
				jumps[C++] = mp(_abs(grid[i][j]-grid[i+1][j]), mp(i*M+j, (i+1)*M+j));
			if (j < M-1)
				jumps[C++] = mp(_abs(grid[i][j]-grid[i][j+1]), mp(i*M+j, i*M+j+1));
		}
	}

	sort(jumps, jumps+C);

	for (i = 0; i < C; i++){
		j = join(jumps[i].snd.fst, jumps[i].snd.snd);
		if (size[j] >= T && toCount[j]){
			ans += ((long long)toCount[j]) * jumps[i].fst;
			toCount[j] = 0;
		}
	}

	printf("%lld\n", ans);
}
