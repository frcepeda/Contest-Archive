#include <stdio.h>

typedef struct {
	int r, g, b;
} color;

color c[10000];

int abs(int a){
	if (a < 0) return -a;
	return a;
}

int max(int a, int b, int c){
	if (b > c && b > a) return b;
	if (c > a && c > b) return c;
	return a;
}

int d(color a, color b){
	return max(abs(a.r - b.r), abs(a.g - b.g), abs(a.b - b.b));
}

int main(void){
	int count, needs;
	scanf("%d %d", &count, &needs);
	if (count == needs){
		int i;
		for (i = 0; i < count; i++){
			scanf("%d %d %d", &c[i].r, &c[i].g, &c[i].b);
		}
		
		int max = 0;
		int j;

		for (i = 0; i < count; i++){
			for (j = 0; j < count; j++){
				int diff = d(c[i], c[j]);
				if (diff > max) max = diff;
			}
		}

		printf("%d\n", max);
		for (i = 0; i < count; i++){
			printf("%d %d %d\n", c[i].r, c[i].g, c[i].b);
		}
	}
	return 0;
}

