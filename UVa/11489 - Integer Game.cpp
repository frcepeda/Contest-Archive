#include <cstdio>
#include <cstring>

int T, N;
char s[1010];

bool solve(int x[3]){
	int r = (x[1] + 2 * x[2]) % 3;

	if (x[0] + x[1] + x[2] == 1) return false;

	if (r)
		return !x[r] || x[0] % 2 == 1;

	return x[0] % 2 == 0;
}

int main(){
	int t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int x[3] = {0};

		scanf("%s", s);
		N = strlen(s);

		for (int i = 0; i < N; i++)
			x[(s[i] - '0') % 3]++;

		printf("Case %d: %c\n", t, solve(x) + 'S');
	}
}
