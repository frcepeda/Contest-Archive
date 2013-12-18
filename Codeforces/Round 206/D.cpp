#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 25

int n;
char board[MAXN][MAXN];
int mem[MAXN][MAXN][2];
bool visited[MAXN][MAXN][2];

int f(int a, int b){
	if (board[a][b] == 'a')
		return 1;
	else if (board[a][b] == 'b')
		return -1;
	return 0;
}

int minimax(int a, int b, int p){
	int d, r;
	d = r = (p == 0 ? -1000000 : 1000000);

	if (visited[a][b][p])
		return mem[a][b][p];
	else if (a == n-1 && b == n-1)
		return f(a,b);

	visited[a][b][p] = true;

	if (a < n-1)
		d = minimax(a+1, b, !p);

	if (b < n-1)
		r = minimax(a, b+1, !p);

	if (p == 0)
		mem[a][b][p] = max(d,r);
	else
		mem[a][b][p] = min(d,r);

	mem[a][b][p] += f(a,b);

	return mem[a][b][p];
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);

	int outcome = minimax(0,0,1);

	if (outcome == 0)
		printf("DRAW\n");
	else if (outcome > 0)
		printf("FIRST\n");
	else
		printf("SECOND\n");
}
