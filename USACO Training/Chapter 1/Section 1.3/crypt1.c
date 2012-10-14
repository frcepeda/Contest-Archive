/*
    ID: frceped1
    LANG: C
    TASK: crypt1
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("crypt1.in", "r", stdin); freopen("crypt1.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXNUM 10

int inSet[MAXNUM];
int toCheckNum;

int digitCount(int num){
	const int base = 10;
	if (!num)
		return 1;
	int count = 0;
	while (num){
		num /= base;
		count++;
	}
	return count;
}

int test(int num){
	const int base = 10;
	int digit;
	while (num){
		digit = num % base;
		num /= base;
		if (!inSet[digit]) return 0;
	}
	return 1;
}

int try(int up1, int up2, int up3, int down1, int down2){
	if (!(test(up1) && test(up2) && test(up3) && test(down1) && test(down2))) return 0;
	int up = up1 + up2 * 10 + up3 * 100;
	int down = down1 + down2 * 10;
	int partial1 = down1 * up;
	int partial2 = down2 * up;
	int answer = up * down;
	return test(partial1) && test(partial2) && test(answer) &&
		digitCount(partial1) <= 3 && digitCount(partial2) <= 3 && digitCount(answer) <= 4;
}

int main(void){
	openFiles();
	int i,j,k,l,m;
	int answer = 0;

	scanf("%d", &toCheckNum);

	for (i = 0; i < toCheckNum; i++){
		scanf("%d", &j);
		inSet[j] = 1;
	}

	for (i = 1; i <= 10; i++)
		for (j = 1; j <= 10; j++)
			for (k = 1; k <= 10; k++)
				for (l = 1; l <= 10; l++)
					for (m = 1; m <= 10; m++)
						if (try(i,j,k,l,m))
							answer++;

	printf("%d\n", answer);

	return 0;
}
