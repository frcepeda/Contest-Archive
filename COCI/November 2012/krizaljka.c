#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int _strcmp(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

char w[6][4];
char *words[6];
char crossword[3][4];

bool try(int a, int b, int c){
	bool inUse[6] = {false};
	char *tmp[3];
	int i, j, k;

	tmp[0] = words[a]; tmp[1] = words[b]; tmp[2] = words[c];
	inUse[a] = inUse[b] = inUse[c] = true;

	for (j = 0; j < 3; j++){
		bool found = false;
		for (i = 0; i < 6; i++){
			if (inUse[i]) continue;

			bool works = true;
			for (k = 0; k < 3; k++){
				if (tmp[k][j] != words[i][k]){
					works = false;
					break;
				}
			}

			if (works){
				inUse[i] = true;
				found = true;
				break;
			}
		}

		if (!found)
			return false;
	}

	return true;
}

int main(void){
	int i, j, k;

	for (i = 0; i < 6; i++){
		scanf("%s", w[i]);
		words[i] = w[i];
	}

	qsort(words, 6, sizeof(words[0]), _strcmp);

	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			for (k = 0; k < 6; k++){
				if (i != j && i != k && j != k && try(i,j,k)){
					printf("%s\n", words[i]);
					printf("%s\n", words[j]);
					printf("%s\n", words[k]);
					return 0;
				}
			}
		}
	}

	printf("0\n");

	return 0;
}

