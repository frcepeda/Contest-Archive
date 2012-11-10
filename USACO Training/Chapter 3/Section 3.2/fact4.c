/*
    ID: frceped1
    LANG: C
    TASK: fact4
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("fact4.in", "r", stdin); freopen("fact4.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

int main(void){
	openFiles();
	
	int tmp = 1, i, N, two = 0, five = 0, num;

	scanf("%d", &N);

	for (i = 2; i <= N; i++){
		num = i;

		while (num % 2 == 0){
			two++;
			num /= 2;
		}

		while (num % 5 == 0){
			five++;
			num /= 5;
		}

		tmp = (tmp * num) % 10;
	}

	while (two-- > five)
		tmp = (tmp * 2) % 10;

	printf("%d\n", tmp);

	return 0;
}
