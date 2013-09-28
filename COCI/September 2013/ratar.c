// 100/100 points

#include <stdio.h>

#define MAXN 55

int map[MAXN][MAXN];
int N, ans;

int toDelete[MAXN*MAXN*2], tdc;
int _count[5000100];

#define count(x) _count[x + 2500000]
#define area(a,b,c,d) (map[c][d] - map[c][b-1] - map[a-1][d] + map[a-1][b-1])

int main(void){
	int i, j, a, b;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			map[i][j] += map[i-1][j] + map[i][j-1] - map[i-1][j-1];

	for (i = 1; i < N; i++){
		for (j = 2; j <= N; j++){
			for (a = 1; a <= i; a++){
				for (b = j; b <= N; b++){
					count(area(a,j,i,b))++;
					toDelete[tdc++] = area(a,j,i,b);
				}
			}
			for (a = i+1; a <= N; a++)
				for (b = 1; b < j; b++)
					ans += count(area(i+1,b,a,j-1));
			for (a = 0; a < tdc; a++)
				count(toDelete[a]) = 0;
			tdc = 0;

			for (a = i+1; a <= N; a++){
				for (b = j; b <= N; b++){
					count(area(i+1,j,a,b))++;
					toDelete[tdc++] = area(i+1,j,a,b);
				}
			}
			for (a = 1; a <= i; a++)
				for (b = 1; b < j; b++)
					ans += count(area(a,b,i,j-1));
			for (a = 0; a < tdc; a++)
				count(toDelete[a]) = 0;
			tdc = 0;
		}
	}

	printf("%d\n", ans);

	return 0;
}
