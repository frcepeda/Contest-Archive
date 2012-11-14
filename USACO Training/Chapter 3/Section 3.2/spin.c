/*
    ID: frceped1
    LANG: C
    TASK: spin
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("spin.in", "r", stdin); freopen("spin.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

int speeds[5];
bool wheels[5][360];
bool tmp[360];

bool try(int time){
	memset(tmp, false, 360);

	int i, j, k;

	for (i = 0; i < 5; i++){
		j = (speeds[i] * time) % 360;
		for (k = 0; k < 360; k++){
			if (i == 0)
				tmp[j] = wheels[i][k];
			else
				tmp[j] &= wheels[i][k];
			j = (j + 1) % 360;
		}
	}

	for (i = 0; i < 360; i++)
		if (tmp[i])
			return true;

	return false;
}

int main(void){
	openFiles();
	
	int i, j;

	for (i = 0; i < 5; i++){
		scanf("%d", &speeds[i]);
		scanf("%d", &j);
		while (j--){
			int a, b;
			scanf("%d %d", &a, &b);
			b++;
			while (b--){
				wheels[i][a++] = true;
				a %= 360;
			}
		}
	}

	for (i = 0; i < 360; i++){
		if (try(i)){
			printf("%d\n", i);
			return 0;
		}
	}

	printf("none\n");

	return 0;
}
