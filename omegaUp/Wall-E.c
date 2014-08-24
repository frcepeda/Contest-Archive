#include <stdio.h>

int vis[5][5] = {{1}};
int dr[4] = {0,-1,0,1};
int dc[4] = {1,0,-1,0};
int r, c, d;

int main(void){
	int N, op, ans = 1;

	scanf("%d", &N);

	while (N--){
		scanf("%d", &op);
		switch (op){
			case 1:
				r += dr[d];
				c += dc[d];
				break;
			case 2:
				r -= dr[d];
				c -= dc[d];
				break;
			case 3:
				d = (d+3) % 4;
				break;
			case 4:
				d = (d+1) % 4;
				break;
		}

		if (r < 0 || c < 0 || r >= 5 || c >= 5){
			printf("0\n");
			return 0;
		}
		
		ans += !vis[r][c];
		vis[r][c] = 1;
	}

	printf("%d\n", ans);
	return 0;
}
