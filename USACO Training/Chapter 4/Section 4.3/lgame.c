/*
    ID: frceped1
    LANG: C
    TASK: lgame
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("lgame.in", "r", stdin); freopen("lgame.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXWORDS 40010
#define MAXLEN 10

int values[30] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int N, wCount;
char words[MAXWORDS][MAXLEN];
char str[MAXLEN];

int charCmp(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

int getScore(char *str){
	int s = 0;
	for (; *str; str++)
		s += values[*str - 'a'];
	return s;
}

#define findWord(str) (bsearch(str,words,wCount,sizeof(words[0]),(int (*)(const void *, const void *))strcmp) != NULL)

bool next_permutation(void){
	int i, j;

	for (i = N-2; i >= 0; i--)
		if (str[i] < str[i+1])
			for (j = N-1; j >= 0; j--)
				if (str[i] < str[j]){
					char c = str[i];
					str[i] = str[j];
					str[j] = c;

					for (i++, j = N-1; i < j; i++, j--){
						c = str[i];
						str[i] = str[j];
						str[j] = c;
					}

					return true;
				}

	return false;
}

int bestScore, bestCount;
char bestWords[MAXWORDS][MAXLEN];

int main(void){
	int i;

	openFiles();
	
	scanf("%s", str);
	N = strlen(str);
	str[N++] = '\0';
	str[N++] = '\0';

	FILE *dict = fopen("lgame.dict", "r");

	for (; fscanf(dict, "%s", words[wCount]) != EOF; wCount++);
	wCount--;

	qsort(str, N, sizeof(char), charCmp);

	while (next_permutation()){
		int sep;

		for (sep = 0; str[sep] != '\0'; sep++);

		if (sep == 0) continue;

		if (findWord(str)){
			int score = getScore(str);

			if (strcmp(str, bestWords[bestCount-1]) != 0){
				if (score > bestScore){
					bestScore = score;
					bestCount = 0;
				}

				if (score == bestScore){
					strcpy(bestWords[bestCount],str);
					bestCount++;
				}
			}

			if (strcmp(str, str + sep + 1) <= 0 && findWord(str + sep + 1)){
				score += getScore(str + sep + 1);

				if (score > bestScore){
					bestScore = score;
					bestCount = 0;
				}

				if (score == bestScore){
					str[sep] = ' ';

					if (strcmp(str, bestWords[bestCount-1]) != 0){
						strcpy(bestWords[bestCount],str);
						bestCount++;
					}

					str[sep] = '\0';
				}
			}
		}
	}

	printf("%d\n", bestScore);

	for (i = 0; i < bestCount; i++)
		printf("%s\n", bestWords[i]);

	return 0;
}
