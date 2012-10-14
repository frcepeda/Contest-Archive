/*
    ID: frceped1
    LANG: C
    TASK: namenum
 */

#include <stdio.h>
#include <string.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("namenum.in", "r", stdin); freopen("namenum.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXLENGTH 15

void removeNewline(char *str){
	int i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	str[i] = '\0';
}

int buttons[8][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'},
	{'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'},
	{'W', 'X', 'Y'}};
int sequence[MAXLENGTH];
int length;
char string[MAXLENGTH];
char acceptable[5000][MAXLENGTH];
int nameCount;

void openDictionary(void){
	FILE *dict = fopen("dict.txt", "r");
	int i = 0;
	while (fgets(acceptable[i], MAXLENGTH, dict)){
		removeNewline(acceptable[i++]);
		nameCount++;
	}
	fclose(dict);
}

int printedSomething;

void checkString(void){
	int lo = 0, hi = nameCount-1;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		int ret = strcmp(string, acceptable[mid]);
		if (ret == 0){
			printf("%s\n", string);
			printedSomething = 1;
			return;
		} else if (ret < 0)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
}

void permute(int index){
	if (index == length){
		checkString();
		return;
	} else {
		int i = 0;
		for (i = 0; i < 3; i++){
			string[index] = buttons[sequence[index]-2][i];
			permute(index+1);
		}
	}
}

int main(void){
	openFiles();
	long long int i, num;
	scanf("%lld", &num);
	for (i = 0; num; i++, length++){
		sequence[i] = num % 10;
		num /= 10;
	}
	for (i = 0; i < length / 2; i++) {
		int temp = sequence[i];
		sequence[i] = sequence[length-1-i];
		sequence[length-1-i] = temp;
	}
	openDictionary();
	permute(0);
	if (!printedSomething)
		printf("NONE\n");
	return 0;
}
