#include <stdio.h>
#include <string.h>

#define MAXN 55

int charCmp(const void *a, const void *b){
	if (*(char *)a > *(char *)b)
		return 1;
	if (*(char *)a < *(char *)b)
		return -1;
	return 0;
}

char letters[MAXN];
char curr[MAXN], last[MAXN];

int N, K;

int doPasswords(int n, int i){
	if (n == K){
		if (strcmp(curr, last) > 0){
			printf("%s\n", curr);
			strcpy(last, curr);
		}
		return;
	}

	for (; i < N && n + (N-i) >= K; i++){
		curr[n] = letters[i];
		if (strncmp(curr, last, n+1) == 0) continue;
		doPasswords(n+1, i+1);
	}
}

int main(void){
	scanf("%d %d", &N, &K);
	scanf("%s", letters);

	qsort(letters, N, sizeof(char), charCmp);

	doPasswords(0, 0);

	return 0;
}
