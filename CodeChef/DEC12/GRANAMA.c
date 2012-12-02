#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>

int T;
char strings[2][1010];

int charCmp(const void *a, const void *b){
	return *((char *)a) - *((char *)b);
}

bool chef(void){
	int i = 0, j = 0;

	while (strings[0][i] && strings[1][j]){
		if (strings[0][i] != strings[1][j])
			return false;

		while (strings[0][i] == strings[0][i+1]) i++;
		i++;

		while (strings[1][j] == strings[1][j+1]) j++;
		j++;
	}

	return strings[0][i] == '\0' && strings[1][j] == '\0';
}

bool correct(void){
	return strcmp(strings[0], strings[1]) == 0;
}

int main(void){
	scanf("%d", &T);

	while (T--){
		scanf("%s", strings[0]);
		scanf("%s", strings[1]);
		
		qsort(strings[0], strlen(strings[0]), sizeof(char), charCmp);
		qsort(strings[1], strlen(strings[1]), sizeof(char), charCmp);

		printf("%s\n", chef() == correct() ? "YES" : "NO");
	}

	return 0;
}
