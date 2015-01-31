#include <cstdio>

using namespace std;

#define MAXN 1000

char A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];
int N, n;

void rotate(){
	int i, j;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			C[j][n-1-i] = B[i][j];
			
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			B[i][j] = C[i][j];
}

bool check(int a, int b){
	int i, j;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (B[i][j] != A[a+i][b+j])
				return false;
				
	return true;
}

int match(){
	int i, j, r = 0;
	
	for (i = 0; i+n <= N; i++)
		for (j = 0; j+n <= N; j++)
			if (check(i,j))
				r++;
	
	return r;
}

int main() {
	while (scanf("%d %d", &N, &n), (N || n)){
		int i;
		
		for (i = 0; i < N; i++)
			scanf("%s", &A[i]);
			
		for (i = 0; i < n; i++)
			scanf("%s", &B[i]);
			
		for (i = 0; i < 4; i++){
			if (i) rotate();
			printf("%d%c", match(), i < 3 ? ' ' : '\n');
		}
	}
}