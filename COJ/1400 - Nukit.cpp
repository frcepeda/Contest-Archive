#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXK 10

bool v[MAXK][MAXK][MAXK][MAXK];
bool dp[MAXK][MAXK][MAXK][MAXK];

#define arr(v) v[a][b][c][d]

int N;

bool f(int a, int b, int c, int d){
	if (a < 0 || b < 0 || c < 0 || d < 0) return true;
	if (arr(v)) return arr(dp);
	arr(v) = true;

	arr(dp) |= !f(a-2, b-1, c-0, d-2);
	arr(dp) |= !f(a-1, b-1, c-1, d-1);
	arr(dp) |= !f(a-0, b-0, c-1, d-1);
	arr(dp) |= !f(a-0, b-3, c-0, d-0);
	arr(dp) |= !f(a-1, b-0, c-0, d-1);

	return arr(dp);
}

int main(){
	scanf("%d", &N);

	while (N--){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%s\n", !f(a,b,c,d) ? "Roland" : "Patrick");
	}
}
