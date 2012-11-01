#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

int prices[MAXNUM];
int num;
int mem[MAXNUM][MAXNUM];
int vis[MAXNUM][MAXNUM];

int max(int a, int b){return a>b?a:b;}

int crap(int a, int b, int t){
	if (vis[a][b]) return mem[a][b];
	vis[a][b] = 1;
	int ans;
	if (a > b) ans = -1;
	else if (a == b) ans = prices[a] * t;
	else ans = max(crap(a+1,b,t+1)+t*prices[a], crap(a,b-1,t+1)+t*prices[b]);
	return mem[a][b] = ans;
}

int main(void) {
	int i;

	scanf("%d", &num);
	for (i = 0; i < num; i++){
		scanf("%d", &prices[i]);
	}

	printf("%d\n", crap(0, num-1, 1));

	return 0;
}
