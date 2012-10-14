/*
    ID: frceped1
    LANG: C
    TASK: calfflac
 */

#include <stdio.h>
#include <ctype.h>
#include <strings.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("calfflac.in", "r", stdin); freopen("calfflac.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXLENGTH 20000

char originalString[MAXLENGTH];
char noPunctuationString[MAXLENGTH];
int originalLength, noPunctuationLength;

int main(void){
	openFiles();

	char c;

	while ((c = getchar()) != EOF){
		originalString[originalLength++] = c;
		if (isalpha(c))
			noPunctuationString[noPunctuationLength++] = tolower(c);
	}

	int i;
	int maxLen, maxi;
	int start, end, len;
	int center, centered;
	for (i = 0; i < noPunctuationLength * 2; i++){
		if (i % 2 == 0){
			start = end = i / 2;
			start--;
			end++;
			len = 1;
		} else {
			start = (i - 1) / 2;
			end = (i + 1) / 2;
			len = 0;
		}
		center = start;
		while (start >= 0 &&
				end < noPunctuationLength &&
				noPunctuationString[start] == noPunctuationString[end]){
			start--;
			end++;
			len += 2;
		}
		if (len > maxLen){
			maxLen = len;
			maxi = i;
			centered = (i%2==0) ? 1 : 0;
		}
	}


	printf("%d\n", maxLen);

	if (i % 2 == 0){
		start = end = i / 2;
		start--;
		end++;
		len = 1;
	} else {
		start = (i - 1) / 2;
		end = (i + 1) / 2;
		len = 0;
	}

	i = -1;
	maxi /= 2;
	maxi += centered ? 1 : 2;
	maxi -= maxLen / 2;
	while (maxi){
		i++;
		if (isalpha(originalString[i])) maxi--;
	}

	while (maxLen){
		putchar(originalString[i]);
		if (isalpha(originalString[i++])) maxLen--;
	}

	putchar('\n');

	return 0;
}
