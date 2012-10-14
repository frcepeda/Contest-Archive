/*
    ID: frceped1
    LANG: C
    TASK: fracdec
 */

#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("fracdec.in", "r", stdin); freopen("fracdec.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 1000001
#define MAXCHARS 76

int numerators[MAXN];
int N, D;

char tmp[MAXN];
int len;

int main(void){
	openFiles();
	int i, start = 0, count;

	scanf("%d %d", &N, &D);

	sprintf(tmp, "%01d.", N/D);
	len = strlen(tmp);

	N %= D;

	if (!N){
		sprintf(tmp+len, "0\n");
		printf("%s", tmp);
		return 0;
	}

	while (N != 0){
		N *= 10;
		if (!numerators[N]){
			numerators[N] = len;
			tmp[len++] = '0'+ (N/D);
			N %= D;
		} else break;
	}
	start = numerators[N];

	for (i = 0, count = 0; tmp[i]; count++){
		if (start && count == start){
			putchar('(');
		} else {
			putchar(tmp[i++]);
		}
		if ((count+1) % MAXCHARS == 0){
			putchar('\n');
		}
	}
	if (start){
		putchar(')');
		putchar('\n');
	} else if ((count + 1) % MAXCHARS)
		putchar('\n');

	return 0;
}
