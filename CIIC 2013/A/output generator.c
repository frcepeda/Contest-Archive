#include <stdio.h>
#include <strings.h>

#define MAXN 5000000
#define PRINTLENGTH 1

int C = 1, N = 1, L = 1;
char str[MAXN];
char tmp[MAXN];

void stuff(void){
	int i, j;

	while (1){
#if PRINTLENGTH
		printf("%d\n", N);
#else
		for (i = 0; i < N; i++)
			printf("%c\n", str[i] + 'A');
#endif
		j = 0;
		for (i = 0; i < N; i++){
			if (str[i] == 0){
				tmp[j++] = 0;
				tmp[j++] = 1;
			} else if (str[i] == 1){
				tmp[j++] = 0;
				tmp[j++] = 2;
			} else {
				tmp[j++] = 0;
			}

			if (j >= MAXN)
				return;
		}

		N = j;
		for (i = 0; i < N; i++)
			str[i] = tmp[i];
	}
}

int main(void){
	stuff();
	return 0;
}
