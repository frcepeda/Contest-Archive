#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 300+3

int accum[MAXNUM][MAXNUM];
int map[MAXNUM][MAXNUM];

int getAccum(int xt, int yt, int xb, int yb){
	return accum[xb][yb] + accum[xt-1][yt-1] - accum[xt-1][yb] - accum[xb][yt-1];
}

int area(int xt, int yt, int xb, int yb){
	return (xb - xt + 1) * (yb - yt + 1);
}

int main(void){
	int width, height, max;
	int i, j, top, bottom, min = 1<<30;

	scanf("%d %d %d", &height, &width, &max);

	for (i = 1; i <= height; i++){
		for (j = 1; j <= width; j++){
			scanf("%d", &map[j][i]);
		}
	}


	for (i = 1; i <= height; i++){
		accum[1][i] = map[1][i];
		for (j = 2; j <= width; j++){
			accum[j][i] = accum[j-1][i] + map[j][i];
		}
	}

	for (j = 1; j <= width; j++){
		for (i = 2; i <= height; i++){
			accum[j][i] += accum[j][i-1];
		}
	}

	/*for (i = 1; i <= height; i++){
		for (j = 1; j <= width; j++){
			printf("%2d ", accum[j][i]);
		}
		printf("\n");
	}//*/

	for (i = 1; i <= width; i++){
		for (j = i; j <= width; j++){
			top = 1;
			bottom = 1;
			while (top <= bottom && bottom <= height){
				int ac = getAccum(i,top,j,bottom);
				if (ac == max){
					if (area(i,top,j,bottom) < min){
					    min = area(i,top,j,bottom);
					}
					top++;
				} else if (ac > max){
					top++;
				} else if (ac < max){
					bottom++;
				}
			}
			bottom = height;
			while (top != bottom){
				int ac = getAccum(i,top,j,bottom);
				if (ac == max){
					if (area(i,top,j,bottom) < min){
					    min = area(i,top,j,bottom);
					}
				}
				top++;
			}
		}
	}

	printf("%d %d\n", max, min);

	return 0;
}
