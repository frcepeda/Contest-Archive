/*
    ID: frceped1
    LANG: C
    TASK: namenum
 */

#include <stdio.h>
#include <string.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("namenum.in", "r"); out = fopen("namenum.out", "w")
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

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
			print("%s\n", string);
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
		printf("%s\n", string);
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
	read("%lld", &num);
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
	if (!printedSomething) print("NONE\n");
	return 0;
}
