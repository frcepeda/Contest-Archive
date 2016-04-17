#include <cstdio>
#include <algorithm>

#define MAXN 250 

using namespace std;

int N;
char S[MAXN];

bool works(int a, int b){
	int x = 0, y = 0;

	for (int i = a; i < b; i++){
		if (S[i] == 'U')
			y++;
		else if (S[i] == 'D')
			y--;
		else if (S[i] == 'R')
			x++;
		else if (S[i] == 'L')
			x--;
	}

	return x == 0 && y == 0;
}

int main(){
	scanf("%d %s", &N, S);

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = i+1; j <= N; j++)
			if (works(i,j))
				ans++;

	printf("%d\n", ans);
}
