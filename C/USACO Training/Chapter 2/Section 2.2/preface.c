/*
    ID: frceped1
    LANG: C
    TASK: preface
 */

#include <stdio.h>
#include <strings.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("preface.in", "r", stdin); freopen("preface.out", "w", stdout)
#else
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

typedef struct {
	int value;
	char *numeral;
} romanNumeral;

#define NUMS 13
romanNumeral numbers[NUMS] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

char tmpstring[100];
int tmpstringlen;

#define MAXLETTERS 30
int count[MAXLETTERS];

#define DIGITS 7
char digit[DIGITS] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void toRoman(int n){
	int i;
	tmpstringlen = 0;
	for (i = 0; i < NUMS && n; i++){
		while (numbers[i].value <= n){
			n -= numbers[i].value;
			strcpy(tmpstring+tmpstringlen, numbers[i].numeral);
			tmpstringlen += strlen(numbers[i].numeral);
		}
	}
}

void addDigits(void){
	int i;
	for (i = 0; i < tmpstringlen; i++){
		count[tmpstring[i]-'A']++;
	}
}

int main(void){
	openFiles();

	int N, i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		toRoman(i);
		addDigits();
	}

	for (i = 0; i < DIGITS; i++){
		if (count[digit[i]-'A']){
			printf("%c %d\n", digit[i], count[digit[i]-'A']);
		}
	}

	return 0;
}
